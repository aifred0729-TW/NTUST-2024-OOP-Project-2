#ifndef SKILLCOMMANDSET_H
#define SKILLCOMMANDSET_H

#include <vector>
#include <iostream>

#include <SkillCommand.h>

class Entity;

class AttackActiveCommand : public SkillCommand {
public:
    void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class FleeActiveCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class ProvokeActiveCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class ShockBlastActiveCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class HealActiveCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

class SpeedUpActiveCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) override;
};

#endif
