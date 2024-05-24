#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "Attribute.h"
#include "Skill.h"
#include "Equipment.h"
#include "EquipmentTable.h"

class Active;

class Entity {
private:
	Attribute          attribute;       // Attribute
	Skill              skill;           // Skill
	Equipment          equipment;	    // Equipment
	uint8_t            status;          // Role Status
	uint8_t            eventID;         // Current Event

public:
	Entity();
	void SetAttribute(const Attribute&);
	void SetSkill(const Skill&);
	void SetEquipment(const Equipment&);
	void SetStatus(const uint8_t);
	void SetEventID(const uint8_t);

	Attribute&          GetAttribute(void);
	Skill&              GetSkill(void);
	Equipment           GetEquipment(void);
	uint8_t             GetStatus(void);
	uint8_t             GetEventID(void);

	Attribute           GetTotalAttribute(void);
	Skill               GetTotalSkill(void);
public:
	// Find the Enemy in Range
	bool isInRange(std::vector<Entity*>);
	// Equip and UnEquip Weapon and Armor
	// 需要和物品欄結合才算完成
	void equip(std::string equipmentName);
	void unEquip(std::string equipmentName);
	// 技能實做
	void useSkill(std::string skillName, std::vector<Entity*> targets);
};

#endif