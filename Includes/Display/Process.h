#ifndef PROCESS_H
#define PROCESS_H

#include <vector>

class Dice;
class Role;
class Enemy;
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
    static int focusUseSimulator(int focusPoint, int diceAmount);

    //隸屬於技能目標選取的專注模擬器
    static std::vector<Entity*> targetChoiceSimulator(std::vector<Enemy*>enemys, std::vector<Role*>roles, Role* caster, int TargetType);

    // ...
};

#endif