#ifndef SKILL_H
#define SKILL_H

#include <cstdint>
#include <vector>
#include <functional>
#include "Dice.h"
#include "Active.h"
#include "Buff.h"
#include "Passive.h"
#include "ConstData.h"

class Entity;

class Skill {
private:
    std::vector<Active> active;
    std::vector<Passive> passive;
    std::vector<Buff> buff;

public:
    Skill();

	void SetActive(const std::vector<Active>&);
	void SetPassive(const std::vector<Passive>&);
	void SetBuff(const std::vector<Buff>&);

	std::vector<Active> GetActive() const;
	std::vector<Passive> GetPassive() const;
	std::vector<Buff> GetBuff() const;

public:
	void display();
	void pushActive(const Active&);
	void pushPassive(const Passive&);
	void pushBuff(const Buff&);
	Skill operator+=(const Skill&);
	std::function<void()> ApplySkill;
};

#endif
