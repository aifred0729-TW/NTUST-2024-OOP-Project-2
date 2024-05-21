#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <vector>

#include <Attribute.h>
#include <Skill.h>
#include <Equipment.h>
#include "EquipmentTable.h"

class Entity {
private:
	Attribute attribute;      // Attribute
	Skill     skill;          // Skill
	Equipment equipment;	  // Equipment
	uint8_t   status;         // Role Status
	uint8_t   eventID;        // Current Event
	Equipment weapon;         // Current Weapon
	Equipment armor;          // Current Armor
	Equipment accessory;      // Current Accessory
	// For each current attribute, you can use vector<uint8_t> to replace uint8_t to extend the current attribute to a plurality of

public:
	Entity();
	void SetAttribute(const Attribute&);
	void SetSkill(const Skill&);
	void SetEquipment(const Equipment&);
	void SetStatus(const uint8_t);
	void SetEventID(const uint8_t);
	void SetWeapon(const Equipment&);
	void SetArmor(const Equipment&);
	void SetAccessory(const Equipment&);

	Attribute& GetAttribute(void);
	Skill&     GetSkill(void);
	Equipment GetEquipment(void);
	uint8_t    GetStatus(void);
	uint8_t    GetEventID(void);
	Equipment& GetWeapon(void);
	Equipment& GetArmor(void);
	Equipment& GetAccessory(void);

public:
	// Find the Enemy in Range
	bool isInRange(std::vector<Entity*>);
	void Equip(const std::string& equipmentName);
	// ...
};

#endif