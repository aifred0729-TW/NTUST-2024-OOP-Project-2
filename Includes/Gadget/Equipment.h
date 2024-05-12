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
	Attribute attribate;
	Skill     skill;
	uint8_t   quality;

public:
	void SetAttribute(const Attribute&);
	void SetSkill(const Skill&);
	void SetQuality(const uint8_t);

	Attribute GetAttribute(void);
	Skill     GetSkill(void);
	uint8_t   GetQuality(void);

public:
	// Equip with Role
	void EquipWith(Role*);
};

#endif