#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

class Role;
class Store;
class Tent;
class Enemy;
class Attribute;

class Game {
private:
    std::vector<Role*> movePriority; // Priority of Character Movement

private:
    static std::vector<Role*> roles;
    static std::vector<Enemy*> enemys;
    static std::vector<Tent*> tents;
    static std::vector<Store*> stores;

    int Move(void);
    int GetKeyboard(void);
    int GiveRandomAttribate(void);

    // ...

    void sortExecutionRole();

public:
    Game() {}

    // Initialize Game
    void Initialize();



public:

    // Game Main Process
    void MainProcess(void);
    int OnePlayerMovePhase(Role* currentActRole);
    static int GenerateMovementPoint(Role* currentActRole);

    static void createTent(Role*);
    void displayEquipment(Role* role);
    void displayAttribute(Attribute att);
    void choiceItem(Role* role);

};

#endif