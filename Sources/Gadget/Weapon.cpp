#include "Weapon.h"

// Default constructor
Weapon::Weapon() : attribute(), skills() {}

// Parameterized constructor
Weapon::Weapon(std::string name, Attribute attribute, std::vector<Skill> skills)
    : name(name), attribute(attribute), skills(skills) {}

// Setters
void Weapon::SetName(const std::string& name) {
	this->name = name;
}

void Weapon::SetAttribute(const Attribute& attribute) {
    this->attribute = attribute;
}

void Weapon::SetSkills(const std::vector<Skill>& skills) {
    this->skills = skills;
}

// Getters
std::string Weapon::GetName() const {
	return name;
}

Attribute Weapon::GetAttribute() const {
    return attribute;
}

std::vector<Skill> Weapon::GetSkills() const {
    return skills;
}