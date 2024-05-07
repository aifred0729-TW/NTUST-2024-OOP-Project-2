#include "../HeaderPack.h"

class Dice
{
private:
    uint8_t              count;        // Count of Dice
    uint8_t              focusCount;   // Focus Skill Effect
    std::vector<uint8_t> successRate;  // Dice Successful Rate ([0, 100])
    std::vector<double>  rateAddition; // Dice Rate Addition

public:
    // Roll Dice
    void RollDice(void)

    // ...
};