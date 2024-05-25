#include "Weapon.h"

// Default constructor
Weapon::Weapon() : name(""), attribute(), skill(), diceAmount(0), attackType('P') {}

// Parameterized constructor
Weapon::Weapon(std::string name, Attribute attribute, Skill skill, uint8_t diceAmount, char attackType)
    : name(name), attribute(attribute), skill(skill), diceAmount(diceAmount), attackType(attackType) {}

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

void Weapon::SetDiceAmount(const uint16_t& diceAmount) {
	this->diceAmount = diceAmount;
}

void Weapon::SetAttackType(const char& attackType) {
	this->attackType = attackType;
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

uint16_t Weapon::GetDiceAmount() const {
	return diceAmount;
}

char Weapon::GetAttackType() const {
	return attackType;
}