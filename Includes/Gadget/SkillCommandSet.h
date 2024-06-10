#ifndef SKILLCOMMANDSET_H
#define SKILLCOMMANDSET_H

#include <vector>
#include <iostream>

#include <SkillCommand.h>

class Entity;

class AttackCommand : public SkillCommand {
public:
    void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class FleeCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class ProvokeCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class ShockBlastCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class HealCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class SpeedUpCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

#endif
