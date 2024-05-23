#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "Attribute.h"
#include "Skill.h"

class Accessory {
private:
    std::string name;
    Attribute attribute;
    std::vector<Skill> skills;

public:
    Accessory();
    Accessory(std::string name, Attribute, std::vector<Skill>);

    void SetName(const std::string&);
    void SetAttribute(const Attribute&);
    void SetSkills(const std::vector<Skill>&);

    std::string GetName() const;
    Attribute GetAttribute() const;
    std::vector<Skill> GetSkills() const;
};

#endif