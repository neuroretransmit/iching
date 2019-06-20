from enum import Enum

SOLID = '==========\n'
BROKEN = '====  ====\n'


class Trigram(Enum):
    HEAVEN = 0
    LAKE = 1
    FIRE = 2
    THUNDER = 3
    WIND = 4
    WATER = 5
    MOUNTAIN = 6
    EARTH = 7

    def __str__(self):
        if self.value == 0:
            return SOLID + SOLID + SOLID
        elif self.value == 1:
            return BROKEN + SOLID + SOLID
        elif self.value == 2:
            return SOLID + BROKEN + SOLID
        elif self.value == 3:
            return BROKEN + BROKEN + SOLID
        elif self.value == 4:
            return SOLID + SOLID + BROKEN
        elif self.value == 5:
            return BROKEN + SOLID + BROKEN
        elif self.value == 6:
            return SOLID + BROKEN + BROKEN
        elif self.value == 7:
            return BROKEN + BROKEN + BROKEN