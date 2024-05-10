#include "../HeaderPack.h"

class Entity {
private:
    Attribute attribute;      // Attribute
    Skill     skill;          // Skill
    uint32_t  HP;             // HP
    uint8_t   status;         // Role Status
    uint8_t   classID;        // Current Profession
    uint8_t   eventID;        // Current Event
    uint8_t   statusID;       // Current Status
    uint8_t   weaponID;       // Current Weapon
    uint8_t   armorID;        // Current Armor
    uint8_t   accessoryID;    // Current Accessory
    // For each current attribute, you can use vector<uint8_t> to replace uint8_t to extend the current attribute to a plurality of

public:
    // Find the Enemy in Range
    bool isInRange(std::vector<Entity*>);

    // ...
};