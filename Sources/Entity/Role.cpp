#include "../../Includes/Entity/Role.h"

void Role::SetPack(const Item& pack) {
	this->pack.items = pack.items;
	this->pack.packUsers = pack.packUsers;
}
void Role::SetEquipment(const Equipment& equipment) {
	this->equipment.attribute.maxHP = equipment.attribute.maxHP;
	this->equipment.attribute.maxFocus = equipment.attribute.maxFocus;
	this->equipment.attribute.HP = equipment.attribute.HP;
	this->equipment.attribute.focus = equipment.attribute.focus;
	this->equipment.attribute.SPD = equipment.attribute.SPD;
	this->equipment.attribute.ACC = equipment.attribute.ACC;
	this->equipment.attribute.PA = equipment.attribute.PA;
	this->equipment.attribute.MA = equipment.attribute.MA;
	this->equipment.attribute.PD = equipment.attribute.PD;
	this->equipment.attribute.MD = equipment.attribute.MD;
	this->equipment.skill.skillID = equipment.skill.skillID;
	this->equipment.skill.coolDownTime = equipment.skill.coolDownTime;
	this->equipment.skill.dice.amount = equipment.skill.dice.amount;
	this->equipment.skill.dice.movementPoint = equipment.skill.dice.movementPoint;
	this->equipment.skill.dice.focusCount = equipment.skill.dice.focusCount;
	this->equipment.skill.dice.successRate = equipment.skill.dice.successRate;
	this->equipment.skill.dice.rateAddition = equipment.skill.dice.rateAddition;
	this->equipment.skill.dice.result = equipment.skill.dice.result;
	this->skill.skillUser = skill.skillUser;
	this->skill.skillTargets = skill.skillTargets;
	this->equipment.quality = equipment.quality;
}
void Role::SetMovementPoint(const uint8_t movementPoint) {
	this->movementPoint = movementPoint;
}
void Role::SetStep(const uint32_t step) {
	this->step = step;
}
void Role::SetPosition(const std::pair<uint32_t, uint32_t>& position) {
	this->position = position;
}

Item      Role::GetPack(void) {
	return pack;
}
Equipment Role::GetEquipment(void) {
	return equipment;
}
uint8_t   Role::GetMovementPoint(void) {
	return movementPoint;
}
uint32_t  Role::GetStep(void) {
	return step;
}
std::pair<uint32_t, uint32_t> Role::GetPosition(void) {
	return position;
}