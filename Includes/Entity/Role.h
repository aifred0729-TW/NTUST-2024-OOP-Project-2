#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include "Entity.h"
#include "../Gadget/Item.h"
#include "../Gadget/Equipment.h"

class Role : public Entity {
private:
    Item      pack;
    Equipment equipment;
    uint8_t   movementPoint;
    uint32_t  step;
    std::pair<uint32_t, uint32_t> position;

public:
    // ...
};