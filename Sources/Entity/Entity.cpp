#include <Entity.h>
#include <Attribute.h>
#include <Skill.h>
#include <Dice.h>

// Public
Entity::Entity() {
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
    renewPlayer();
}

Entity::Entity(std::string name) : Entity() {
    this->name = name;
}

void Entity::useActive(std::string skillName, std::vector<Entity*> target) {
    for (auto& active : totalSkill.GetActive()) {
        if (active.GetName() == skillName) {
            active.SetTick(active.GetCoolDown());
            active.apply(*this, target);
            UI::renewPlayerInfo();
            return;
        }
    }
}

void Entity::takeDamage(int16_t damage, char attackType) {
    int16_t armor = attackType == 'P' ? totalAttribute.GetPD() : totalAttribute.GetMD();
    double absorption = armor / (double)(armor + 50);
    damage = static_cast<int16_t>((double)damage * (1 - absorption));
    int16_t damageTaken = totalAttribute.GetHP() - damage;
    totalAttribute.SetHP(damageTaken > 0 ? damageTaken : 0);
    attribute = totalAttribute;

    UI::logEvent(name + " 防禦後受到了 " + std::to_string(damage) + " 點傷害！，當前HP為 " + std::to_string(totalAttribute.GetHP()) + " !");
    UI::logEvent(std::to_string(totalAttribute.GetHP()) + "/" + std::to_string(totalAttribute.GetMaxHP()));
    if (totalAttribute.GetHP() == 0) {
        UI::logEvent( name + " is dead! 喔不!!" );
        status |= DEAD;
    }
}

void Entity::heal(int16_t heal) {
    int16_t healTaken = totalAttribute.GetHP() + heal;
    totalAttribute.SetHP(healTaken < totalAttribute.GetMaxHP() ? healTaken : totalAttribute.GetMaxHP());
    attribute = totalAttribute;

    std::string outputStr;
    std::stringstream outputSs;
    outputSs << name << " 受到了 " << heal << " 點治療！，當前HP為 " << totalAttribute.GetHP() << " !" << std::endl;
    std::getline(outputSs, outputStr);
    UI::logEvent(outputStr);
}

void Entity::renewPlayer(void) {
    totalAttribute = attribute;
    totalAttribute += equipment.GetArmor().GetAttribute();
    totalAttribute += equipment.GetWeapon().GetAttribute();
    totalAttribute += equipment.GetAccessory().GetAttribute();

    totalSkill = skill;
    totalSkill += equipment.GetArmor().GetSkill();
    totalSkill += equipment.GetWeapon().GetSkill();
    totalSkill += equipment.GetAccessory().GetSkill();
}

void Entity::equipForce(std::string equipmentName) {
    if (EquipmentTable::weaponMap.find(equipmentName) != EquipmentTable::weaponMap.end()) {
        this->equipment.SetWeapon(EquipmentTable::weaponMap[equipmentName]);
    } else if (EquipmentTable::armorMap.find(equipmentName) != EquipmentTable::armorMap.end()) {
        this->equipment.SetArmor(EquipmentTable::armorMap[equipmentName]);
    } else if (EquipmentTable::accessoryMap.find(equipmentName) != EquipmentTable::accessoryMap.end()) {
        this->equipment.SetAccessory(EquipmentTable::accessoryMap[equipmentName]);
    }
    renewPlayer();
}

void Entity::unEquipForce(std::string equipmentName) {
    if (this->GetEquipment().GetArmor().GetName() == equipmentName) {
        this->equipment.SetArmor(EquipmentTable::armorMap.find("BareBody")->second);
    } else if (this->GetEquipment().GetWeapon().GetName() == equipmentName) {
        this->equipment.SetWeapon(EquipmentTable::weaponMap.find("BareHand")->second);
    } else if (this->GetEquipment().GetAccessory().GetName() == equipmentName) {
        this->equipment.SetAccessory(EquipmentTable::accessoryMap.find("BareAccessory")->second);
    }
    renewPlayer();
}

bool Entity::isInRange(std::vector<Entity*>) {
    return 0;
}