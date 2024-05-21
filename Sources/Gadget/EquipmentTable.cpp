#include "EquipmentTable.h"

std::map<std::string, Equipment> EquipmentTable::equipmentMap;

void EquipmentTable::Initialize() {
    Attribute swordAttribute;
    swordAttribute.SetPA(10);
    swordAttribute.SetSPD(5);

    std::vector<Skill> swordSkills;

    Equipment sword(1, swordAttribute, swordSkills, 5);

    equipmentMap["Sword"] = sword;

    // Add other equipments similarly
    // ...
}
