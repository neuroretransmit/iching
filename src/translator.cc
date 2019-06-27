#include "translator.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>

#include "hexagram.h"
#include "lexer.h"
#include "parser.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::pair;

static size_t MAX_WIDTH = 80;
static map<char, Hexagram> KEYMAP;
string BASE64_CHARACTER_ORDERING = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static void build_keymap()
{
    int i = 0;
    for (const char& c : BASE64_CHARACTER_ORDERING) {
        KEYMAP.insert(pair<char, Hexagram>(c, HEXAGRAMS[i]));
        i += 1;
    }
}

string build_hexagram_output(const vector<Hexagram>& hexagrams, const string& delimiter)
{
    string repr = "";    
    vector<string> continuous_hexagrams(NUM_HEXAGRAM_LINES);
    size_t offset = 0;
    size_t line_pos = 0;
    
    for (const Hexagram& hexagram: hexagrams) {
        if (line_pos >= MAX_WIDTH) {
            for (int i = 0; i < NUM_HEXAGRAM_LINES; i++) {
                continuous_hexagrams.push_back("");
            }
            
            offset += NUM_HEXAGRAM_LINES;
            line_pos = 0;
        }
        
        string h = Hexagram(hexagram).str();
        size_t pos = 0;
        string token;
        
        for (size_t i = 0; (pos = h.find(delimiter)) != string::npos && i < offset + NUM_HEXAGRAM_LINES; i++) {
            token = h.substr(0, pos);
            continuous_hexagrams[offset + i] += token;
            h.erase(0, pos + delimiter.length());
        }
        
        line_pos += HEXAGRAM_WIDTH;
    }
    
    for (const string& line: continuous_hexagrams) {
        repr += line + "\n";
    }
    
    return repr;
}

string Translator::encode(const string& input, bool shuffle)
{
    if (shuffle) {
        std::srand(unsigned(std::time(0)));
        std::random_shuffle(
            BASE64_CHARACTER_ORDERING.begin(), 
            BASE64_CHARACTER_ORDERING.end(), 
            Util::Random::random_generator);
        cout << "KEY: " << BASE64_CHARACTER_ORDERING << endl;
        build_keymap();
    } else {
        build_keymap();
    }
    
    string b64_encoded = Util::Base64::b64_encode(input);
    vector<Hexagram> hexagrams;
    
    for (const char& c : b64_encoded) {
        hexagrams.push_back(KEYMAP.at(c));
    }
    
    return build_hexagram_output(hexagrams, "\n");
}

string Translator::decode(const string& input, const string& key)
{
    if (key != "") {
        BASE64_CHARACTER_ORDERING = key;
        build_keymap();
    } else {
        build_keymap();
    }
    
    vector<string> hexagrams = Parser::lines_to_hexagrams(Lexer::strip_lines(input));   
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
    
    return Util::Base64::b64_decode(b64);
}
