#ifndef BUFF_H
#define BUFF_H

#include "Dice.h"
#include "Attribute.h"

class Buff {
private:
	std::string name;

public:
	Buff();
	Buff(std::string);

	std::string GetName() const;
	void SetName(const std::string&);
};


#endif