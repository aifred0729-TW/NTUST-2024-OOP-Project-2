#include "../../Includes/Gadget/Attribute.h"

Attribute::Attribute(void) {
	this->maxHP = 0;
	this->maxFocus = 0;
	this->HP = 0;
	this->focus = 0;
	this->SPD = 0;
	this->ACC = 0;
	this->PA = 0;
	this->MA = 0;
	this->PD = 0;
	this->MD = 0;
}

void Attribute::randomAttribute(void) {
	// Random Engine
	std::random_device rd;
	std::mt19937 gen(rd());

	this->maxFocus = 3; // The initial value of focus is set to 3. 
	this->focus = this->maxFocus;

	// Random Attribute
	std::uniform_int_distribution<> hpDis(30, 44);
	std::uniform_int_distribution<> spdDis(30, 54);
	std::uniform_int_distribution<> accDis(40, 59);
	std::uniform_int_distribution<> attackDis(5, 15);
	std::uniform_int_distribution<> defenseDis(0, 20);

	this->maxHP = hpDis(gen);
	this->HP = this->maxHP;
	this->SPD = spdDis(gen);
	this->ACC = accDis(gen);
	this->PA = attackDis(gen);
	this->MA = attackDis(gen);
	this->PD = defenseDis(gen);
	this->MD = defenseDis(gen);
}

void Attribute::SetMaxHP(const int16_t maxHP) {
	this->maxHP = maxHP;
}

void Attribute::SetMaxFocus(const int16_t maxFocus) {
	this->maxFocus = maxFocus;
}

void Attribute::SetHP(const int16_t HP) {
	this->HP = HP;
}

void Attribute::SetFocus(const int16_t focus) {
	this->focus = focus;
}

void Attribute::SetSPD(const int16_t SPD) {
	this->SPD = SPD;
}

void Attribute::SetACC(const int16_t ACC) {
	this->ACC = ACC;
}

void Attribute::SetPA(const int16_t PA) {
	this->PA = PA;
}

void Attribute::SetMA(const int16_t MA) {
	this->MA = MA;
}

void Attribute::SetPD(const int16_t PD) {
	this->PD = PD;
}

void Attribute::SetMD(const int16_t MD) {
	this->MD = MD;
}

int16_t Attribute::GetMaxHP(void) {
	return this->maxHP;
}

int16_t Attribute::GetMaxFocus(void) {
	return this->maxFocus;
}

int16_t Attribute::GetHP(void) {
	return this->HP;
}

int16_t Attribute::GetFocus(void) {
	return this->focus;
}

int16_t Attribute::GetSPD(void) {
	return this->SPD;
}

int16_t Attribute::GetACC(void) {
	return this->ACC;
}

int16_t Attribute::GetPA(void) {
	return this->PA;
}

int16_t Attribute::GetMA(void) {
	return this->MA;
}

int16_t Attribute::GetPD(void) {
	return this->PD;
}

int16_t Attribute::GetMD(void) {
	return this->MD;
}