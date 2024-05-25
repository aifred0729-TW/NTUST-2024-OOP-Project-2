#include "../../Includes/Gadget/Passive.h"

Passive::Passive() : name(""), cooldown(0) {}
Passive::Passive(std::string name, uint8_t cooldown)
	: name(name), cooldown(cooldown) {}

std::string Passive::GetName() const {
	return name;
}

uint8_t Passive::GetCooldown() const {
	return cooldown;
}

void Passive::SetName(const std::string& name) {
	this->name = name;
}

void Passive::SetCooldown(const uint8_t& cooldown) {
	this->cooldown = cooldown;
}