#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include "WorldMap.h"
#include "../Entity/Role.h"

class Game {
private:
    std::vector<Role*> movePriority; // Priority of Character Movement
    WorldMap* worldMap;              // Map

private:
    int Move(void);
    int GetKeyboard(void);
    int GiveRandomAttribate(void);

    // ...

public:
    // Initialize Game
    int Init(void);
};