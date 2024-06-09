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
#include "SkillTable.h"

class Active;

class Entity {
protected:
	std::string        name;            // Role Name
	Attribute          attribute;       // Attribute
	Skill              skill;           // Skill
	Equipment          equipment;	    // Equipment
	Dice               dice;            // Dice
	uint8_t            status;          // Role Status
	uint8_t            eventID;         // Current Event

public:
	Entity();
	Entity(std::string name);

	void SetName(const std::string&);
	void SetAttribute(const Attribute&);
	void SetSkill(const Skill&);
	void SetEquipment(const Equipment&);
	void SetDice(const Dice&);
	void SetStatus(const uint8_t);
	void SetEventID(const uint8_t);

	std::string         GetName(void);
	Attribute&          GetAttribute(void);
	Skill&              GetSkill(void);
	Equipment           GetEquipment(void);
	Dice&               GetDice(void);
	uint8_t             GetStatus(void);
	uint8_t             GetEventID(void);

	Attribute           GetTotalAttribute(void);
	Skill               GetTotalSkill(void);

public:
	// Find the Enemy in Range
	bool isInRange(std::vector<Entity*>);
	// 直接強制用set套上裝備，沒有在跟你把裝備拿下來的
	void equipForce(std::string equipmentName);
	void unEquipForce(std::string equipmentName);
	// 主動技能實做
	void useActive(std::string skillName, std::vector<Entity*> targets);
	// 計算經過一切計算後受到的傷害(直接傳原始傷害進來就好)
	void takeDamage(int16_t damage, char attackType);
	// 直接受到的治療數值
	void heal(int16_t heal);
};

#endif