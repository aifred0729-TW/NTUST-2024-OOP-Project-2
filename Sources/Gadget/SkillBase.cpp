#include <SkillBase.h>
#include <Entity.h>

SkillBase::SkillBase() : tick(0) {}
SkillBase::SkillBase(std::string name, uint8_t tick) : name(name), tick(tick) {}

std::string SkillBase::GetName() const {
	return name;
}

uint8_t SkillBase::GetTick() const {
	return tick;
}

uint8_t SkillBase::GetCoolDown() const {
	return coolDown;
}

void SkillBase::SetName(const std::string& name) {
	this->name = name;
}

void SkillBase::SetTick(const uint8_t& tick) {
	this->tick = tick;
}

void SkillBase::SetCoolDown(const uint8_t& coolDown) {
	this->coolDown = coolDown;
}

Buff::Buff() {}
Buff::Buff(std::string name, uint8_t tick) : SkillBase(name, tick) {}

Passive::Passive() {}
Passive::Passive(std::string name, uint8_t tick) : SkillBase(name, tick) {}

Active::Active() : diceAmount(0), command(nullptr) {}
Active::Active(std::string name, uint8_t cooldown, uint8_t diceAmount, SkillCommand* command)
	: SkillBase(name, cooldown), diceAmount(diceAmount), command(command) {}

Active::Active(std::string name, uint8_t cooldown, uint8_t diceAmount, SkillCommand* command, uint8_t targetType)
	: SkillBase(name , cooldown), diceAmount(diceAmount), command(command), targetType(targetType) {}

void Active::apply(Entity& caster, std::vector<Entity*> targets) {
	if (command) {
		command->execute(caster, targets, coolDown, tick, diceAmount);
	}
	else {
		std::cerr << "No command assigned to this skill!" << std::endl;
	}
}

uint8_t Active::GetDiceAmount() const {
	return diceAmount;
}

uint8_t Active::GetTargetType() const {
	return targetType;
}
void Active::SetDiceAmount(const uint8_t& diceAmount) {
	this->diceAmount = diceAmount;
}