#include "../HeaderPack.h"

class Equipment
{
private:
    Attribute attribate;
    Skill     skill;
    uint8_t   quality;

public:
    // Equip with Role
    void EquipWith(Role*);
};