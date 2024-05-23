#include "../../Includes/Entity/Entity.h"
#include "../../Includes/Gadget/EquipmentTable.h"
#include "../../Includes/Gadget/SkillTable.h"

// Public
Entity::Entity() {
	attribute = Attribute();
	attribute.randomAttribute();
	equipment = Equipment();
	skill = Skill();
	Active Attack = SkillTable::activeMap.find("Attack")->second;
	Active Flee = SkillTable::activeMap.find("Flee")->second;
	skill.pushActive(Attack);
	skill.pushActive(Flee);
	status = 0;
	eventID = 0;
}

void Entity::EquipWeapon(const std::string& equipmentName) {
	auto it = EquipmentTable::weaponMap.find(equipmentName);
	if (it != EquipmentTable::weaponMap.end()) {
		UnEquipWeapon();
		this->equipment.SetWeapon(it->second);
	} else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
}

void Entity::EquipArmor(const std::string& equipmentName) {
	auto it = EquipmentTable::armorMap.find(equipmentName);
	if (it != EquipmentTable::armorMap.end()) {
		// UnEquipArmor();
		this->equipment.SetArmor(it->second);
	} else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
}

void Entity::EquipAccessory(const std::string& equipmentName) {
	auto it = EquipmentTable::accessoryMap.find(equipmentName);
	if (it != EquipmentTable::accessoryMap.end()) {
		UnEquipAccessory();
		this->equipment.SetAccessory(it->second);
	} else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
}

void Entity::UnEquipWeapon() {
	auto it = EquipmentTable::weaponMap.find("BareHand");
	this->equipment.SetWeapon(it->second);
}

void Entity::UnEquipArmor() {
	auto it = EquipmentTable::armorMap.find("BareBody");
	this->equipment.SetArmor(it->second);
}

void Entity::UnEquipAccessory() {
	auto it = EquipmentTable::accessoryMap.find("BareAccessory");
	this->equipment.SetAccessory(it->second);
}

Attribute Entity::GetTotalAttribute(void) {
	Attribute totalAttribute;
	totalAttribute += this->attribute;
	totalAttribute += equipment.GetTotalAttribute();
	return totalAttribute;
}

Skill Entity::GetTotalSkill(void) {
	Skill fuck;
	fuck += this->skill;
	fuck += equipment.GetTotalSkills();
	return fuck;
}

bool Entity::isInRange(std::vector<Entity*>) {
	return 0;
}

void Entity::SetAttribute(const Attribute& attribute) {
	this->attribute = attribute;
}

void Entity::SetSkill(const Skill& skill) {
	this->skill = skill;
}

void Entity::SetEquipment(const Equipment& equipment) {
	this->equipment = equipment;
}

void Entity::SetStatus(const uint8_t status) {
	this->status = status;
}

void Entity::SetEventID(const uint8_t eventID) {
	this->eventID = eventID;
}

Attribute& Entity::GetAttribute(void) {
	return attribute;
}

Skill& Entity::GetSkill(void) {
	return skill;
}

Equipment Entity::GetEquipment(void) {
	return equipment;
}

uint8_t   Entity::GetStatus(void) {
	return status;
}

uint8_t   Entity::GetEventID(void) {
	return eventID;
}