#ifndef DICE_H
#define DICE_H

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
    void SetDiceCount(const uint8_t);
    void SetFocusCount(const uint8_t);
    void SetSuccessRate(const std::vector<uint8_t>&);
    void SetRateAddition(const std::vector<double>&);
    
    uint8_t              GetFocus(void);
    uint8_t              GetFocusCount(void);
    std::vector<uint8_t> GetSuccessRate(void);
    std::vector<double>  GetRateAddition(void);

public:
    // Roll Dice
    void RollDice(void);

    // ...
};

#endif