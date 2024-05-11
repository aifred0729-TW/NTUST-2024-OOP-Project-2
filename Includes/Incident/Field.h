#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include "../Entity/Enemy.h"
#include "../Entity/Role.h"

class Field {
private:
    Dice                dice;               // Dice
    uint8_t             enemyPlayerCount; // Count of Enemy
    std::vector<Enemy*> enemyEngage;        // Engage Enemys
    uint8_t             rolePlayerCount;  // Count of Role
    std::vector<Role*>  roleEngage;         // Engage Roles
    uint8_t             turn;               // Current Turn
    uint8_t             round;              // Current Round

private:
    // Detect Status and Compute
    void DetectStatus(uint8_t);

public:
    // ...
};