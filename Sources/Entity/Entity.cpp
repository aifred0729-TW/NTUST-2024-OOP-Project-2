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

void Entity::useSkill(std::string skillName, std::vector<Entity*> target) {
	Skill combinedSkill = GetTotalSkill();
	for (auto active : combinedSkill.GetActive()) {
		if (active.GetName() == skillName) {
			active.apply(*this, target);
			return;
		}
	}
	std::cerr << "Skill " << skillName << " not found in active skills!" << std::endl;
}

void Entity::equip(std::string equipmentName) {
	if (EquipmentTable::weaponMap.find(equipmentName) != EquipmentTable::weaponMap.end()) {
		this->equipment.SetWeapon(EquipmentTable::weaponMap[equipmentName]);
		return;
	} else if (EquipmentTable::armorMap.find(equipmentName) != EquipmentTable::armorMap.end()) {
		this->equipment.SetArmor(EquipmentTable::armorMap[equipmentName]);
		return;
	} else if (EquipmentTable::accessoryMap.find(equipmentName) != EquipmentTable::accessoryMap.end()) {
		this->equipment.SetAccessory(EquipmentTable::accessoryMap[equipmentName]);
		return;
	} else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
}

void Entity::unEquip(std::string equipmentName) {
	if (this->GetEquipment().GetArmor().GetName() == equipmentName) {
		this->equipment.SetArmor(EquipmentTable::armorMap.find("BareBody")->second);
		return;
	} else if (this->GetEquipment().GetWeapon().GetName() == equipmentName) {
		this->equipment.SetWeapon(EquipmentTable::weaponMap.find("BareHand")->second);
		return;
	} else if (this->GetEquipment().GetAccessory().GetName() == equipmentName) {
		this->equipment.SetAccessory(EquipmentTable::accessoryMap.find("BareAccessory")->second);
		return;
	} else {
		std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
	}
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