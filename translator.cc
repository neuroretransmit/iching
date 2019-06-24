#include "translator.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/insert_linebreaks.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/remove_whitespace.hpp>

#include "hexagram.h"

using namespace boost::archive::iterators;

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::pair;
using std::vector;

static size_t MAX_WIDTH = 80;
static string B64_CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static map<char, Hexagram> KEYMAP;

static void build_keymap(const vector<Hexagram> hexagrams)
{
    int i = 0;
    for (const char& c : B64_CHARACTERS) {
        KEYMAP.insert(pair<char, Hexagram>(c, hexagrams[i]));
        i += 1;
    }
}

static string b64_encode(string msg)
{
    std::stringstream os;
    typedef base64_from_binary<transform_width<const char*, 6, 8>> base64_text;

    std::copy(
        base64_text(msg.c_str()),
        base64_text(msg.c_str() + msg.size()),
        std::ostream_iterator<char>(os));
    return os.str();
}

static string b64_decode(const string& msg)
{
    typedef transform_width<binary_from_base64<remove_whitespace<std::string::const_iterator>>, 8, 6> ItBinaryT;
    string output = "";
    string padded = msg;
    
    try {
        size_t num_pad_chars((4 - msg.size() % 4) % 4);
        padded.append(num_pad_chars, '=');
        size_t pad_chars(std::count(padded.begin(), padded.end(), '='));
        std::replace(padded.begin(), padded.end(), '=', 'A');
        std::string output(ItBinaryT(padded.begin()), ItBinaryT(padded.end()));
        output.erase(output.end() - pad_chars, output.end());
        return output;
    } catch (std::exception const& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }
    
    return output;
}

static vector<Hexagram> translate_hexagrams_2d_to_1d(bool sort = false)
{
    vector<Hexagram> sorted_hexagrams;
    
    for (int i = 0; i < NUM_TRIGRAMS; i++)
        for (int j = 0; j < NUM_TRIGRAMS; j++)
            sorted_hexagrams.push_back(HEXAGRAMS[i][j]);
    
    if (sort)
        std::sort(sorted_hexagrams.begin(), sorted_hexagrams.end());
    
    return sorted_hexagrams;
}

string build_hexagram_output(vector<Hexagram>& hexagrams, const string& delimiter)
{
    string repr = "";    
    vector<string> continuous_hexagrams(NUM_HEXAGRAM_LINES);
    size_t offset = 0;
    size_t line_pos = 0;
    
    for (Hexagram& hexagram: hexagrams) {
        if (line_pos >= MAX_WIDTH) {
            for (int i = 0; i < NUM_HEXAGRAM_LINES; i++)
                continuous_hexagrams.push_back("");
            offset += NUM_HEXAGRAM_LINES;
            line_pos = 0;
        }
        
        string h = hexagram.str();
        size_t pos = 0;
        string token;
        
        for (size_t i = 0; (pos = h.find(delimiter)) != string::npos && i < offset + NUM_HEXAGRAM_LINES; i++) {
            token = h.substr(0, pos);
            continuous_hexagrams[offset + i] += token;
            h.erase(0, pos + delimiter.length());
        }
        
        line_pos += HEXAGRAM_WIDTH;
    }
    
    for (const string& line: continuous_hexagrams)
        repr += line + "\n";
    
    return repr;
}

static int random_generator(int i)
{
    return std::rand() % i;
}

string Translator::encode(const string& input, bool shuffle)
{
    if (shuffle) {
        std::srand(unsigned(std::time(0)));
        std::random_shuffle(B64_CHARACTERS.begin(), B64_CHARACTERS.end(), random_generator);
        cout << "KEY: " << B64_CHARACTERS << endl;
        build_keymap(translate_hexagrams_2d_to_1d());
    } else {
        build_keymap(translate_hexagrams_2d_to_1d(true));
    }
    
    string b64_encoded = b64_encode(input);
    vector<Hexagram> hexagrams;
    
    for (const char& c : b64_encoded) {
        hexagrams.push_back(KEYMAP.at(c));
    }
    
    return build_hexagram_output(hexagrams, "\n");
}

static vector<string> strip_lines(const string& encoded_or_fname)
{
    vector<string> lines;
    std::stringstream ss(encoded_or_fname);
    string line = "";
    
    while (std::getline(ss, line, '\n'))
        lines.push_back(line);
    
    return lines;
}

static vector<string> lines_to_hexagrams(const vector<string>& lines)
{
    vector<string> continuous_hexagrams(NUM_HEXAGRAM_LINES);
    int i = 0;
    for (const string& line : lines) {
        i = i % NUM_HEXAGRAM_LINES == 0 ? 0 : i;
        continuous_hexagrams[i] += line;
        i += 1;
    }
    
    vector<string> hexagrams;
    for (size_t offset = 0; offset < continuous_hexagrams[0].length(); offset += HEXAGRAM_WIDTH) {
        string hexagram = "";
        for (const string& line : continuous_hexagrams) {
            for (size_t j = offset; j < offset + HEXAGRAM_WIDTH; j++)
                hexagram += line[j];
            hexagram += "\n";
        }
        hexagrams.push_back(hexagram);
    }
    
    return hexagrams;
}

string Translator::decode(const string& input, string key)
{
    if (key != "") {
        B64_CHARACTERS = key;
        build_keymap(translate_hexagrams_2d_to_1d());
    } else {
        build_keymap(translate_hexagrams_2d_to_1d(true));
    }
    vector<string> hexagrams = lines_to_hexagrams(strip_lines(input));   
    string b64 = "";
    
    for (const string& hexagram: hexagrams) {
        map<char, Hexagram>::iterator it;
        for (it = KEYMAP.begin(); it != KEYMAP.end(); it++) {
            string hex_str = it->second.str();
            if (hex_str != "" && hex_str == hexagram) {
                b64 += it->first;
            }
        }
    }
    
    return b64_decode(b64);
}
