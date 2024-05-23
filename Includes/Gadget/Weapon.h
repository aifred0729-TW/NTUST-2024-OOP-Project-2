#ifndef WEAPON_H
#define WEAPON_H

#include "Attribute.h"
#include "Skill.h"

class Weapon {
private:
    std::string name;
    Attribute attribute;
    Skill skill;

public:
    Weapon();
    Weapon(std::string name, Attribute, Skill);

    void SetName(const std::string&);
    void SetAttribute(const Attribute&);
    void SetSkill(const Skill&);

    std::string GetName() const;
    Attribute GetAttribute() const;
    Skill GetSkill() const;
};

#endif