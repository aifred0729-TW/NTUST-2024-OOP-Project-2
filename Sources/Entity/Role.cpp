#include "../../Includes/Entity/Role.h"

void Role::SetPack(const Item& pack) {
	this->pack = pack;
}
void Role::SetEquipment(const Equipment& equipment) {
	this->equipment = equipment;
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