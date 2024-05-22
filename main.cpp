#include "Includes/Entity/Role.h"
#include "Includes/Gadget/Equipment.h"

int main() {
    EquipmentTable::Initialize();

    Role hero;

    std::cout << "---------------Equip WoodenSword---------------" << std::endl;
    hero.EquipWeapon("WoodenSword");
    Equipment equipped = hero.GetEquipment();
    std::cout << "Additional Attribute PA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetPA()) << std::endl;
    std::cout << "Additional Attribute ACC: " << static_cast<int>(equipped.GetAdditionalAttribute().GetACC()) << std::endl;
    std::cout << "Additional Attribute MA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetMA()) << std::endl;
    std::cout << "Additional skills: "; 
    for (auto skill : equipped.GetAdditionalSkills()) {
		std::cout << skill.GetName() << " ";
	}
    std::cout << std::endl;

    std::cout << "---------------UnEquip WoodenSword---------------" << std::endl;
    hero.UnEquipWeapon();
    equipped = hero.GetEquipment();
    std::cout << "Additional Attribute PA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetPA()) << std::endl;
    std::cout << "Additional Attribute ACC: " << static_cast<int>(equipped.GetAdditionalAttribute().GetACC()) << std::endl;
    std::cout << "Additional Attribute MA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetMA()) << std::endl;
    std::cout << "Additional skills: ";
    for (auto skill : equipped.GetAdditionalSkills()) {
        std::cout << skill.GetName() << " ";
    }
    std::cout << std::endl;

    std::cout << "---------------Equip MagicWand---------------" << std::endl;
    hero.EquipWeapon("MagicWand");
    equipped = hero.GetEquipment();
    std::cout << "Additional Attribute PA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetPA()) << std::endl;
    std::cout << "Additional Attribute ACC: " << static_cast<int>(equipped.GetAdditionalAttribute().GetACC()) << std::endl;
    std::cout << "Additional Attribute MA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetMA()) << std::endl;
    std::cout << "Additional skills: ";
    for (auto skill : equipped.GetAdditionalSkills()) {
        std::cout << skill.GetName() << " ";
    }
    std::cout << std::endl;

    std::cout << "---------------Equip WoodenShield---------------" << std::endl;
    hero.EquipArmor("WoodenShield");
    equipped = hero.GetEquipment();
    std::cout << "Additional Attribute PA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetPA()) << std::endl;
    std::cout << "Additional Attribute ACC: " << static_cast<int>(equipped.GetAdditionalAttribute().GetACC()) << std::endl;
    std::cout << "Additional Attribute MA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetMA()) << std::endl;
    std::cout << "Additional Attribute PD: " << static_cast<int>(equipped.GetAdditionalAttribute().GetPD()) << std::endl;
    std::cout << "Additional skills: ";
    for (auto skill : equipped.GetAdditionalSkills()) {
        std::cout << skill.GetName() << " ";
    }
    std::cout << std::endl;

    std::cout << "---------------Equip HolyGrail---------------" << std::endl;
    hero.EquipAccessory("HolyGrail");
    equipped = hero.GetEquipment();
    std::cout << "Additional Attribute PA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetPA()) << std::endl;
    std::cout << "Additional Attribute ACC: " << static_cast<int>(equipped.GetAdditionalAttribute().GetACC()) << std::endl;
    std::cout << "Additional Attribute MA: " << static_cast<int>(equipped.GetAdditionalAttribute().GetMA()) << std::endl;
    std::cout << "Additional Attribute PD: " << static_cast<int>(equipped.GetAdditionalAttribute().GetPD()) << std::endl;
    std::cout << "Additional skills: ";
    for (auto skill : equipped.GetAdditionalSkills()) {
		std::cout << skill.GetName() << " ";
	}
    std::cout << std::endl;

    std::cout << "---------------Hero Total Attributes---------------" << std::endl;
    Attribute totalAttribute = hero.GetTotalAttribute();
    std::cout << "Total Attribute PA: " << static_cast<int>(totalAttribute.GetPA()) << std::endl;
    std::cout << "Total Attribute ACC: " << static_cast<int>(totalAttribute.GetACC()) << std::endl;
    std::cout << "Total Attribute MA: " << static_cast<int>(totalAttribute.GetMA()) << std::endl;
    std::cout << "Total Attribute PD: " << static_cast<int>(totalAttribute.GetPD()) << std::endl;
    std::cout << "Total skills: ";
    for (auto skill : hero.GetTotalSkills()) {
		std::cout << skill.GetName() << " ";
	}
    std::cout << std::endl;


    return 0;
}
