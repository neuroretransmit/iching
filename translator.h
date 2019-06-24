#pragma once

#include <string>

using std::string;

namespace Translator
{
    string encode(const string& input, bool shuffle = false);
    string decode(const string& input, string key = "");
}
