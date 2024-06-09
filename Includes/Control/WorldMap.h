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

namespace WorldMap {

    // Map Structure
    // 0 = Player (不他不該出現在這裡)
    // 1 = Ground (Allow to Pass)
    // 2 = Wall   (Not Allow to Pass)
    // 3 = Tree   (Not Allow to Pass)
    // 4 = Water  (Not Allow to Pass)
    // 5 = Shop   (Allow to Pass) (修改至可互動物件)
    // 6 = Enemy  (Allow to Pass) (修改至可互動物件)

    extern int HEIGHT;
    extern int WIDTH;

    extern std::pair<int, int> pos;
    extern std::vector<std::vector<int>>  map; // Map Storge
    extern std::vector<std::vector<bool>> fog; // War Fog (Make some lamp?)

    // 地圖目前對準的地塊
    // 只能使用一次
    void loadMap(std::string mapFile);
    // 只能使用一次
    void loadFog();

    std::vector<std::vector<int>> GetMap(void);

    void SetMap(int, int, int);

    std::vector<std::vector<bool>> GetFog(void);

    void SetFog(int, int);

    void setPos(std::pair<int, int> pos);

    std::pair<int, int> getPos();

    // ...
};

#endif