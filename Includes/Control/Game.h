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

#include <WorldMap.h>
#include <Role.h>
#include <Enemy.h>
#include <UI.h>
#include <Process.h>
#include <SkillTable.h>
#include <Equipment.h>
#include <ItemTable.h>

class Game {
private:
    std::vector<Role*> movePriority; // Priority of Character Movement

private:
    std::vector<Role> roles;

    int Move(void);
    int GetKeyboard(void);
    int GiveRandomAttribate(void);

    // ...

    void sortExecutionRole();

public:
    Game() {
        Initialize();
    }

    // Initialize Game
    void Initialize();

    bool checkIsOnShop();
    bool checkIsOnEnemy();


public:
    // Game Main Process
    void MainProcess(void);
};

#endif