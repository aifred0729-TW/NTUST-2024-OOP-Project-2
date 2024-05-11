#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>


class Attribute {
private:
    uint8_t focus;     // Focus
    uint8_t maxHP;     // Max HP
    uint8_t SPD;       // Speed
    uint8_t ACC;       // Hit Rate
    uint8_t PA;        // Physical Attack
    uint8_t MA;        // Magic Attack
    uint8_t PD;        // Physical Defense
    uint8_t MD;        // Magic Defense

public:
    //...
};
