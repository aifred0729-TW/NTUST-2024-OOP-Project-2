#include "../HeaderPack.h"

class Entity
{
private:
    Attribute attribute;      // Attribute
    Skill     skill;          // Skill
    uint32_t  HP;             // HP
    uint8_t   status;         // Role Status
    uint8_t   classId;        // Current Profession
    uint8_t   eventId;        // Current Event
    uint8_t   statusId;       // Current Status
    uint8_t   weaponId;       // Current Weapon
    uint8_t   armorId;        // Current Armor
    uint8_t   accessoryId;    // Current Accessory
    // For each current attribute, you can use vector<uint8_t> to replace uint8_t to extend the current attribute to a plurality of

public:
    // Find the Enemy in Range
    bool isInRangeOf(std::vector<Entity*>);

    // ...
};