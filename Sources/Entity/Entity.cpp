#include "../../Includes/Entity/Entity.h"
#include "../../Includes/Gadget/EquipmentTable.h"

// Public
Entity::Entity() {
	attribute = Attribute();
	attribute.randomAttribute();
	Skill attackSkill("Attack", SkillType::ACTIVE);
	Skill fleeSkill("Flee", SkillType::ACTIVE);
	skills.push_back(attackSkill);
	skills.push_back(fleeSkill);
	equipment = Equipment();
	status = 0;
	eventID = 0;
}

void Entity::EquipWeapon(const std::string& equipmentName) {
	auto it = EquipmentTable::weaponMap.find(equipmentName);
	if (it != EquipmentTable::weaponMap.end()) {
		UnEquipWeapon();
		this->equipment.SetWeaponAttribute(it->second.GetWeaponAttribute());
		this->equipment.SetWeaponSkills(it->second.GetWeaponSkills());
	} else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
}

void Entity::EquipArmor(const std::string& equipmentName) {
	auto it = EquipmentTable::armorMap.find(equipmentName);
	if (it != EquipmentTable::armorMap.end()) {
		UnEquipArmor();
		this->equipment.SetArmorAttribute(it->second.GetArmorAttribute());
		this->equipment.SetArmorSkills(it->second.GetArmorSkills());
	} else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
}

void Entity::EquipAccessory(const std::string& equipmentName) {
	auto it = EquipmentTable::accessoryMap.find(equipmentName);
	if (it != EquipmentTable::accessoryMap.end()) {
		UnEquipAccessory();
		this->equipment.SetAccessoryAttribute(it->second.GetAccessoryAttribute());
		this->equipment.SetAccessorySkills(it->second.GetAccessorySkills());
	}
	else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
}

void Entity::UnEquipWeapon() {
	auto it = EquipmentTable::weaponMap.find("BareHand");
	this->equipment.SetWeaponAttribute(it->second.GetWeaponAttribute());
	this->equipment.SetWeaponSkills(it->second.GetWeaponSkills());
}

void Entity::UnEquipArmor() {
	auto it = EquipmentTable::armorMap.find("BareBody");
	this->equipment.SetArmorAttribute(it->second.GetArmorAttribute());
	this->equipment.SetArmorSkills(it->second.GetArmorSkills());
}

void Entity::UnEquipAccessory() {
	auto it = EquipmentTable::accessoryMap.find("BareAccessory");
	this->equipment.SetAccessoryAttribute(it->second.GetAccessoryAttribute());
	this->equipment.SetAccessorySkills(it->second.GetAccessorySkills());
}

Attribute Entity::GetTotalAttribute(void) {
	Attribute totalAttribute = attribute;
	totalAttribute += equipment.GetAdditionalAttribute();
	return totalAttribute;
}

std::vector<Skill> Entity::GetTotalSkills(void) {
	std::vector<Skill> skills = equipment.GetAdditionalSkills();
	skills.insert(skills.end(), this->skills.begin(), this->skills.end());
	return skills;
}

bool Entity::isInRange(std::vector<Entity*>) {
	return 0;
}

void Entity::SetAttribute(const Attribute& attribute) {
	this->attribute = attribute;
}

void Entity::SetSkills(const std::vector<Skill>& skills) {
	this->skills = skills;
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

std::vector<Skill>& Entity::GetSkills(void) {
	return skills;
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