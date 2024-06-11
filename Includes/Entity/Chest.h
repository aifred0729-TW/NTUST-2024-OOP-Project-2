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

private:
    std::pair<uint32_t, uint32_t> position;
public:
    Chest() {
        position = { -69, -69 };
    };
    Chest(int x, int y) {
        position = { x,y };
    };
public:
    void SetPosition(const std::pair<uint32_t, uint32_t>&);
    std::pair<uint32_t, uint32_t> GetPosition() const;

    // Give Item or Money to Role
    void GiveTreasureTo(Role*);
};

#endif