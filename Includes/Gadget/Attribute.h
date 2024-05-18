#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>
#include <random>

class Attribute {
private:
	uint8_t maxHP;     // Max HP
	uint8_t maxFocus;  // Max Focus
	uint8_t HP;        // HP
	uint8_t focus;     // Focus
	uint8_t SPD;       // Speed
	uint8_t ACC;       // Hit Rate
	uint8_t PA;        // Physical Attack
	uint8_t MA;        // Magic Attack
	uint8_t PD;        // Physical Defense
	uint8_t MD;        // Magic Defense

public:
	// Construct all Attributes to 0
	Attribute(void);
	
	void SetMaxHP(const uint8_t);
	void SetMaxFocus(const uint8_t);
	void SetHP(const uint8_t);
	void SetFocus(const uint8_t);
	void SetSPD(const uint8_t);
	void SetACC(const uint8_t);
	void SetPA(const uint8_t);
	void SetMA(const uint8_t);
	void SetPD(const uint8_t);
	void SetMD(const uint8_t);

	uint8_t GetMaxHP(void);
	uint8_t GetMaxFocus(void);
	uint8_t GetHP(void);
	uint8_t GetFocus(void);
	uint8_t GetSPD(void);
	uint8_t GetACC(void);
	uint8_t GetPA(void);
	uint8_t GetMA(void);
	uint8_t GetPD(void);
	uint8_t GetMD(void);

public:
	// Random Attribute based on the Docs requirement.
	void randomAttribute(void);
};

#endif