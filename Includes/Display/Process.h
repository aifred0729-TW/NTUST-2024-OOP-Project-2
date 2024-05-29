#ifndef PROCESS_H
#define PROCESS_H

#include <Entity.h>
#include <Store.h>
#include <Interactive.h>
#include <Dice.h>
#include <Field.h>

class Dice;
class Role;
class WorldMap;
class Field;
class Store;
class Entity;
class Interactive;

class Process {
private:

public:
    Process(/**/) {}

public:
    // Handle Prepare Battle
    static int HandlePreBattle(std::vector<Enemy*>, std::vector<Role*>);

    //幹架模擬器 先寫來玩玩 之後會移植
    static int fightSimulator(std::vector<Enemy*>enemys, std::vector<Role*>roles);

    //隸屬於幹架模擬的專注模擬器
    static int focusUseSimulator(int, int);

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

#endif