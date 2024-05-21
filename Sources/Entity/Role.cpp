#include "Role.h"

Role::Role()
    : pack(), equipment(), movementPoint(0), step(0), position({ 0, 0 }) {}

void Role::Equip(const std::string& equipmentName) {
    auto it = EquipmentTable::equipmentMap.find(equipmentName);
    if (it != EquipmentTable::equipmentMap.end()) {
        this->SetEquipment(it->second);
    } else {
        std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
    }
}

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

Item Role::GetPack(void) {
    return pack;
}

Equipment Role::GetEquipment(void) {
    return equipment;
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
