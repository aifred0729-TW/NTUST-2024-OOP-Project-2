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
#include <random>

class Dice {
private:
    uint8_t              amount;            // Amount of Dice
    uint8_t              movementPoint;     // Movement Point
    uint8_t              focusCount;        // Focus Skill Effect
    std::vector<uint8_t> successRate;       // Dice Successful Rate ([0, 100]). If the value is 90, it means 90% successful rate.
    std::vector<double>  rateAddition;      // Dice Rate Additiond
    std::vector<bool>    result;            // Dice Result

public:
    // Construct dice to calculate movementPoint for map navigation (movement on map).
    Dice(uint8_t speed); 
    // Construct dice with a uniform successRate.
    Dice(uint8_t amount, uint8_t successRate);

    void setMovementPoint(const uint8_t);
    void SetAmount(const uint8_t);
    void SetFocusCount(const uint8_t);
    void SetSuccessRate(const std::vector<uint8_t>&);
    void SetRateAddition(const std::vector<double>&);
    void SetResult(const std::vector<bool>&);
    
    uint8_t              GetMovementPoint(void);
    uint8_t              GetAmount(void);
    uint8_t              GetFocusCount(void);
    std::vector<uint8_t> GetSuccessRate(void);
    std::vector<double>  GetRateAddition(void);
    std::vector<bool>    GetResult(void);

public:
    // Caution: FocusCount and RateAddition would be reset after rolling dice.
    void RollDice(void);
};

#endif