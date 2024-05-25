#ifndef SKILL_BASE_H
#define SKILL_BASE_H

#include <vector> 

#include <Dice.h>
#include <Attribute.h>
#include <SkillCommand.h>

class SkillBase {
private:
	std::string name;
	uint8_t tick;
	uint8_t coolDown;

public:
	SkillBase();
	SkillBase(std::string name, uint8_t tick);

	std::string GetName() const;
	uint8_t GetTick() const;
	uint8_t GetCoolDown() const;

	void SetName(const std::string&);
	void SetTick(const uint8_t&);
	void SetCoolDown(const uint8_t&);
};

class Buff : public SkillBase {
public:
	Buff();
	Buff(std::string, uint8_t);
};

class Passive : public SkillBase {
public:
	Passive();
	Passive(std::string, uint8_t);
};

class Entity;

class Active : public SkillBase {
private:
	uint8_t diceAmount;
	SkillCommand* command;

public:
	Active();
	Active(std::string name, uint8_t tick, uint8_t diceAmount, SkillCommand* command);

	uint8_t GetDiceAmount() const;

	void SetDiceAmount(const uint8_t&);

public:
	void apply(Entity& caster, std::vector<Entity*> targets);
};

#endif