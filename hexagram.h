#pragma once

#include <string>

#include "trigram.h"

using std::string;

class Hexagram
{
private:
    Trigram _upper;
    Trigram _lower;
    unsigned _value;
    
public:
    Hexagram(Trigram upper, Trigram lower, unsigned value) :
        _upper(upper),
        _lower(lower),
        _value(value) {}
    Trigram upper();
    Trigram lower();
    unsigned value() const;
    bool operator <(const Hexagram& hexagram) const;
    string str();
};

const int NUM_TRIGRAMS = 8;
const int NUM_TRIGRAM_LINES = 3;
const int NUM_HEXAGRAM_LINES = NUM_TRIGRAM_LINES * 2;
const int HEXAGRAM_WIDTH = 10;

// Hexagram lookup table by upper/lower trigram
const Hexagram HEXAGRAMS[NUM_TRIGRAMS][NUM_TRIGRAMS] = {
    [ HEAVEN ] = {
        Hexagram(HEAVEN, HEAVEN, 1),
        Hexagram(HEAVEN, LAKE, 43),
        Hexagram(HEAVEN, FIRE, 14),
        Hexagram(HEAVEN, THUNDER, 34),
        Hexagram(HEAVEN, WIND, 9),
        Hexagram(HEAVEN, WATER, 5),
        Hexagram(HEAVEN, MOUNTAIN, 26),
        Hexagram(HEAVEN, EARTH, 11),
    },
    [ LAKE ] = {
        Hexagram(LAKE, HEAVEN, 10),
        Hexagram(LAKE, LAKE, 58),
        Hexagram(LAKE, FIRE, 38),
        Hexagram(LAKE, THUNDER, 54),
        Hexagram(LAKE, WIND, 61),
        Hexagram(LAKE, WATER, 60),
        Hexagram(LAKE, MOUNTAIN, 41),
        Hexagram(LAKE, EARTH, 19),
    },
    [ FIRE ] = {
        Hexagram(FIRE, HEAVEN, 13),
        Hexagram(FIRE, LAKE, 49),
        Hexagram(FIRE, FIRE, 30),
        Hexagram(FIRE, THUNDER, 55),
        Hexagram(FIRE, WIND, 37),
        Hexagram(FIRE, WATER, 63),
        Hexagram(FIRE, MOUNTAIN, 22),
        Hexagram(FIRE, EARTH, 36),
    },
    [ THUNDER ] = {
        Hexagram(THUNDER, HEAVEN, 25),
        Hexagram(THUNDER, LAKE, 17),
        Hexagram(THUNDER, FIRE, 21),
        Hexagram(THUNDER, THUNDER, 51),
        Hexagram(THUNDER, WIND, 42),
        Hexagram(THUNDER, WATER, 3),
        Hexagram(THUNDER, MOUNTAIN, 27),
        Hexagram(THUNDER, EARTH, 24),
    },
    [ WIND ] = {
        Hexagram(WIND, HEAVEN, 44),
        Hexagram(WIND, LAKE, 28),
        Hexagram(WIND, FIRE, 50),
        Hexagram(WIND, THUNDER, 32),
        Hexagram(WIND, WIND, 57),
        Hexagram(WIND, WATER, 48),
        Hexagram(WIND, MOUNTAIN, 18),
        Hexagram(WIND, EARTH, 46),
    },
    [ WATER ] = {
        Hexagram(WATER, HEAVEN, 6),
        Hexagram(WATER, LAKE, 47),
        Hexagram(WATER, FIRE, 64),
        Hexagram(WATER, THUNDER, 40),
        Hexagram(WATER, WIND, 59),
        Hexagram(WATER, WATER, 29),
        Hexagram(WATER, MOUNTAIN, 4),
        Hexagram(WATER, EARTH, 7),
    },
    [ MOUNTAIN ] = {
        Hexagram(MOUNTAIN, HEAVEN, 33),
        Hexagram(MOUNTAIN, LAKE, 31),
        Hexagram(MOUNTAIN, FIRE, 56),
        Hexagram(MOUNTAIN, THUNDER, 62),
        Hexagram(MOUNTAIN, WIND, 53),
        Hexagram(MOUNTAIN, WATER, 39),
        Hexagram(MOUNTAIN, MOUNTAIN, 52),
        Hexagram(MOUNTAIN, EARTH, 15),
    },
    [ EARTH ] = {
        Hexagram(EARTH, HEAVEN, 12),
        Hexagram(EARTH, LAKE, 45),
        Hexagram(EARTH, FIRE, 35),
        Hexagram(EARTH, THUNDER, 16),
        Hexagram(EARTH, WIND, 20),
        Hexagram(EARTH, WATER, 8),
        Hexagram(EARTH, MOUNTAIN, 23),
        Hexagram(EARTH, EARTH, 2),
    }
};
