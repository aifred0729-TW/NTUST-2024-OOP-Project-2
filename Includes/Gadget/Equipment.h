#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include "../Entity/Role.h"
#include "../Gadget/Attribute.h"
#include "../Gadget/Skill.h"

class Equipment {
private:
    Attribute attribate;
    Skill     skill;
    uint8_t   quality;

public:
    // Equip with Role
    void EquipWith(Role*);
};