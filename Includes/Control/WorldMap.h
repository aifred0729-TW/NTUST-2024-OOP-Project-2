#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>


class WorldMap {
private:
    std::vector<std::vector<char>> board; // Map Storge
    std::vector<std::vector<bool>> fog;   // War Fog (Make some lamp?)

public:
    // ...
};