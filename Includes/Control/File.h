#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include "../../Includes/Control/WorldMap.h"
#include "../../Includes/Entity/Role.h"
#include "../../Includes/Entity/Enemy.h"

class File {
private:
    std::fstream FileStream;

public:
    // Load Map from File
    void LoadWorldMap(WorldMap&);

    // Load Role from File
    void LoadRole(Role&);

    // Load Enemy from File
    void LoadEnemy(Enemy&);

    // ...
};