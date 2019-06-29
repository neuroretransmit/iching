#pragma once

#include <vector>
#include <sstream>
#include <string>

using std::vector;
using std::string;

namespace Lexer
{
    vector<string> strip_lines(const string& encoded_or_fname);
}
