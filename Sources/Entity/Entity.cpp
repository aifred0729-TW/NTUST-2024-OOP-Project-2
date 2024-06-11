#include <Entity.h>
#include <Attribute.h>
#include <Skill.h>
#include <Dice.h>

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
    lastDamage = 0;
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

void Entity::usePassive(std::string skillName, std::vector<Entity*> target) {
    for (auto& passive : totalSkill.GetPassive()) {
        if (passive.GetName() == skillName) {
            passive.SetTick(passive.GetCoolDown());
            passive.apply(*this, target);
            UI::renewPlayerInfo();
            return;
        }
    }
}

void Entity::useBuff(std::string skillName) {
    for (auto& buff : totalSkill.GetBuff()) {
        if (buff.GetName() == skillName) {
            buff.apply(*this);
            UI::renewPlayerInfo();
            return;
        }
    }
}

void Entity::addBuff(std::string skillName, uint8_t round) {
    int index = 0;
    for (index = 0; index < totalSkill.GetBuff().size(); index++) {
        if (totalSkill.GetBuff()[index].GetName() == skillName)
            break;
    }

    if (index == totalSkill.GetBuff().size()) {
        Buff buff = SkillTable::buffMap.find(skillName)->second;
        buff.SetTick(round);
        totalSkill.pushBuff(buff);
        UI::logEvent(name + " 身上新增了將持續 " + std::to_string(buff.GetTick()) + " 回合的 " + skillName + "。");
        useBuff(skillName);
    } else {
        totalSkill.GetBuff()[index].SetTick(round);
        UI::logEvent(name + " 的 " + skillName + " 重製為 " + std::to_string(totalSkill.GetBuff()[index].GetTick()) + " 回合。");
    }
    UI::logEvent("");
}

void Entity::removeBuff(std::string skillName) {
    for (int i = 0; i < totalSkill.GetBuff().size(); i++) {
        if (totalSkill.GetBuff()[i].GetName() == skillName) {
            totalSkill.GetBuff()[i].unApply(*this);
            totalSkill.GetBuff().erase(totalSkill.GetBuff().begin() + i);
            UI::logEvent(name + " 的 " + skillName + " 被移除了。");
            UI::logEvent("");
            return;
        }
    }
}

void Entity::takeDamage(int16_t damage, char attackType) {
    int16_t armor = attackType == 'P' ? totalAttribute.GetPD() : totalAttribute.GetMD();
    double absorption = armor / (double)(armor + 50);
    damage = static_cast<int16_t>((double)damage * (1 - absorption));

    if (findAvailablePassive("Fortify") && damage != 0) {
        usePassive("Fortify", { &(*this) });
        damage = static_cast<int16_t>(damage * 0.9);
    }

    lastDamage = damage;
    int16_t damageTaken = totalAttribute.GetHP() - damage;
    totalAttribute.SetHP(damageTaken > 0 ? damageTaken : 0);
    attribute.SetHP(totalAttribute.GetHP());

    UI::logEvent(name + " 防禦後受到了 " + std::to_string(damage) + " 點傷害！當前HP為 " + std::to_string(totalAttribute.GetHP()) + " !");
    if (totalAttribute.GetHP() == 0) {
        UI::logEvent(name + " 被幹死了！喔不！！");
        UI::logEvent("");
        status |= DEAD;
    }
}

void Entity::takeTrueDamage(int16_t damage) {
    int16_t damageTaken = totalAttribute.GetHP() - damage;
    totalAttribute.SetHP(damageTaken > 0 ? damageTaken : 0);
    attribute.SetHP(totalAttribute.GetHP());

    UI::logEvent(name + " 受到了 " + std::to_string(damage) + " 點真實傷害！當前HP為 " + std::to_string(totalAttribute.GetHP()) + " !");
    if (totalAttribute.GetHP() == 0) {
        UI::logEvent(name + " 被幹死了！喔不！！");
        UI::logEvent("");
        status |= DEAD;
    }
}

void Entity::heal(int16_t heal) {
    int16_t healTaken = totalAttribute.GetHP() + heal;
    totalAttribute.SetHP(healTaken < totalAttribute.GetMaxHP() ? healTaken : totalAttribute.GetMaxHP());
    attribute.SetHP(totalAttribute.GetHP());

    std::string outputStr;
    std::stringstream outputSs;
    outputSs << name << " 受到了 " << heal << " 點治療！當前HP為 " << totalAttribute.GetHP() << " !" << std::endl;
    std::getline(outputSs, outputStr);
    UI::logEvent(outputStr);
    UI::logEvent("");
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

void Entity::decreaseTick(void) {
    for (auto& active : totalSkill.GetActive()) {
        if (active.GetTick() > 0) {
            active.SetTick(active.GetTick() - 1);
        }
    }

    for (auto& passive : totalSkill.GetPassive()) {
        if (passive.GetTick() > 0) {
            passive.SetTick(passive.GetTick() - 1);
        }
    }

    for (int i = 0; i < totalSkill.GetBuff().size(); i++) {
        if (totalSkill.GetBuff()[i].GetTick() > 1) {
            totalSkill.GetBuff()[i].SetTick(totalSkill.GetBuff()[i].GetTick() - 1);
        } else if (totalSkill.GetBuff()[i].GetTick() == 1) {
            UI::logDivider(name + " 狀態更新");
            removeBuff(totalSkill.GetBuff()[i].GetName());
            i--;
        }
    }
}

bool Entity::findAvailablePassive(std::string skillName) {
    for (auto& passive : totalSkill.GetPassive()) {
        if (passive.GetName() == skillName && passive.GetTick() == 0) {
            return true;
        }
    }
    return false;
}

bool Entity::findAvailableBuff(std::string skillName) {
    for (auto& buff : totalSkill.GetBuff()) {
        if (buff.GetName() == skillName && buff.GetTick() != 0) {
            return true;
        }
    }
    return false;
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

void Entity::displayTotalSkill() {
    UI::logDivider(name + " 技能顯示");
    UI::logEvent("主動技能: ");
    for (auto& active : totalSkill.GetActive()) {
        if (active.GetTick() == 0)
			UI::logEvent("\t" + active.GetName() + " 可以使用");
		else
            UI::logEvent("\t" + active.GetName() + " 還剩 " + std::to_string(active.GetTick()) + " 回合冷卻");
    }
    UI::logEvent("被動技能: ");
    for (auto& passive : totalSkill.GetPassive()) {
        if (passive.GetTick() == 0)
            UI::logEvent("\t" + passive.GetName() + " 蓄勢待發");
        else
		    UI::logEvent("\t" + passive.GetName() + " 還剩 " + std::to_string(passive.GetTick()) + " 回合冷卻");
	}
    UI::logEvent("各種 Buff: ");
    for (auto& buff : totalSkill.GetBuff()) {
		UI::logEvent("\t" + buff.GetName() + " 持續時間 " + std::to_string(buff.GetTick()) + " 回合");
	}
    UI::logEvent("");
}

void Entity::clearBuff() {
    totalSkill.SetBuff(std::vector<Buff>());
}