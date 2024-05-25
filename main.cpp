#include "Includes/Entity/Role.h"
#include "Includes/Entity/Enemy.h"
#include "Includes/Gadget/Equipment.h"
#include "Includes/Gadget/EquipmentTable.h"
#include "Includes/Gadget/SkillTable.h"

#include <string>

int main() {
	SkillTable::Initialize();
	EquipmentTable::Initialize();

	Role hero("hero");
	Enemy dragon("dragon");
	hero.equip("MagicWand");
	std::cout << "---------------Hero---------------" << std::endl;
	hero.GetTotalAttribute().display();
	std::cout << "---------------Dragon---------------" << std::endl;
	dragon.GetTotalAttribute().display();

	std::vector<Entity*> targets;
	targets.push_back(&dragon);
	std::cout << "----------------------------------" << std::endl;
	hero.useSkill("Attack", { &dragon });
	std::cout << "----------------------------------" << std::endl;
	hero.useSkill("Attack", { &dragon });
	std::cout << "----------------------------------" << std::endl;
	hero.useSkill("Flee", { &hero });
	std::cout << "----------------------------------" << std::endl;
	hero.useSkill("ShockBlast", { &dragon });
	std::cout << "----------------------------------" << std::endl;
	hero.useSkill("Heal", { &hero });
	std::cout << "----------------------------------" << std::endl;
	hero.useSkill("Heal", { &dragon });
	std::cout << "----------------------------------" << std::endl;

	std::cout << "---------------Equip WoodenSword---------------" << std::endl;
	hero.equip("WoodenSword");
	hero.useSkill("SpeedUp", { &hero });

	std::cout << "---------------Hero---------------" << std::endl;
	hero.GetTotalAttribute().display();
	std::cout << "---------------Dragon---------------" << std::endl;
	dragon.GetTotalAttribute().display();

	
	/*
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
	hero.useSkill("Attack", targets);
	hero.useSkill("Attack", targets);
	hero.useSkill("Attack", targets);
	hero.useSkill("Attack", targets);
	hero.useSkill("Attack", targets);
	hero.useSkill("Attack", targets);
	hero.useSkill("Flee", targets);
	hero.useSkill("Heal", targets);
	hero.useSkill("SpeedUp", targets);
	std::cout << std::endl;

	std::cout << "---------------UnEquip Equipment---------------" << std::endl;
	hero.unEquip(hero.GetEquipment().GetWeapon().GetName());
	hero.unEquip(hero.GetEquipment().GetArmor().GetName());
	hero.unEquip(hero.GetEquipment().GetAccessory().GetName());
	hero.useSkill("Attack", targets);
	hero.useSkill("Flee", targets);
	hero.useSkill("Heal", targets);
	hero.useSkill("SpeedUp", targets);
	std::cout << "---------------Hero---------------" << std::endl;
	hero.GetTotalAttribute().display();
	std::cout << "---------------Dragon---------------" << std::endl;
	dragon.GetTotalAttribute().display();
	std::cout << std::endl;
	*/

	return 0;
}
