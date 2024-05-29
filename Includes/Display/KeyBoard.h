#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <iomanip>

class KeyBoard {
public:
    enum ValidInput {
        EW = 0,
        ES = 1,
        EA = 2,
        ED = 3,
        ESPACE = 4,
        ETAB = 5,
        EQ = 6,
        EE = 7,
        ER = 8,
        EF = 9,
        EZ = 10,
        EX = 11,
        EC = 12,
        EV = 13,
        EESC = 14,
        EENTER = 15,
        INVALID,
    };
    static int keyUpdate(bool key[]);
};

#endif