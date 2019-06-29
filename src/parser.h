#pragma once

#include <vector>

#include "hexagram.h"

using std::vector;

namespace Parser
{
    vector<string> lines_to_hexagrams(const vector<string>& lines);
}
