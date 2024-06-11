#include <SkillBase.h>
#include <Entity.h>
#include <Attribute.h>
#include <iostream>
#include <string>

SkillBase::SkillBase() : tick(0), command(nullptr) {}
SkillBase::SkillBase(std::string name, SkillCommand* command, uint8_t targetType)
    : name(name), tick(0), command(command), targetType(targetType) {}

Buff::Buff() {}
Buff::Buff(std::string name, SkillCommand* command, SkillCommand* deStructCommand, uint8_t targetType)
    : SkillBase(name, command, targetType), deStructCommand(deStructCommand) {}

void Buff::apply(Entity& caster) {
	if (command) {
		command->execute(caster);
	}
}

void Buff::unApply(Entity& caster) {
	if (deStructCommand) {
		deStructCommand->execute(caster);
	}
}

Passive::Passive() : coolDown(0) {}
Passive::Passive(std::string name, uint8_t coolDown, SkillCommand* command, uint8_t targetType)
    : SkillBase(name, command, targetType), coolDown(coolDown) {}

void Passive::apply(Entity& caster, std::vector<Entity*> targets) {
	if (command) {
		command->execute(caster, targets);
	}
}

Active::Active() : diceAmount(0), coolDown(0) {}
Active::Active(std::string name, uint8_t coolDown, uint8_t diceAmount, SkillCommand* command, uint8_t targetType)
	: SkillBase(name, command, targetType), diceAmount(diceAmount), coolDown(coolDown) {}

void Active::apply(Entity& caster, std::vector<Entity*> targets) {
	if (command) {
		command->execute(caster, targets, coolDown, tick, diceAmount);
	}
}