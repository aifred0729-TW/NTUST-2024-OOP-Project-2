#ifndef ARMOR_H
#define ARMOR_H

#include "Attribute.h"
#include "Skill.h"

class Armor {
private:
    std::string name;
    Attribute attribute;
    Skill skill;

public:
    Armor();
    Armor(std::string name, Attribute, Skill);

    void SetName(const std::string&);
    void SetAttribute(const Attribute&);
    void SetSkill(const Skill&);

    std::string GetName() const;
    Attribute GetAttribute() const;
    Skill GetSkill() const;
};

#endif