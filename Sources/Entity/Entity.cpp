#include "../../Includes/Entity/Entity.h"

// Public
Entity::Entity() {
    faction = 1;
    attribute = Attribute();
    attribute.randomAttribute();
    equipment = Equipment();
    skill = Skill();
    Active Attack = SkillTable::activeMap.find("Attack")->second;
    Active Flee = SkillTable::activeMap.find("Flee")->second;
    skill.pushActive(Attack);
    skill.pushActive(Flee);
    this->dice = Dice();
    equipForce("BareHand");
    equipForce("BareBody");
    equipForce("BareAccessory");
    status = 0;
    eventID = 0;
    mode = ROLE;
}

Entity::Entity(std::string name) : Entity() {
    this->name = name;
}

void Entity::useActive(std::string skillName, std::vector<Entity*> target) {
    Skill combinedSkill = GetTotalSkill();
    for (auto active : combinedSkill.GetActive()) {
        if (active.GetName() == skillName) {
            active.apply(*this, target);
            UI::renewPlayerInfo();
            return;
        }
    }
    std::cerr << "Skill " << skillName << " not found in active skills!" << std::endl;
}

void Entity::takeDamage(int16_t damage, char attackType) {
    int16_t armor = attackType == 'P' ? GetTotalAttribute().GetPD() : GetTotalAttribute().GetMD();
    double absorption = armor / (double)(armor + 50);
    damage = static_cast<int16_t>((double)damage * (1 - absorption));
    int16_t damageTaken = GetTotalAttribute().GetHP() - damage;
    attribute.SetHP(damageTaken > 0 ? damageTaken : 0);

    std::string outputStr;
    std::stringstream outputSs;
    UI::logEvent(name + " 防禦後受到了 " + std::to_string(damage) + " 點傷害！，當前HP為 " + std::to_string(attribute.GetHP()) + " !");
    UI::logEvent(std::to_string(GetTotalAttribute().GetHP()) + "/" + std::to_string(GetTotalAttribute().GetMaxHP()));
    if (attribute.GetHP() == 0) {
        UI::logEvent(name + " is dead! 喔不!!");
        status |= DEAD;
    }
}

void Entity::heal(int16_t heal) {
    int16_t healTaken = GetTotalAttribute().GetHP() + heal;
    attribute.SetHP(healTaken < GetTotalAttribute().GetMaxHP() ? healTaken : GetTotalAttribute().GetMaxHP());
    std::string outputStr;
    std::stringstream outputSs;
    outputSs << name << " 受到了 " << heal << " 點治療！，當前HP為 " << attribute.GetHP() << " !" << std::endl;
    std::getline(outputSs, outputStr);
    UI::logEvent(outputStr);
}

void Entity::equipForce(std::string equipmentName) {
    if (EquipmentTable::weaponMap.find(equipmentName) != EquipmentTable::weaponMap.end()) {
        this->equipment.SetWeapon(EquipmentTable::weaponMap[equipmentName]);
        return;
    }
    else if (EquipmentTable::armorMap.find(equipmentName) != EquipmentTable::armorMap.end()) {
        this->equipment.SetArmor(EquipmentTable::armorMap[equipmentName]);
        return;
    }
    else if (EquipmentTable::accessoryMap.find(equipmentName) != EquipmentTable::accessoryMap.end()) {
        this->equipment.SetAccessory(EquipmentTable::accessoryMap[equipmentName]);
        return;
    }
    else {
        std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
    }
    UI::renewPlayerInfo();
}

void Entity::unEquipForce(std::string equipmentName) {
    if (this->GetEquipment().GetArmor().GetName() == equipmentName) {
        this->equipment.SetArmor(EquipmentTable::armorMap.find("BareBody")->second);
        return;
    }
    else if (this->GetEquipment().GetWeapon().GetName() == equipmentName) {
        this->equipment.SetWeapon(EquipmentTable::weaponMap.find("BareHand")->second);
        return;
    }
    else if (this->GetEquipment().GetAccessory().GetName() == equipmentName) {
        this->equipment.SetAccessory(EquipmentTable::accessoryMap.find("BareAccessory")->second);
        return;
    }
    else {
        std::cerr << "Equipment " << equipmentName << " not found!" << std::endl;
    }
}

Attribute Entity::GetTotalAttribute(void) {
    Attribute totalAttribute;
    totalAttribute += this->attribute;
    totalAttribute += equipment.GetTotalAttribute();
    return totalAttribute;
}

Skill Entity::GetTotalSkill(void) {
    Skill fuck;
    fuck += this->skill;
    fuck += equipment.GetTotalSkills();
    return fuck;
}

bool Entity::isInRange(std::vector<Entity*>) {
    return 0;
}

void Entity::SetName(const std::string& name) {
    this->name = name;
}

void Entity::SetAttribute(const Attribute& attribute) {
    this->attribute = attribute;
}

void Entity::SetSkill(const Skill& skill) {
    this->skill = skill;
}

void Entity::SetEquipment(const Equipment& equipment) {
    this->equipment = equipment;
}

void Entity::SetDice(const Dice& dice) {
    this->dice = dice;
}

void Entity::SetStatus(const uint8_t status) {
    this->status = status;
}

void Entity::SetEventID(const uint8_t eventID) {
    this->eventID = eventID;
}

void Entity::SetFaction(const bool faction) {
    this->faction = faction;
}

std::string Entity::GetName(void) {
    return name;
}

Attribute& Entity::GetAttribute(void) {
    return attribute;
}

Skill& Entity::GetSkill(void) {
    return skill;
}

Dice& Entity::GetDice(void) {
    return dice;
}

Equipment Entity::GetEquipment(void) {
    return equipment;
}

uint8_t   Entity::GetStatus(void) {
    return status;
}

uint8_t   Entity::GetEventID(void) {
    return eventID;
}

uint8_t   Entity::GetMode(void) {
    return mode;
}