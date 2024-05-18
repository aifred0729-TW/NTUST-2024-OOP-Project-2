#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <vector>

#include <Attribute.h>
#include <Skill.h>

class Entity {
private:
    Attribute attribute;      // Attribute
    Skill     skill;          // Skill
    uint32_t  HP;             // HP
    uint8_t   status;         // Role Status
    uint8_t   eventID;        // Current Event
    uint8_t   weaponID;       // Current Weapon
    uint8_t   armorID;        // Current Armor
    uint8_t   accessoryID;    // Current Accessory
    // For each current attribute, you can use vector<uint8_t> to replace uint8_t to extend the current attribute to a plurality of

public:
    Entity(/**/);
    void SetAttribute(const Attribute&);
    void SetSkill(const Skill&);
    void SetHP(const uint32_t);
    void SetStatus(const uint8_t);
    void SetEventID(const uint8_t);
    void SetWeaponID(const uint8_t);
    void SetArmorID(const uint8_t);
    void SetAccessoryID(const uint8_t);

    Attribute GetAttribute(void);
    Skill     GetSkill(void);
    uint32_t  GetHP(void);
    uint8_t   GetStatus(void);
    uint8_t   GetEventID(void);
    uint8_t   GetWeaponID(void);
    uint8_t   GetArmorID(void);
    uint8_t   GetAccessoryID(void);

public:
    // Find the Enemy in Range
    bool isInRange(std::vector<Entity*>);

    // ...
};

#endif