#ifndef ARMOR_H
#define ARMOR_H

#include "Attribute.h"
#include "Skill.h"

class Armor {
private:
    std::string name;
    Attribute attribute;
    std::vector<Skill> skills;

public:
    Armor();
    Armor(std::string name, Attribute, std::vector<Skill>);

    void SetName(const std::string&);
    void SetAttribute(const Attribute&);
    void SetSkills(const std::vector<Skill>&);

    std::string GetName() const;
    Attribute GetAttribute() const;
    std::vector<Skill> GetSkills() const;
};

#endif