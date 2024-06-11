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
class WorldMap;

class Game {
private:
    std::vector<Role*> movePriority; // Priority of Character Movement

private:
    std::vector<Role*> roles;

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

    void runRoleTurn(Role* RoleRef, long long turn);

public:
    // Game Main Process
    void MainProcess(void);
};

#endif