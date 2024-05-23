#include "../../Includes/Gadget/Buff.h"

Buff::Buff() : name("") {}
Buff::Buff(std::string name) : name(name) {}

std::string Buff::GetName() const {
	return name;
}

void Buff::SetName(const std::string& name) {
	this->name = name;
}