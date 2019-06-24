#pragma once

#include <string>

using std::string;

namespace Translator
{
    string encode(const string& msg_or_fname, bool shuffle = false);
    string decode(const string& encoded_or_fname, string key = "");
}
