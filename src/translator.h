#pragma once

#include <map>
#include <string>
#include <vector>

#include "hexagram.h"
#include "util.h"

using std::map;
using std::string;
using std::vector;

class Translator
{
private:
    const size_t        MAX_WIDTH = 80;
    
    string              b64_char_ordering = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    map<char, Hexagram> keymap;
    
    string build_hexagram_output(const vector<Hexagram>& hexagrams, const string& delimiter);
    void build_keymap();
    
    
public:
    Translator();
    string encode(const string& input, bool shuffle = false);
    string decode(const string& input, const string& key = "");
};
