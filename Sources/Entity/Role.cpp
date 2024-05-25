#include "Role.h"

Role::Role()
    : pack(), movementPoint(0), step(0), position({ 0, 0 }) {}

Role::Role(std::string name) {
    SetName(name);
    SetPack(Item());
    SetMovementPoint(0);
    SetStep(0);
    SetPosition({ 0, 0 });
}

void Role::SetPack(const Item& pack) {
    this->pack = pack;
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

Item Role::GetPack(void) {
    return pack;
}

uint8_t Role::GetMovementPoint(void) {
    return movementPoint;
}

uint32_t Role::GetStep(void) {
    return step;
}

std::pair<uint32_t, uint32_t> Role::GetPosition(void) {
    return position;
}
