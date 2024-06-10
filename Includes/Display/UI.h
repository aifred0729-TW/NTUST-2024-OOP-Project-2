#ifndef UI_H
#define UI_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>
#include "Displayer.h"
#include <Attribute.h>

class Dice;
class Role;
class Ememy;
class Field;
class Store;
class Entity;
class Interactive;
class Action;

namespace UI {
    using namespace Displayer;
    //std::stack<std::vector<std::vector<char>>> prevPicture;
    //WorldMap* worldMapPoac;
    //Field* fieldPointer;

    // Check whether the terminal size is big enough
    void checkConsoleSize(int, int);

    // 戰鬥記錄初始化
    void logInitialization();

    // 戰鬥紀錄
    void logEvent(const std::string&);

    void logDivider(const std::string&);
    void logDivider(const std::string&, const std::string&);

    // Prepare Battle
    int PreBattle(std::vector<Enemy*>, std::vector<Role*>);

    // Display Menu
    int ShowMenu(void);

    // Display Backpack
    int Display(std::vector<std::pair<int, int>>*);

    // Display Dice
    int Display(Dice*);

    //更新戰鬥中的玩家資料
    void renewPlayerInfo();

    //戰鬥中的行動順序
    void printPriority(std::vector<Action*>);

    // Display Information of Entities for Field through its ID
    int Display(Entity*);

    // Display Battle Status
    int Display(Field*);

    // Display Shops
    int Display(Store*);

    // Display Interactive Objects
    int Display(Interactive*);

    // Relocation Map to Roles，and Make it the Center Point Shows Part of Map
    int ReLocation(Role*);

    //玩家選取框的玩家
    void PlayerFrame(int);
    void PlayerFrame(std::vector<int>);

    //地圖階段
    void PreWorldMap(std::vector<Role*>);

    void PrintWorldMap();

    void distanceDisplay(int , int , int);
    // ...
};

#endif