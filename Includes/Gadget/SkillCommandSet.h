#ifndef SKILLCOMMANDSET_H
#define SKILLCOMMANDSET_H

#include <vector> 
#include "SkillCommand.h"
#include "Entity.h"

class AttackCommand : public SkillCommand {
public:
    void execute(Entity& caster, std::vector<Entity*> target) override;
};

class WoodenSwordAttackCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class HammerAttackCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class GiantHammerAttackCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class MagicWandAttackCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class RitualSwordAttackCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class FleeCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class ProvokeCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class ShockBlastCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class HealCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

class SpeedUpCommand : public SkillCommand {
public:
	void execute(Entity& caster, std::vector<Entity*> target) override;
};

#endif
