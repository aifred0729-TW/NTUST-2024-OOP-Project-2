#include "Accessory.h"

// Default constructor
Accessory::Accessory() : name(), attribute(), skills() {}

// Parameterized constructor
Accessory::Accessory(std::string name, Attribute attribute, std::vector<Skill> skills)
	:name(name), attribute(attribute), skills(skills) {}

// Setters
void Accessory::SetName(const std::string& name) {
	this->name = name;
}

void Accessory::SetAttribute(const Attribute& attribute) {
	this->attribute = attribute;
}

void Accessory::SetSkills(const std::vector<Skill>& skills) {
	this->skills = skills;
}

// Getters
std::string Accessory::GetName() const {
	return name;
}

Attribute Accessory::GetAttribute() const {
	return attribute;
}

std::vector<Skill> Accessory::GetSkills() const {
	return skills;
}