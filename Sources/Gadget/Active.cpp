#include "../../Includes/Gadget/Active.h"

Active::Active() : name(""), cooldown(0), diceAmount(0), command(nullptr) {}

Active::Active(std::string name, uint8_t cooldown, uint8_t diceAmount, SkillCommand* command)
	: name(name), cooldown(cooldown), diceAmount(diceAmount), command(command) {}

Active::Active(std::string name, uint8_t cooldown, uint8_t diceAmount, SkillCommand* command , uint8_t targetType)
	: name(name), cooldown(cooldown), diceAmount(diceAmount), command(command) ,targetType(targetType) {}

void Active::apply(Entity& caster, std::vector<Entity*> targets) {
	if (command) {
		command->execute(caster, targets);
	} else {
		std::cerr << "No command assigned to this skill!" << std::endl;
	}
}

std::string Active::GetName() const {
	return name;
}

uint8_t Active::GetCooldown() const {
	return cooldown;
}

uint8_t Active::GetDiceAmount() const {
	return diceAmount;
}

void Active::SetName(const std::string& name) {
	this->name = name;
}

void Active::SetCooldown(const uint8_t& cooldown) {
	this->cooldown = cooldown;
}

void Active::SetDiceAmount(const uint8_t& diceAmount) {
	this->diceAmount = diceAmount;
}