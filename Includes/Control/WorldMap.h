#ifndef WORLD_MAP_H
#define WORLD_MAP_H

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
    static std::vector<std::vector<char>> board; // Map Storge
    static std::vector<std::vector<bool>> fog;   // War Fog (Make some lamp?)

public:
    WorldMap(/**/);

    std::vector<std::vector<char>>& GetBoard(void);
    void SetBoard(const std::vector<std::vector<char>>&);

    std::vector<std::vector<bool>>& GetFog(void);
    void GetFog(const std::vector<std::vector<bool>>&);

public:
    // ...
};

#endif