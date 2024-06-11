#include <SkillTable.h>
#include <ItemTable.h>
#include <Role.h>
#include <Enemy.h>
#include <Field.h>
#include <Attribute.h>
#include <KeyBoard.h>
#include <Color.h>
#include <Backpack.h>

#include <string>

int main() {
	SkillTable::Initialize();
	EquipmentTable::Initialize();
	ItemTable::Initialize();

	UI::checkConsoleSize(50, 180);
	UI::ShowMenu();
	//ui.makeChoice({"FUCKOOP","FUCK戴文凱","FUCK花凱隆"}, 50,20);

	system("Pause");
	system("CLS");

	Role hero("hero");
	Enemy dragon("dragon");

	Role profPao("鮑興國");
	Role myWife("砂狼白子我婆");
	Enemy porfDai("戴文凱");
	Enemy tonya("Tonya");
	// 新增物品到包包裡面
	profPao.addItemToBackpack("MagicWand");
	profPao.addItemToBackpack("MagicWand");
	profPao.addItemToBackpack("MagicWand");
	profPao.addItemToBackpack("WoodenSword");
	profPao.addItemToBackpack("Hammer");
	profPao.addItemToBackpack("WoodenShield");
	profPao.addItemToBackpack("PlateArmor");
	profPao.addItemToBackpack("HolyGrail");
	profPao.addItemToBackpack("Shoes");
	// 從包包裡使用物品 
	hero.backpack.useItem("MagicWand", hero);
	// 從包包裡使用物品(第二種實作方法
	profPao.GetAttribute().SetMaxFocus(20);
	profPao.GetAttribute().SetFocus(20);

	hero.useItemFromBackpack("MagicWand");
	hero.backpack.useItem("MagicWand", hero);
	// hero.backpack.useItem("MagicWand", hero);

	// profPao.useItemFromBackpack("WoodenSword");
	profPao.useItemFromBackpack("Hammer");
	profPao.useItemFromBackpack("PlateArmor");
	profPao.useItemFromBackpack("Shoes");
	myWife.equipForce("RitualSword");

	//system("Pause");
	profPao.equipForce("MagicWand");
	porfDai.renewPlayer();
	// porfDai.equipForce("MagicWand");
	dragon.equipForce("MagicWand");
	tonya.equipForce("RitualSword");

	//Process::HandlePreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });

	//UI::PreBattle({ &dragon, &porfDai, &tonya }, { &hero, &profPao, &myWife });
	UI::moveCursor(2, 9);

	Field battle({ &profPao }, { &porfDai });
	battle.StartBattle();

	/*
		std::vector<Entity*> targets;
		targets.push_back(&dragon);
		for (int i = 0; i < 2; i++) {
			auto skills = hero.GetTotalSkill().GetActive();
			std::string skillToUse = UI::makeChoice(skills, 6, 9).first;
			UI::logDivider(skillToUse);
			hero.useSkill(skillToUse, { &dragon });
		}

		UI::logDivider("");
		hero.GetDice().SetFocusCount(3);
		hero.useSkill("Attack", { &dragon });
		UI::logDivider("");
		hero.useSkill("Flee", { &hero });
		UI::logDivider("");
		hero.useSkill("ShockBlast", { &dragon });
		UI::logDivider("");
		hero.useSkill("Heal", { &hero });
		UI::logDivider("");
		hero.useSkill("Heal", { &dragon });
		UI::logDivider("");

		UI::logDivider("Equip WoodenSword");
		hero.equip("WoodenSword");
		hero.useSkill("SpeedUp", { &hero });

		UI::logDivider("Hero");
		hero.GetTotalAttribute();
		UI::logDivider("Dragon");
		dragon.GetTotalAttribute();


		UI::logDivider("Equip Equipment");
		hero.equip("GiantHammer");
		hero.equip("LaurelWreath");
		hero.equip("HolyGrail");

		//hero.GetTotalAttribute().display();
		//std::cout << std::endl;

		UI::logDivider("Apply Skill");
		//hero.GetTotalSkill().display();

		//重複定義
		//std::vector<Entity*> targets;
		//targets.push_back(&dragon);

		UI::logDivider("1");
		hero.useSkill("Attack", targets);
		UI::logDivider("2");
		hero.useSkill("Attack", targets);
		UI::logDivider("3");
		hero.useSkill("Attack", targets);
		UI::logDivider("4");
		hero.useSkill("Attack", targets);
		UI::logDivider("5");
		hero.useSkill("Attack", targets);
		UI::logDivider("6");
		hero.useSkill("Attack", targets);
		UI::logDivider("7");
		hero.useSkill("Attack", targets);
		UI::logDivider("8");
		hero.useSkill("Flee", targets);
		UI::logDivider("9");
		hero.useSkill("Heal", targets);
		UI::logDivider("10");
		//hero.useSkill("SpeedUp", targets);

		UI::logDivider("UnEquip Equipment");
		hero.unEquip(hero.GetEquipment().GetWeapon().GetName());
		hero.unEquip(hero.GetEquipment().GetArmor().GetName());
		hero.unEquip(hero.GetEquipment().GetAccessory().GetName());
		hero.useSkill("Attack", targets);
		hero.useSkill("Flee", targets);
		//hero.useSkill("Heal", targets);
		//hero.useSkill("SpeedUp", targets);
		UI::logDivider("Hero");
		//hero.GetTotalAttribute().display();
		UI::logDivider("Dragon");
		//dragon.GetTotalAttribute().display();
		//std::cout << std::endl;
		*/

	return 0;
}