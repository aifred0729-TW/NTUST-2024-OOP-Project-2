#include "Includes/Entity/Role.h"
#include "Includes/Gadget/Equipment.h"

int main() {
    EquipmentTable::Initialize();

    Role hero;
    hero.GetTotalAttribute().display();
    for (auto skill : hero.GetTotalSkills()) {
        std::cout << skill.GetName() << " ";
    }
    std::cout << std::endl;

    std::cout << "---------------Equip Equipment---------------" << std::endl;
    hero.EquipWeapon("MagicWand");
    hero.EquipArmor("WoodenShield");
    hero.EquipAccessory("HolyGrail");

    hero.GetTotalAttribute().display();
    for (auto skill : hero.GetTotalSkills()) {
        std::cout << skill.GetName() << " ";
    }
    std::cout << std::endl;

    std::cout << "---------------UnEquip Equipment---------------" << std::endl;
    hero.UnEquipWeapon();
    hero.UnEquipArmor();
    hero.UnEquipAccessory();

    hero.GetTotalAttribute().display();
    for (auto skill : hero.GetTotalSkills()) {
        std::cout << skill.GetName() << " ";
    }
    std::cout << std::endl;

    return 0;
}
