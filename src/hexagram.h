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
const Hexagram HEXAGRAMS[NUM_TRIGRAMS * NUM_TRIGRAMS] = {
    Hexagram(HEAVEN, HEAVEN, 1),
    Hexagram(EARTH, EARTH, 2),
    Hexagram(THUNDER, WATER, 3),
    Hexagram(WATER, MOUNTAIN, 4),
    Hexagram(HEAVEN, WATER, 5),
    Hexagram(WATER, HEAVEN, 6),
    Hexagram(WATER, EARTH, 7),
    Hexagram(EARTH, WATER, 8),
    Hexagram(HEAVEN, WIND, 9),
    Hexagram(LAKE, HEAVEN, 10),
    Hexagram(HEAVEN, EARTH, 11),
    Hexagram(EARTH, HEAVEN, 12),
    Hexagram(FIRE, HEAVEN, 13),
    Hexagram(HEAVEN, FIRE, 14),
    Hexagram(MOUNTAIN, EARTH, 15),
    Hexagram(EARTH, THUNDER, 16),
    Hexagram(THUNDER, LAKE, 17),
    Hexagram(WIND, MOUNTAIN, 18),
    Hexagram(LAKE, EARTH, 19),
    Hexagram(EARTH, WIND, 20),
    Hexagram(THUNDER, FIRE, 21),
    Hexagram(FIRE, MOUNTAIN, 22),
    Hexagram(EARTH, MOUNTAIN, 23),
    Hexagram(THUNDER, EARTH, 24),
    Hexagram(THUNDER, HEAVEN, 25),
    Hexagram(HEAVEN, MOUNTAIN, 26),
    Hexagram(THUNDER, MOUNTAIN, 27),
    Hexagram(WIND, LAKE, 28),
    Hexagram(WATER, WATER, 29),
    Hexagram(FIRE, FIRE, 30),
    Hexagram(MOUNTAIN, LAKE, 31),
    Hexagram(WIND, THUNDER, 32),
    Hexagram(MOUNTAIN, HEAVEN, 33),
    Hexagram(HEAVEN, THUNDER, 34),
    Hexagram(EARTH, FIRE, 35),
    Hexagram(FIRE, EARTH, 36),
    Hexagram(FIRE, WIND, 37),
    Hexagram(LAKE, FIRE, 38),
    Hexagram(MOUNTAIN, WATER, 39),
    Hexagram(WATER, THUNDER, 40),
    Hexagram(LAKE, MOUNTAIN, 41),
    Hexagram(THUNDER, WIND, 42),
    Hexagram(HEAVEN, LAKE, 43),
    Hexagram(WIND, HEAVEN, 44),
    Hexagram(EARTH, LAKE, 45),
    Hexagram(WIND, EARTH, 46),
    Hexagram(WATER, LAKE, 47),
    Hexagram(WIND, WATER, 48),
    Hexagram(FIRE, LAKE, 49),
    Hexagram(WIND, FIRE, 50),
    Hexagram(THUNDER, THUNDER, 51),
    Hexagram(MOUNTAIN, MOUNTAIN, 52),
    Hexagram(MOUNTAIN, WIND, 53),
    Hexagram(LAKE, THUNDER, 54),
    Hexagram(FIRE, THUNDER, 55),
    Hexagram(MOUNTAIN, FIRE, 56),
    Hexagram(WIND, WIND, 57),
    Hexagram(LAKE, LAKE, 58),
    Hexagram(WATER, WIND, 59),
    Hexagram(LAKE, WATER, 60),
    Hexagram(LAKE, WIND, 61),
    Hexagram(MOUNTAIN, THUNDER, 62),
    Hexagram(FIRE, WATER, 63),
    Hexagram(WATER, FIRE, 64),
};
