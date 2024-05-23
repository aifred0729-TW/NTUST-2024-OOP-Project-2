#include "Includes/Entity/Role.h"
#include "Includes/Gadget/Equipment.h"
#include "Includes/Gadget/EquipmentTable.h"
#include "Includes/Gadget/SkillTable.h"

int main() {
	SkillTable::Initialize();
	EquipmentTable::Initialize();

	Role hero;
	Role dragon;
	std::cout << "---------------Hero---------------" << std::endl;
	hero.GetTotalAttribute().display();
	std::cout << "---------------Dragon---------------" << std::endl;
	dragon.GetTotalAttribute().display();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------------Equip Equipment---------------" << std::endl;
	hero.EquipWeapon("GiantHammer");
	hero.EquipArmor("LaurelWreath");
	hero.EquipAccessory("HolyGrail");
	hero.GetTotalAttribute().display();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------------Apply Skill---------------" << std::endl;
	// hero.GetTotalSkill().display();
	/*
	for (auto active : hero.GetTotalSkill().GetActive()) {
		std::cout << "  " << active.GetName() << std::endl;
	}
	*/
	// hero.ApplyActive("WoodenSwordAttack", dragon);
	std::cout << std::endl;

	std::cout << "---------------UnEquip Equipment---------------" << std::endl;
	hero.UnEquipWeapon();
	hero.UnEquipArmor();
	hero.UnEquipAccessory();
	hero.GetTotalAttribute().display();
	std::cout << std::endl;

	return 0;
}
