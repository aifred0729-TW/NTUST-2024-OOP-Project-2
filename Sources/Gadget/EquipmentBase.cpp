#include <EquipmentBase.h>

// Default constructor
EquipmentBase::EquipmentBase() {}

// Parameterized constructor
EquipmentBase::EquipmentBase(std::string name, Attribute attribute, Skill skill)
	: name(name), attribute(attribute), skill(skill) {}

Accessory::Accessory() {}
Accessory::Accessory(std::string name, Attribute attribute, Skill skill) : EquipmentBase(name, attribute, skill) {}

Armor::Armor() {}
Armor::Armor(std::string name, Attribute attribute, Skill skill) : EquipmentBase(name, attribute, skill) {}

// Setters
void EquipmentBase::SetName(const std::string& name) {
	this->name = name;
}

void EquipmentBase::SetAttribute(const Attribute& attribute) {
	this->attribute = attribute;
}

void EquipmentBase::SetSkill(const Skill& skill) {
	this->skill = skill;
}

// Getters
std::string EquipmentBase::GetName() const {
	return name;
}

Attribute EquipmentBase::GetAttribute() const {
	return attribute;
}

Skill EquipmentBase::GetSkill() const {
	return skill;
}

Weapon::Weapon() :diceAmount(0), attackType(0) {}

Weapon::Weapon(std::string name, Attribute attribute, Skill skill, uint8_t diceAmount, char attackType)
	: EquipmentBase(name, attribute, skill), diceAmount(diceAmount), attackType(attackType) {}

void Weapon::SetDiceAmount(const uint16_t& diceAmount) {
	this->diceAmount = diceAmount;
}

void Weapon::SetAttackType(const char& attackType) {
	this->attackType = attackType;
}

uint16_t Weapon::GetDiceAmount() const {
	return diceAmount;
}

char Weapon::GetAttackType() const {
	return attackType;
}