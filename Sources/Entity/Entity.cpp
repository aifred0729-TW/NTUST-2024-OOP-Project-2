#include "../../Includes/Entity/Entity.h"
#include "../../Includes/Gadget/EquipmentTable.h"

// Public
Entity::Entity() {
	attribute = Attribute();
	skill = Skill();
	equipment = Equipment();
	status = 0;
	eventID = 0;
	weapon = Equipment();
	armor = Equipment();
	accessory = Equipment();
}

void Entity::Equip(const std::string& equipmentName) {
	auto it = EquipmentTable::equipmentMap.find(equipmentName);
	if (it != EquipmentTable::equipmentMap.end()) {
		this->SetEquipment(it->second);
	}
	else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
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

void Entity::SetWeapon(const Equipment& weapon) {
	this->weapon = weapon;
}

void Entity::SetArmor(const Equipment& armor) {
	this->armor = armor;
}

void Entity::SetAccessory(const Equipment& accessory) {
	this->accessory = accessory;
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

Equipment& Entity::GetWeapon(void) {
	return weapon;
}

Equipment& Entity::GetArmor(void) {
	return armor;
}

Equipment& Entity::GetAccessory(void) {
	return accessory;
}