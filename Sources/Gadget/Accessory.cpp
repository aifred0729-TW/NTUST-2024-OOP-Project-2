#include "Accessory.h"

// Default constructor
Accessory::Accessory() : name(), attribute(), skill() {}

// Parameterized constructor
Accessory::Accessory(std::string name, Attribute attribute, Skill skill)
	:name(name), attribute(attribute), skill(skill) {}

// Setters
void Accessory::SetName(const std::string& name) {
	this->name = name;
}

void Accessory::SetAttribute(const Attribute& attribute) {
	this->attribute = attribute;
}

void Accessory::SetSkill(const Skill& skill) {
	this->skill = skill;
}

// Getters
std::string Accessory::GetName() const {
	return name;
}

Attribute Accessory::GetAttribute() const {
	return attribute;
}

Skill Accessory::GetSkill() const {
	return skill;
}