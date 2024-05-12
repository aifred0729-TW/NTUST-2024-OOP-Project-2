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
#include <Role.h>

class Chest : public Interactive {

public:
    Chest(/**/);

public:
    // Give Item to Role
    void GiveItemTo(Role*);
};

#endif