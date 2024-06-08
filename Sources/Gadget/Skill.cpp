#include "Skill.h"

Skill::Skill() : active(), passive(), buff() {}

void Skill::display() {
	std::cout << "Active: " << std::endl;
	for (auto& a : active) {
		std::cout << "  " << a.GetName() << std::endl;
	}
	std::cout << "Passive: " << std::endl;
	for (auto& p : passive) {
		std::cout << "  " << p.GetName() << std::endl;
	}
	std::cout << "Buff: " << std::endl;
	for (auto& b : buff) {
		std::cout << "  " << b.GetName() << std::endl;
	}
}

void Skill::pushActive(const Active& active) {
	this->active.push_back(active);
}

void Skill::pushPassive(const Passive& passive) {
	this->passive.push_back(passive);
}

void Skill::pushBuff(const Buff& buff) {
	this->buff.push_back(buff);
}

void Skill::SetActive(const std::vector<Active>& active) {
	this->active = active;
}

void Skill::SetPassive(const std::vector<Passive>& passive) {
	this->passive = passive;
}

void Skill::SetBuff(const std::vector<Buff>& buff) {
	this->buff = buff;
}

std::vector<Active> Skill::GetActive() const {
	return active;
}

std::vector<Passive> Skill::GetPassive() const {
	return passive;
}

std::vector<Buff> Skill::GetBuff() const {
	return buff;
}

Skill Skill::operator+=(const Skill& rhs) {
	for (auto& a : rhs.GetActive()) {
		active.push_back(a);
	}
	for (auto& p : rhs.GetPassive()) {
		passive.push_back(p);
	}
	for (auto& b : rhs.GetBuff()) {
		buff.push_back(b);
	}

	return *this;
}