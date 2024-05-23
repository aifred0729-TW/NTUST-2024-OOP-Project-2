#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "Attribute.h"
#include "Skill.h"

class Accessory {
private:
    std::string name;
    Attribute attribute;
    Skill skill;

public:
    Accessory();
    Accessory(std::string name, Attribute, Skill);

    void SetName(const std::string&);
    void SetAttribute(const Attribute&);
    void SetSkill(const Skill&);

    std::string GetName() const;
    Attribute GetAttribute() const;
    Skill GetSkill() const;
};

#endif