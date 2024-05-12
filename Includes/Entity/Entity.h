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
    int8_t    entityID;       // label for class UI and Field
    uint32_t  priority;       // Current priority for Entity
    uint32_t  turn;           // Current turn for Entity
    uint8_t   mode;           // Entity mode which means that Role or Enemy mode
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
    void SetEntityID(const int8_t);
    void SetPriority(const uint32_t);
    void SetTurn(const uint32_t);
    void SetMode(const uint8_t);

    Attribute GetAttribute(void);
    Skill     GetSkill(void);
    uint32_t  GetHP(void);
    uint8_t   GetStatus(void);
    uint8_t   GetEventID(void);
    uint8_t   GetWeaponID(void);
    uint8_t   GetArmorID(void);
    uint8_t   GetAccessoryID(void);
    int8_t    GetEntityID(void);
    uint32_t  GetPriority(void);
    uint32_t  GetTurn(void);
    uint8_t   GetMode(void);

public:
    // Find the Enemy in Range
    bool isInRange(std::vector<Entity*>);

    // ...
};

#endif