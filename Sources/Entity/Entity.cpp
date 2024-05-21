#include "../../Includes/Entity/Entity.h"

// Public

bool Entity::isInRange(std::vector<Entity*>) {
    return 0;
}

void Entity::SetAttribute(const Attribute& attribute) {

    this->attribute = attribute;
}
void Entity::SetSkill(const Skill& skill) {
    this->skill = skill;
}
void Entity::SetHP(const uint32_t HP) {
    this->HP = HP;
}
void Entity::SetStatus(const uint8_t status) {
    this->status = status;
}
void Entity::SetEventID(const uint8_t eventID) {
    this->eventID = eventID;
}

void Entity::SetWeapon(const Equipment& weapon) {
    this->weapon = weapon;
}
void Entity::SetArmor(const Equipment& armor) {
    this->armor = armor;
}
void Entity::SetAccessory(const Equipment& accessory) {
    this->accessory = accessory;
}

Attribute& Entity::GetAttribute(void) {
    return attribute;
}
Skill&    Entity::GetSkill(void) {
    return skill;
}
uint32_t  Entity::GetHP(void) {
    return HP;
}
uint8_t   Entity::GetStatus(void) {
    return status;
}
uint8_t   Entity::GetEventID(void) {
    return eventID;
}

Equipment& Entity::GetWeapon(void) {
    return weapon;
}
Equipment& Entity::GetArmor(void) {
    return armor;
}
Equipment& Entity::GetAccessory(void) {
    return accessory;
}