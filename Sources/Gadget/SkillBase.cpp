#include <SkillBase.h>
#include <Entity.h>

SkillBase::SkillBase() : tick(0), command(nullptr) {}
SkillBase::SkillBase(std::string name, SkillCommand* command, uint8_t targetType)
    : name(name), tick(0), command(command), targetType(targetType) {}

Buff::Buff() {}
Buff::Buff(std::string name, SkillCommand* command, uint8_t targetType)
    : SkillBase(name, command, targetType) {}

Passive::Passive() : coolDown(0) {}
Passive::Passive(std::string name, uint8_t coolDown, SkillCommand* command, uint8_t targetType)
    : SkillBase(name, command, targetType), coolDown(coolDown) {}

Active::Active() : diceAmount(0), coolDown(0) {}
Active::Active(std::string name, uint8_t coolDown, uint8_t diceAmount, SkillCommand* command, uint8_t targetType)
	: SkillBase(name, command, targetType), diceAmount(diceAmount), coolDown(coolDown) {}

void Active::apply(Entity& caster, std::vector<Entity*> targets) {
	if (command) {
		command->execute(caster, targets, coolDown, tick, diceAmount);
	} else {
		std::cerr << "No command assigned to this skill!" << std::endl;
	}
}