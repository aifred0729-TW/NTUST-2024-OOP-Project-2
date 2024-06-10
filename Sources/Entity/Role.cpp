#include "../../Includes/Entity/Role.h"
#include <Entity.h>
#include "ItemTable.h"

#include "Entity.h"
#include "Backpack.h"
#include "Equipment.h"
#include "EquipmentTable.h"

Backpack Role::backpack;
uint16_t Role::money = 0;

Role::Role()
    : movementPoint(0), step(0), position({ 0, 0 }) {
}

Role::Role(std::string name) {
    SetName(name);
    SetMovementPoint(0);
    SetStep(0);
    SetPosition({ 0, 0 });
    SetFaction(0);
}

Role::Role(std::string name, int x, int y) {
    SetName(name);
    SetMovementPoint(0);
    SetStep(0);
    SetPosition({ x, y });
    SetFaction(0);
}

void Role::equip(const std::string& name) {
    if (EquipmentTable::weaponMap.find(name) != EquipmentTable::weaponMap.end()) {
        if (this->equipment.GetWeapon().GetName() != "BareHand")
            addItemToBackpack(equipment.GetWeapon().GetName());
        this->equipment.SetWeapon(EquipmentTable::weaponMap[name]);
        return;
    }
    else if (EquipmentTable::armorMap.find(name) != EquipmentTable::armorMap.end()) {
        if (this->equipment.GetArmor().GetName() != "BareBody")
            addItemToBackpack(equipment.GetArmor().GetName());
        this->equipment.SetArmor(EquipmentTable::armorMap[name]);
        return;
    }
    else if (EquipmentTable::accessoryMap.find(name) != EquipmentTable::accessoryMap.end()) {
        if (this->equipment.GetAccessory().GetName() != "BareAccessory")
            addItemToBackpack(equipment.GetAccessory().GetName());
        this->equipment.SetAccessory(EquipmentTable::accessoryMap[name]);
        return;
    }
    UI::renewPlayerInfo();
}

void Role::unEquip(const std::string& name) {
    if (this->GetEquipment().GetArmor().GetName() == name) {
        addItemToBackpack(equipment.GetArmor().GetName());
        this->equipment.SetArmor(EquipmentTable::armorMap.find("BareBody")->second);
        return;
    }
    else if (this->GetEquipment().GetWeapon().GetName() == name) {
        addItemToBackpack(equipment.GetWeapon().GetName());
        this->equipment.SetWeapon(EquipmentTable::weaponMap.find("BareHand")->second);
        return;
    }
    else if (this->GetEquipment().GetAccessory().GetName() == name) {
        addItemToBackpack(equipment.GetAccessory().GetName());
        this->equipment.SetAccessory(EquipmentTable::accessoryMap.find("BareAccessory")->second);
        return;
    }
    else {
        std::cerr << "Equipment " << name << " not found!" << std::endl;
    }
}

void Role::addItemToBackpack(const std::string& name) {
    Item* item = ItemTable::getItem(name);
    backpack.addItem(item);
}

void Role::useItemFromBackpack(const std::string& name) {
    backpack.useItem(name, *this);
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

void Role::SetMoney(const uint16_t money) {
    this->money = money;
}

uint8_t Role::GetMovementPoint(void) const {
    return movementPoint;
}

uint32_t Role::GetStep(void) const {
    return step;
}

std::pair<uint32_t, uint32_t> Role::GetPosition(void) const {
    return position;
}

uint16_t Role::GetMoney(void) const {
    return money;
}