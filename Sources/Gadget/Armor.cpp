#include "Armor.h"

// Default constructor
Armor::Armor() : name(), attribute(), skill() {}

// Parameterized constructor
Armor::Armor(std::string name, Attribute attribute, Skill skill)
    : name(name), attribute(attribute), skill(skill) {}

// Setters
void Armor::SetName(const std::string& name) {
	this->name = name;
}

void Armor::SetAttribute(const Attribute& attribute) {
    this->attribute = attribute;
}

void Armor::SetSkill(const Skill& skill) {
    this->skill = skill;
}

// Getters
std::string Armor::GetName() const {
	return name;
}

Attribute Armor::GetAttribute() const {
    return attribute;
}

Skill Armor::GetSkill() const {
    return skill;
}