#include <EquipmentBase.h>

// Default constructor
EquipmentBase::EquipmentBase() {}

// Parameterized constructor
EquipmentBase::EquipmentBase(std::string name, Attribute attribute, Skill skill)
	: name(name), attribute(attribute), skill(skill) {}

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

Skill& EquipmentBase::GetSkill() {
	return skill;
}

Accessory::Accessory(): EquipmentBase("BareAccessory", Attribute(), Skill()) {}
Accessory::Accessory(std::string name, Attribute attribute, Skill skill) : EquipmentBase(name, attribute, skill) {}

Armor::Armor(): EquipmentBase("BareBody", Attribute(), Skill()) {}
Armor::Armor(std::string name, Attribute attribute, Skill skill) : EquipmentBase(name, attribute, skill) {}

Weapon::Weapon(): EquipmentBase("BareHand", Attribute(), Skill()), diceAmount(0), attackType(0) {}
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