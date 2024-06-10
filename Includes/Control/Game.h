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
    WorldMap* worldMap;              // Map

private:
    int Move(void);
    int GetKeyboard(void);
    int GiveRandomAttribate(void);

    // ...

public:
    Game() {
        ;
    }

public:
    // Initialize Game
    void Initialize();

    // Game Main Process
    void MainProcess(void);
};

#endif