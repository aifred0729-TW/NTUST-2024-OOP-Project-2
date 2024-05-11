#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>


class Dice {
private:
    uint8_t              diceCount;    // Count of Dice
    uint8_t              focusCount;   // Focus Skill Effect
    std::vector<uint8_t> successRate;  // Dice Successful Rate ([0, 100])
    std::vector<double>  rateAddition; // Dice Rate Addition

public:
    // Roll Dice
    void RollDice(void);

    // ...
};