#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <cstdint>
#include <vector>
#include "Attribute.h"
#include "Skill.h"

class Equipment {
private:
    uint8_t id;
    Attribute attribute;
    std::vector<Skill> skills;
    uint8_t quality;

public:
    Equipment();  // Default constructor
    Equipment(uint8_t, Attribute, std::vector<Skill>, uint8_t);

    void SetID(const uint8_t);
    void SetAttribute(const Attribute&);
    void SetSkills(const std::vector<Skill>&);
    void SetQuality(const uint8_t);

    uint8_t GetID() const;
    Attribute GetAttribute() const;
    std::vector<Skill> GetSkills() const;
    uint8_t GetQuality() const;
};

#endif
