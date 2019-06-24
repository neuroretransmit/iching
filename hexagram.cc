#include "hexagram.h"

#include <string>
#include <vector>

#include "trigram.h"

using std::string;
using std::vector;

const char* SOLID = "==========";
const char* BROKEN = "====  ====";

const char* TRIGRAMS[NUM_TRIGRAMS][NUM_TRIGRAM_LINES] = 
{
    [ HEAVEN ]    = { SOLID,  SOLID,  SOLID  },
    [ LAKE ]      = { BROKEN, SOLID,  SOLID  },
    [ FIRE ]      = { SOLID,  BROKEN, SOLID  },
    [ THUNDER ]   = { BROKEN, BROKEN, SOLID  },
    [ WIND ]      = { SOLID,  SOLID,  BROKEN },
    [ WATER ]     = { BROKEN, SOLID,  BROKEN },
    [ MOUNTAIN ]  = { SOLID,  BROKEN, BROKEN },
    [ EARTH ]     = { BROKEN, BROKEN, BROKEN }
};

Trigram Hexagram::lower()
{
    return this->_lower;
}

Trigram Hexagram::upper()
{
    return this->_upper;
}

unsigned int Hexagram::value() const
{
    return this->_value;
}

bool Hexagram::operator<(const Hexagram& hexagram) const
{
    return this->_value < hexagram.value();
}

string Hexagram::str()
{
    string s;
    for (const char* line: TRIGRAMS[this->upper()]) {
        s += line;
        s += "\n";
    }
    for (const char* line: TRIGRAMS[this->lower()]) {
        s += line;
        s += "\n";
    }
    return s;
}
