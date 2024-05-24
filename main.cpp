#include "Includes/Entity/Role.h"
#include "Includes/Gadget/Equipment.h"
#include "Includes/Gadget/EquipmentTable.h"
#include "Includes/Gadget/SkillTable.h"

int main() {
	SkillTable::Initialize();
	EquipmentTable::Initialize();

	Entity hero;
	Entity dragon;
	std::cout << "---------------Hero---------------" << std::endl;
	hero.GetTotalAttribute().display();
	std::cout << "---------------Dragon---------------" << std::endl;
	dragon.GetTotalAttribute().display();
	std::cout << std::endl;

	std::cout << "---------------Equip Equipment---------------" << std::endl;
	hero.equip("GiantHammer");
	hero.equip("LaurelWreath");
	hero.equip("HolyGrail");
	hero.GetTotalAttribute().display();
	std::cout << std::endl;

	std::cout << "---------------Apply Skill---------------" << std::endl;
	hero.GetTotalSkill().display();
	std::vector<Entity*> targets;
	targets.push_back(&dragon);
	hero.useSkill("Attack", targets);
	hero.useSkill("Flee", targets);
	hero.useSkill("Heal", targets);
	hero.useSkill("SpeedUp", targets);
	hero.useSkill("GiantHammerAttack", targets);
	std::cout << std::endl;

	std::cout << "---------------UnEquip Equipment---------------" << std::endl;
	hero.unEquip(hero.GetEquipment().GetWeapon().GetName());
	hero.unEquip(hero.GetEquipment().GetArmor().GetName());
	hero.unEquip(hero.GetEquipment().GetAccessory().GetName());
	std::cout << "---------------Hero---------------" << std::endl;
	hero.GetTotalAttribute().display();
	std::cout << "---------------Dragon---------------" << std::endl;
	dragon.GetTotalAttribute().display();
	std::cout << std::endl;

	return 0;
}
