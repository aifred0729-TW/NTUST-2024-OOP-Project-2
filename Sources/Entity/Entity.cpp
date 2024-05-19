#include "../../Includes/Entity/Entity.h"

// Public

bool Entity::isInRange(std::vector<Entity*>) {
    return 0;
}

void Entity::SetAttribute(const Attribute& attribute) {
    this->attribute.maxHP = attribute.maxHP;
    this->attribute.maxFocus = attribute.maxFocus;
    this->attribute.HP = attribute.HP;
    this->attribute.focus = attribute.focus;
    this->attribute.SPD = attribute.SPD;
    this->attribute.ACC = attribute.ACC;
    this->attribute.PA = attribute.PA;
    this->attribute.MA = attribute.MA;
    this->attribute.PD = attribute.PD;
    this->attribute.MD = attribute.MD;
}
void Entity::SetSkill(const Skill& skill) {
    this->skill.skillID = skill.skillID;
    this->skill.coolDownTime = skill.coolDownTime;
    this->skill.dice.amount = skill.dice.amount;
    this->skill.dice.movementPoint = skill.dice.movementPoint;
    this->skill.dice.focusCount = skill.dice.focusCount;
    this->skill.dice.successRate = skill.dice.successRate;
    this->skill.dice.rateAddition = skill.dice.rateAddition;
    this->skill.dice.result = skill.dice.result;
    this->skill.skillUser = skill.skillUser;
    this->skill.skillTargets = skill.skillTargets;
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
void Entity::SetWeaponID(const uint8_t weaponID) {
    this->weaponID = weaponID;
}
void Entity::SetArmorID(const uint8_t armorID) {
    this->armorID = armorID;
}
void Entity::SetAccessoryID(const uint8_t accessoryID) {
    this->accessoryID = accessoryID;
}

Attribute Entity::GetAttribute(void) {
    return attribute;
}
Skill     Entity::GetSkill(void) {
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
uint8_t   Entity::GetWeaponID(void) {
    return weaponID;
}
uint8_t   Entity::GetArmorID(void) {
    return armorID;
}
uint8_t   Entity::GetAccessoryID(void) {
    return accessoryID;
}