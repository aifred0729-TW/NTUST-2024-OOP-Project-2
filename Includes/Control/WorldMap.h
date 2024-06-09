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
#include <fstream>
#include <sstream>
#include "ConstData.h"

class WorldMap {
private:
    // Map Structure
    // 0 = Player (不他不該出現在這裡)
    // 1 = Ground (Allow to Pass)
    // 2 = Wall   (Not Allow to Pass)
    // 3 = Tree   (Not Allow to Pass)
    // 4 = Water  (Not Allow to Pass)
    // 5 = Shop   (Allow to Pass) (修改至可互動物件)
    // 6 = Enemy  (Allow to Pass) (修改至可互動物件)

    static std::vector<std::vector<int>>  map; // Map Storge
    static std::vector<std::vector<bool>> fog; // War Fog (Make some lamp?)

public:
    WorldMap() { ; };

    WorldMap(std::string mapFile) {
        loadMap("../Resources/" + mapFile);
        loadFog();
    }

    //只能使用一次
    static void loadMap(std::string mapFile);
    //只能使用一次
    static void loadFog();

    static std::vector<std::vector<int>> GetMap(void);

    static void SetMap(int row, int col, MAP_ELEMENT element);

    static std::vector<std::vector<bool>> GetFog(void);
    static void SetFog(int row, int col);

public:
    // ...
};

#endif