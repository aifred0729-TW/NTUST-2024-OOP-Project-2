#ifndef ACTIVE_H
#define ACTIVE_H

#include "Dice.h"
#include "Attribute.h"

class Active {
private:
	std::string name;
	uint8_t cooldown;
	uint8_t diceAmount;

public:
	Active();
	Active(std::string name, uint8_t cooldown, uint8_t diceAmount);

	std::string GetName() const;
	uint8_t GetCooldown() const;
	uint8_t GetDiceAmount() const;

	void SetName(const std::string&);
	void SetCooldown(const uint8_t&);
	void SetDiceAmount(const uint8_t&);

public:
	// void apply(Entity&, std::vector<Entity>&);
};

#endif