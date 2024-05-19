#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include <Attribute.h>
#include <Skill.h>

class Role;

class Equipment {
private:
	uint8_t   ID;
	Attribute attribate;
	Skill     skill;
	uint8_t   quality;

public:
	void SetID(const uint8_t);
	void SetAttribute(const Attribute&);
	void SetSkill(const Skill&);
	void SetQuality(const uint8_t);

	uint8_t   GetID(void);
	Attribute GetAttribute(void);
	Skill     GetSkill(void);
	uint8_t   GetQuality(void);

public:
	// Equip with Role
	void EquipWith(Role*);
};

#endif