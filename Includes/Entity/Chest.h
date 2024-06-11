#ifndef CHEST_H
#define CHEST_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include <Interactive.h>

class Role;

class Chest : public Interactive {

public:
    Chest() {};

public:
    // Give Item or Money to Role
    void GiveTreasureTo(Role*);
};

#endif