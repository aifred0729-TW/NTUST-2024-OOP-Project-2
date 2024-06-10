#include "Includes/Entity/Role.h"
#include "Includes/Entity/Enemy.h"
#include "Includes/Gadget/Equipment.h"
#include "Includes/Gadget/EquipmentTable.h"
#include "Includes/Gadget/SkillTable.h"
#include "Includes/Display/UI.h"
#include "Field.h"
#include <Color.h>
#include <WorldMap.h>
#include "ItemTable.h"

#include <Process.h>
#include <Game.h>

#include <string>

int main() {
	Game G;
	G.MainProcess();

    UI::checkConsoleSize(50, 180);
    //UI::ShowMenu();
    //ui.makeChoice({"FUCKOOP","FUCK戴文凱","FUCK花凱隆"}, 50,20);

    //system("Pause");
    system("CLS");
	Role hero("hero");
	Enemy dragon("dragon");

	Role profPao("鮑興國");
	Role myWife("砂狼白子我婆");
	Enemy porfDai("戴文凱");
	Enemy tonya("Tonya");
	// 新增物品到包包裡面
	profPao.addItemToBackpack("MagicWand");
	profPao.addItemToBackpack("Hammer");
	// 從包包裡使用物品 
	hero.backpack.useItem("MagicWand", hero);
	// 從包包裡使用物品(第二種實作方法
	hero.useItemFromBackpack("MagicWand");
	hero.backpack.useItem("Hammer", hero);
	hero.backpack.useItem("MagicWand", hero);

	profPao.equipForce("Hammer");
	myWife.equipForce("RitualSword");

	profPao.GetAttribute().SetMaxFocus(20);
	profPao.GetAttribute().SetFocus(20);



	//Process::HandlePreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });

    WorldMap::SetEnemys({ &dragon ,&porfDai ,&tonya });
    WorldMap::SetRoles({ &hero ,&profPao ,&myWife });
    //system("Pause");


    //Process::HandlePreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });

    //UI::PreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });
    UI::moveCursor(2, 9);


    Field battle({ &hero ,&profPao , &myWife }, { &porfDai  , &tonya  ,&dragon });
    //battle.StartBattle();

    WorldMap::loadMap("W-1.txt");
    UI::PreWorldMap({ &hero ,&profPao , &myWife });
    /*
    std::cout << BG_BRIGHT_CYAN;
    UI::distanceDisplay(0, 0, 0);
    */
    UI::moveCursor(0, 0);
    Process::worldMapViewSimulator();

    UI::moveCursor(5, 1);
    return 0;
}
