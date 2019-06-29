#include "parser.h"

vector<string> Parser::lines_to_hexagrams(const vector<string>& lines)
{
    vector<string> continuous_hexagrams(NUM_HEXAGRAM_LINES);
    vector<string> hexagrams;
    int i = 0;
    
    for (const string& line : lines) {
        i = i % NUM_HEXAGRAM_LINES == 0 ? 0 : i;
        continuous_hexagrams[i] += line;
        i += 1;
    }
    
    for (size_t offset = 0; offset < continuous_hexagrams[0].length(); offset += HEXAGRAM_WIDTH) {
        string hexagram = "";
        for (const string& line : continuous_hexagrams) {
            for (size_t j = offset; j < offset + HEXAGRAM_WIDTH; j++) {
                hexagram += line[j];
            }
            hexagram += "\n";
        }
        
        hexagrams.push_back(hexagram);
    }
    
    return hexagrams;
}

