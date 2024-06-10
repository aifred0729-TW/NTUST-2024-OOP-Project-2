#ifndef EQUIPMENT_COMPONENT_H
#define EQUIPMENT_COMPONENT_H

#include <Attribute.h>
#include <Skill.h>

class EquipmentBase {
private:
	std::string name;
	Attribute attribute;
	Skill skill;

public:
	EquipmentBase();
	EquipmentBase(std::string name, Attribute, Skill);

	void SetName(const std::string&);
	void SetAttribute(const Attribute&);
	void SetSkill(const Skill&);

	std::string GetName() const;
	Attribute GetAttribute() const;
	Skill& GetSkill() ;
};

class Accessory :public EquipmentBase {
public:
	Accessory();
	Accessory(std::string, Attribute, Skill);
};

class Armor :public EquipmentBase {
public:
	Armor();
	Armor(std::string, Attribute, Skill);
};

class Weapon :public EquipmentBase {
private:
	uint8_t diceAmount;
	char attackType;

public:
	Weapon();
	Weapon(std::string name, Attribute attribute, Skill skill, uint8_t diceAmount, char attackType);

	void SetDiceAmount(const uint16_t&);
	void SetAttackType(const char&);

	uint16_t GetDiceAmount() const;
	char GetAttackType() const;
};

#endif