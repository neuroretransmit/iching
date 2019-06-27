#pragma once

#include <string>

#include "util.h"

using std::string;

namespace Translator
{
    string encode(const string& input, bool shuffle = false);
    string decode(const string& input, const string& key = "");
}
