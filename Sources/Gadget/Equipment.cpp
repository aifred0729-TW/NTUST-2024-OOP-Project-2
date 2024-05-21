#include "Equipment.h"

Equipment::Equipment()
    : id(0), attribute(), skills(), quality(0) {}

Equipment::Equipment(uint8_t id, Attribute attribute, std::vector<Skill> skills, uint8_t quality)
    : id(id), attribute(attribute), skills(skills), quality(quality) {}

void Equipment::SetID(const uint8_t id) {
    this->id = id;
}

void Equipment::SetAttribute(const Attribute& attribute) {
    this->attribute = attribute;
}

void Equipment::SetSkills(const std::vector<Skill>& skills) {
    this->skills = skills;
}

void Equipment::SetQuality(const uint8_t quality) {
    this->quality = quality;
}

uint8_t Equipment::GetID() const {
    return id;
}

Attribute Equipment::GetAttribute() const {
    return attribute;
}

std::vector<Skill> Equipment::GetSkills() const {
    return skills;
}

uint8_t Equipment::GetQuality() const {
    return quality;
}
