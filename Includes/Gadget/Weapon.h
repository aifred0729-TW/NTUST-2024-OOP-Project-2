#ifndef WEAPON_H
#define WEAPON_H

#include "Attribute.h"
#include "Skill.h"

class Weapon {
private:
    std::string name;
    Attribute attribute;
    std::vector<Skill> skills;

public:
    Weapon();
    Weapon(std::string name, Attribute, std::vector<Skill>);

    void SetName(const std::string&);
    void SetAttribute(const Attribute&);
    void SetSkills(const std::vector<Skill>&);

    std::string GetName() const;
    Attribute GetAttribute() const;
    std::vector<Skill> GetSkills() const;
};

#endif