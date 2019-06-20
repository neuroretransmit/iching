from trigram import Trigram

class Hexagram:
    def __init__(self, upper, lower, value):
        self.upper = upper
        self.lower = lower
        self.value = value

    def __str__(self):
        return str(self.upper) + str(self.lower)

HEXAGRAMS = [
    [
        Hexagram(Trigram.HEAVEN, Trigram.HEAVEN, 1),
        Hexagram(Trigram.HEAVEN, Trigram.LAKE, 43),
        Hexagram(Trigram.HEAVEN, Trigram.FIRE, 14),
        Hexagram(Trigram.HEAVEN, Trigram.THUNDER, 34),
        Hexagram(Trigram.HEAVEN, Trigram.WIND, 9),
        Hexagram(Trigram.HEAVEN, Trigram.WATER, 5),
        Hexagram(Trigram.HEAVEN, Trigram.MOUNTAIN, 26),
        Hexagram(Trigram.HEAVEN, Trigram.EARTH, 11)
    ],
    [
        Hexagram(Trigram.LAKE, Trigram.HEAVEN, 10),
        Hexagram(Trigram.LAKE, Trigram.LAKE, 58),
        Hexagram(Trigram.LAKE, Trigram.FIRE, 38),
        Hexagram(Trigram.LAKE, Trigram.THUNDER, 54),
        Hexagram(Trigram.LAKE, Trigram.WIND, 61),
        Hexagram(Trigram.LAKE, Trigram.WATER, 60),
        Hexagram(Trigram.LAKE, Trigram.MOUNTAIN, 41),
        Hexagram(Trigram.LAKE, Trigram.EARTH, 19)
    ],
    [
        Hexagram(Trigram.FIRE, Trigram.HEAVEN, 13),
        Hexagram(Trigram.FIRE, Trigram.LAKE, 49),
        Hexagram(Trigram.FIRE, Trigram.FIRE, 30),
        Hexagram(Trigram.FIRE, Trigram.THUNDER, 55),
        Hexagram(Trigram.FIRE, Trigram.WIND, 37),
        Hexagram(Trigram.FIRE, Trigram.WATER, 63),
        Hexagram(Trigram.FIRE, Trigram.MOUNTAIN, 22),
        Hexagram(Trigram.FIRE, Trigram.EARTH, 36)
    ],
    [
        Hexagram(Trigram.THUNDER, Trigram.HEAVEN, 25),
        Hexagram(Trigram.THUNDER, Trigram.LAKE, 17),
        Hexagram(Trigram.THUNDER, Trigram.FIRE, 21),
        Hexagram(Trigram.THUNDER, Trigram.THUNDER, 51),
        Hexagram(Trigram.THUNDER, Trigram.WIND, 42),
        Hexagram(Trigram.THUNDER, Trigram.WATER, 3),
        Hexagram(Trigram.THUNDER, Trigram.MOUNTAIN, 27),
        Hexagram(Trigram.THUNDER, Trigram.EARTH, 24)
    ],
    [
        Hexagram(Trigram.WIND, Trigram.HEAVEN, 44),
        Hexagram(Trigram.WIND, Trigram.LAKE, 28),
        Hexagram(Trigram.WIND, Trigram.FIRE, 50),
        Hexagram(Trigram.WIND, Trigram.THUNDER, 32),
        Hexagram(Trigram.WIND, Trigram.WIND, 57),
        Hexagram(Trigram.WIND, Trigram.WATER, 48),
        Hexagram(Trigram.WIND, Trigram.MOUNTAIN, 18),
        Hexagram(Trigram.WIND, Trigram.EARTH, 46)
    ],
    [
        Hexagram(Trigram.WATER, Trigram.HEAVEN, 6),
        Hexagram(Trigram.WATER, Trigram.LAKE, 47),
        Hexagram(Trigram.WATER, Trigram.FIRE, 64),
        Hexagram(Trigram.WATER, Trigram.THUNDER, 40),
        Hexagram(Trigram.WATER, Trigram.WIND, 59),
        Hexagram(Trigram.WATER, Trigram.WATER, 29),
        Hexagram(Trigram.WATER, Trigram.MOUNTAIN, 4),
        Hexagram(Trigram.WATER, Trigram.EARTH, 7)
    ],
    [
        Hexagram(Trigram.MOUNTAIN, Trigram.HEAVEN, 33),
        Hexagram(Trigram.MOUNTAIN, Trigram.LAKE, 31),
        Hexagram(Trigram.MOUNTAIN, Trigram.FIRE, 56),
        Hexagram(Trigram.MOUNTAIN, Trigram.THUNDER, 62),
        Hexagram(Trigram.MOUNTAIN, Trigram.WIND, 53),
        Hexagram(Trigram.MOUNTAIN, Trigram.WATER, 39),
        Hexagram(Trigram.MOUNTAIN, Trigram.MOUNTAIN, 52),
        Hexagram(Trigram.MOUNTAIN, Trigram.EARTH, 15)
    ],
    [
        Hexagram(Trigram.EARTH, Trigram.HEAVEN, 12),
        Hexagram(Trigram.EARTH, Trigram.LAKE, 45),
        Hexagram(Trigram.EARTH, Trigram.FIRE, 35),
        Hexagram(Trigram.EARTH, Trigram.THUNDER, 16),
        Hexagram(Trigram.EARTH, Trigram.WIND, 20),
        Hexagram(Trigram.EARTH, Trigram.WATER, 8),
        Hexagram(Trigram.EARTH, Trigram.MOUNTAIN, 23),
        Hexagram(Trigram.EARTH, Trigram.EARTH, 2)
    ]
]

SORTED_HEXAGRAMS = sorted(sum(HEXAGRAMS, []), key=lambda h: h.value)