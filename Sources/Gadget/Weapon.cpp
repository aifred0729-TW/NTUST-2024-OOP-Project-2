#include "Weapon.h"

// Default constructor
Weapon::Weapon() : attribute(), skill() {}

// Parameterized constructor
Weapon::Weapon(std::string name, Attribute attribute, Skill skill)
    : name(name), attribute(attribute), skill(skill) {}

// Setters
void Weapon::SetName(const std::string& name) {
	this->name = name;
}

void Weapon::SetAttribute(const Attribute& attribute) {
    this->attribute = attribute;
}

void Weapon::SetSkill(const Skill& skill) {
    this->skill = skill;
}

// Getters
std::string Weapon::GetName() const {
	return name;
}

Attribute Weapon::GetAttribute() const {
    return attribute;
}

Skill Weapon::GetSkill() const {
    return skill;
}