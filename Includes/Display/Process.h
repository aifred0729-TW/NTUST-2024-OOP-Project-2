#pragma once
#include "../HeaderPack.h"

#include "../Entity/Entity.h"
#include "../Entity/Store.h"
#include "../Entity/Interactive.h"
#include "../Gadget/Dice.h"
#include "../Incident/Field.h"

class Process {
private:

public:
    // Handle Prepare Battle
    int HandlePreBattle(std::vector<Entity*>, std::vector<Entity*>);

    // Handle Display Menu
    int HandleMemu(void);

    // Handle Display Backpack
    int Handle(std::vector<std::pair<int, int>>*);

    // Handle Display Dice
    int Handle(std::vector<Dice*>);

    // Handle Display Information of Roles
    int Handle(std::vector<Entity*>);

    // Handle Display Battle Status
    int Handle(Field*);

    // Handle Display Shops
    int Handle(Store*);

    // Handle Display Interactive Objects
    int Handle(Interactive*);

    // ...
};