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

#include <WorldMap.h>
#include <Field.h>
#include <Store.h>

class UI {
private:
    std::stack<std::vector<std::vector<char>>> prevPicture;
    WorldMap* worldMapPoac;
    Field* fieldPointer;

public:
    UI(/**/);

public:
    // Prepare Battle
    int PreBattle(std::vector<Entity*>, std::vector<Entity*>);

    // Display Menu
    int ShowMenu(void);

    // Display Backpack
    int Display(std::vector<std::pair<int, int>>*);

    // Display Dice
    int Display(std::vector<Dice*>);

    // Display Information of Roles
    int Display(std::vector<Entity*>);

    // Display Battle Status
    int Display(Field*);

    // Display Shops
    int Display(Store*);

    // Display Interactive Objects
    int Display(Interactive*);

    // Relocation Map to Roles¡Aand Make it the Center Point Shows Part of Map
    int ReLocation(Entity*);

    // ...
};

#endif