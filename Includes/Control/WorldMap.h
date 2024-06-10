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

class Role;
class Enemy;
class Entity;
class Store;

struct Rect {
    int terrain; // 地形
    std::vector<Enemy*> enemys; // 地塊上的敵人
    std::vector<Role*> roles; // 地塊上的角色
    std::vector<Store*> stores; // 地塊上的商店
    bool moveable;
};

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
    extern std::vector<std::vector<std::string>> renderMap; // 每個單元為可輸出色塊
    extern std::vector<Enemy*> enemys;
    extern std::vector<Role*> roles;
    extern std::vector<Store*> stores;

    // 地圖目前對準的地塊
    // 只能使用一次
    void loadMap(std::string mapFile);
    // 只能使用一次
    void loadFog();

    std::vector<std::vector<int>> getMap(void);
    std::vector<std::vector<bool>> getFog(void);
    std::vector<std::vector<std::string>> getRenderMap();
    std::vector<std::string> getColorBoard();
    std::pair<int, int> getPos();

    int getHeight();
    int getWidth();

    void SetEnemys(std::vector<Enemy*> enemys);
    void SetRoles(std::vector<Role*> roles);
    void SetStores(std::vector<Store*> stores);

    void SetMap(int, int, int);

    void SetFog(int, int);

    bool posValid(std::pair<int, int> pos);
    int setPos(std::pair<int, int> pos);
    int movePos(std::pair<int, int> pos);
    int movePos(int x, int y);

    void renderColor();
    bool VisibleOnMap(std::pair<int, int > pos);
    Rect GetRect(std::pair<int, int > pos);
    Rect GetRect();

    int manhattanDistance(std::pair<int, int> player, std::pair<int, int> enemy);

};

#endif