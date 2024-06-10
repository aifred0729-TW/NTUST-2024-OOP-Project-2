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

#include <ConstData.h>

class WorldMap {
private:
    // Map Structure
    // 0 = Player
    // 1 = Ground (Allow to Pass)
    // 2 = Wall   (Not Allow to Pass)
    // 3 = Tree   (Not Allow to Pass)
    // 4 = Water  (Not Allow to Pass)
    // 5 = Shop   (Not Allow to Pass)
    // 6 = Enemy  (Not Allow to Pass)

    std::vector<std::vector<int>>  map; // Map Storge
    std::vector<std::vector<bool>> fog; // War Fog (Make some lamp?)

    void loadMap(std::string mapFile);
    void loadFog();

public:
    WorldMap() { ; };

    WorldMap(std::string mapFile) {
        loadMap("../Resources/" + mapFile);
        loadFog();
    }

    std::vector<std::vector<int>> GetMap(void);
    void SetMap(int row, int col, MAP_ELEMENT element);

    std::vector<std::vector<bool>> GetFog(void);
    void SetFog(int row, int col);

    int manhattanDistance(std::pair<int, int> player, std::pair<int, int> enemy);
};

#endif