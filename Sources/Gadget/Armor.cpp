#include "Armor.h"

// Default constructor
Armor::Armor() : name(), attribute(), skills() {}

// Parameterized constructor
Armor::Armor(std::string name, Attribute attribute, std::vector<Skill> skills)
    : name(name), attribute(attribute), skills(skills) {}

// Setters
void Armor::SetName(const std::string& name) {
	this->name = name;
}

void Armor::SetAttribute(const Attribute& attribute) {
    this->attribute = attribute;
}

void Armor::SetSkills(const std::vector<Skill>& skills) {
    this->skills = skills;
}

// Getters
std::string Armor::GetName() const {
	return name;
}

Attribute Armor::GetAttribute() const {
    return attribute;
}

std::vector<Skill> Armor::GetSkills() const {
    return skills;
}