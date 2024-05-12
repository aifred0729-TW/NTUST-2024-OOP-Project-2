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
    Game();

    std::vector<Role*> GetMovePriority(void);
    void SetMovePriority(const std::vector<Role*>&);
    
    WorldMap *GetWorldMap(void);
    void SetWorldMap(const WorldMap * &);

public:
    // Initialize Game
    int Init(void);
};

#endif