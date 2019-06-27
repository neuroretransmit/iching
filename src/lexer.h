#pragma once

#include <vector>
#include <sstream>
#include <string>

using std::vector;
using std::string;

namespace Lexer
{
    vector<string> strip_lines(const string& encoded_or_fname)
    {
        vector<string> lines;
        std::stringstream ss(encoded_or_fname);
        string line = "";
        
        while (std::getline(ss, line, '\n'))
            lines.push_back(line);
        
        return lines;
    }
}
