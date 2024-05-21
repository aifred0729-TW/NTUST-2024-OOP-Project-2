#include "Includes/Entity/Role.h"
#include "Includes/Gadget/Equipment.h"

int main() {
    EquipmentTable::Initialize();

    Role hero;

    hero.Equip("Sword");
    std::cout << hero.GetAttribute().GetACC() << std::endl;
    Equipment equipped = hero.GetEquipment();
    std::cout << "Hero equipped item ID: " << static_cast<int>(equipped.GetID()) << std::endl;
    std::cout << "Hero equipped item quality: " << static_cast<int>(equipped.GetQuality()) << std::endl;
    std::cout << "Hero Attribute PA: " << static_cast<int>(equipped.GetAttribute().GetPA()) << std::endl;
    std::cout << "Hero Attribute SPD: " << static_cast<int>(equipped.GetAttribute().GetSPD()) << std::endl;

    return 0;
}
