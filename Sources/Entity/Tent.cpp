#include "Tent.h"
#include "Attribute.h"
#include "Role.h"

Tent::Tent(std::string name, std::pair<uint32_t, uint32_t> position) {
    this->name = name;
    this->position = position;
}

Tent::Tent(std::string name, uint32_t x, uint32_t y) {
    this->name = name;
    this->position = { x,y };
}

std::pair<uint32_t, uint32_t> Tent::GetPosition(void) const {
    return position;
}

std::string Tent::GetName(void) const {
    return name;
}

void Tent::SetTent(Role* player) {
    position = player->GetPosition();
}

void Tent::Recover(Role* player) {
    Attribute attribute;
    int16_t HP, maxHP, focus, maxFocus;
    attribute = player->GetTotalAttribute();
    HP = attribute.GetHP();
    maxHP = attribute.GetMaxHP();
    focus = attribute.GetFocus();
    maxFocus = attribute.GetMaxFocus();
    if (HP + 50 <= maxHP) HP += 50;
    else HP = maxHP;
    if (focus + 5 <= maxFocus) focus += 5;
    else focus = maxFocus;
    attribute.SetHP(HP);
    attribute.SetFocus(focus);
    player->SetAttribute(attribute);
}