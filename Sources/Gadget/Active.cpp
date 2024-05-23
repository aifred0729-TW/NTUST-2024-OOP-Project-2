#include "../../Includes/Gadget/Active.h"

Active::Active() : name(""), cooldown(0), diceAmount() {}
Active::Active(std::string name, uint8_t cooldown, uint8_t diceAmount) 
	: name(name), cooldown(cooldown), diceAmount(diceAmount) {}

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