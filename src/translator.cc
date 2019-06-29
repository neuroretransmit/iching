#include "translator.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>

#include "hexagram.h"
#include "lexer.h"
#include "parser.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::pair;

Translator::Translator()
{
}

void Translator::build_keymap()
{
    int i = 0;
    
    for (const char& c : this->b64_char_ordering) {
        this->keymap.insert(pair<char, Hexagram>(c, HEXAGRAMS[i]));
        i += 1;
    }
}

string Translator::build_hexagram_output(const vector<Hexagram>& hexagrams, const string& delimiter)
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
        std::srand(0);
        std::random_shuffle(
            b64_char_ordering.begin(), 
            b64_char_ordering.end(), 
            util::rand::random_generator);
        cout << "KEY: " << b64_char_ordering << endl;
        build_keymap();
    } else {
        build_keymap();
    }
    
    string b64_encoded = util::b64::b64_encode(input);
    vector<Hexagram> hexagrams;
    
    for (const char& c : b64_encoded) {
        hexagrams.push_back(keymap.at(c));
    }
    
    return build_hexagram_output(hexagrams, "\n");
}

string Translator::decode(const string& input, const string& key)
{
    if (key != "") {
        b64_char_ordering = key;
        build_keymap();
    } else {
        build_keymap();
    }
    
    vector<string> hexagrams = Parser::lines_to_hexagrams(Lexer::strip_lines(input));   
    string b64 = "";
    
    for (const string& hexagram: hexagrams) {
        map<char, Hexagram>::iterator it;
        for (it = keymap.begin(); it != keymap.end(); it++) {
            string hex_str = it->second.str();
            
            if (hex_str != "" && hex_str == hexagram) {
                b64 += it->first;
            }
        }
    }
    
    return util::b64::b64_decode(b64);
}
