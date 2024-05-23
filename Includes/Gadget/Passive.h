#ifndef PASSIVE_H
#define PASSIVE_H

#include "Dice.h"
#include "Attribute.h"

class Passive {
private:
	std::string name;
	uint8_t cooldown;

public:
	Passive();
	Passive(std::string name, uint8_t cooldown);

	std::string GetName() const;
	uint8_t GetCooldown() const;

	void SetName(const std::string&);
	void SetCooldown(const uint8_t&);
};


#endif