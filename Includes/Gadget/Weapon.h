#ifndef WEAPON_H
#define WEAPON_H

#include "Attribute.h"
#include "Skill.h"

class Weapon {
private:
    std::string name;
    Attribute attribute;
    Skill skill;
    uint8_t diceAmount;
    char attackType;

public:
    Weapon();
    Weapon(std::string name, Attribute attribute, Skill skill, uint8_t diceAmount, char attackType);

    void SetName(const std::string&);
    void SetAttribute(const Attribute&);
    void SetSkill(const Skill&);
    void SetDiceAmount(const uint16_t&);
    void SetAttackType(const char&);

    std::string GetName() const;
    Attribute GetAttribute() const;
    Skill GetSkill() const;
    uint16_t GetDiceAmount() const;
    char GetAttackType() const;
};

#endif