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
	int16_t maxHP;     // Max HP
	int16_t maxFocus;  // Max Focus
	int16_t HP;        // HP
	int16_t focus;     // Focus
	int16_t SPD;       // Speed
	int16_t ACC;       // Hit Rate
	int16_t PA;        // Physical Attack
	int16_t MA;        // Magic Attack
	int16_t PD;        // Physical Defense
	int16_t MD;        // Magic Defense

public:
	// Construct all Attributes to 0
	Attribute();
	
	void SetMaxHP(const int16_t);
	void SetMaxFocus(const int16_t);
	void SetHP(const int16_t);
	void SetFocus(const int16_t);
	void SetSPD(const int16_t);
	void SetACC(const int16_t);
	void SetPA(const int16_t);
	void SetMA(const int16_t);
	void SetPD(const int16_t);
	void SetMD(const int16_t);

	int16_t GetMaxHP(void);
	int16_t GetMaxFocus(void);
	int16_t GetHP(void);
	int16_t GetFocus(void);
	int16_t GetSPD(void);
	int16_t GetACC(void);
	int16_t GetPA(void);
	int16_t GetMA(void);
	int16_t GetPD(void);
	int16_t GetMD(void);

public:
	// Random Attribute based on the Docs requirement.
	void randomAttribute(void);
	void display(void);
	Attribute operator+=(const Attribute&);
};

#endif