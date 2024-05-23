#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <vector>
#include <set>

#include <Attribute.h>
#include <Skill.h>
#include <Equipment.h>
#include "EquipmentTable.h"

class Entity {
private:
	Attribute          attribute;       // Attribute
	std::vector<Skill> skills;          // Skill
	Equipment          equipment;	    // Equipment
	uint8_t            status;          // Role Status
	uint8_t            eventID;         // Current Event

public:
	Entity();
	void SetAttribute(const Attribute&);
	void SetSkills(const std::vector<Skill>&);
	void SetEquipment(const Equipment&);
	void SetStatus(const uint8_t);
	void SetEventID(const uint8_t);

	Attribute&          GetAttribute(void);
	std::vector<Skill>& GetSkills(void);
	Equipment           GetEquipment(void);
	uint8_t             GetStatus(void);
	uint8_t             GetEventID(void);

	Attribute           GetTotalAttribute(void);
	std::vector<Skill>  GetTotalSkills(void);
public:
	// Find the Enemy in Range
	bool isInRange(std::vector<Entity*>);

	// Equip and UnEquip Weapon and Armor
	void EquipWeapon(const std::string& equipmentName);
	void EquipArmor(const std::string& equipmentName);
	void EquipAccessory(const std::string& equipmentName);
	void UnEquipWeapon();
	void UnEquipArmor();
	void UnEquipAccessory();
	// ...
};

#endif