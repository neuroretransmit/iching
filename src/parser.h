#pragma once

#include <vector>

#include "hexagram.h"

using std::vector;

namespace Parser
{
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
}
