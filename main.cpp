#include "Includes/Entity/Role.h"
#include "Includes/Entity/Enemy.h"
#include "Includes/Gadget/Equipment.h"
#include "Includes/Gadget/EquipmentTable.h"
#include "Includes/Gadget/SkillTable.h"
#include "Includes/Display/UI.h"
#include "Backpack.h"
#include "Field.h"
#include <Color.h>
#include <WorldMap.h>
#include "ItemTable.h"
#include <Store.h>

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

    Role Kazusa("杏山千紗", 1, 1);
    Role Shiroko("砂狼白子", 3, 1);
    Role Hoshino("小鳥游星野", 5, 1);

    Enemy fat_tonya("胖子 - Tonya", 1, 3);
    Enemy troll_tonya("巨魔 - Tonya", 3, 3);
    Enemy boomer_tonya("胖子炸彈 - Tonya", 5, 3);

    Store shop1("RB-509 碼田", 1, 5);
    // 新增物品到包包裡面
    Kazusa.addItemToBackpack("MagicWand");
    Kazusa.addItemToBackpack("Hammer");
    // 從包包裡使用物品 
    Shiroko.backpack.useItem("MagicWand", Shiroko);
    // 從包包裡使用物品(第二種實作方法
    Shiroko.useItemFromBackpack("MagicWand");
    Shiroko.backpack.useItem("Hammer", Shiroko);
    Shiroko.backpack.useItem("MagicWand", Shiroko);

    Kazusa.equipForce("Hammer");
    Hoshino.equipForce("RitualSword");

    Kazusa.GetAttribute().SetMaxFocus(20);
    Kazusa.GetAttribute().SetFocus(20);

    //Process::HandlePreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });

    WorldMap::SetRoles({ &Kazusa ,&Shiroko ,&Hoshino });
    WorldMap::SetEnemys({ &fat_tonya ,&troll_tonya ,&boomer_tonya });
    WorldMap::SetStores({ &shop1 });
    //system("Pause");


    //Process::HandlePreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });

    //UI::PreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });
    UI::moveCursor(2, 9);


    Field battle({ &Kazusa ,&Shiroko ,&Hoshino }, { &fat_tonya ,&troll_tonya ,&boomer_tonya });
    //battle.StartBattle();

    WorldMap::loadMap("W-1.txt");
    UI::PreWorldMap({ &Kazusa ,&Shiroko ,&Hoshino });


    /*
    std::cout << BG_BRIGHT_CYAN;
    UI::distanceDisplay(0, 0, 0);
    */
    UI::moveCursor(0, 0);
    Process::worldMapViewSimulator();

    UI::moveCursor(5, 1);
    return 0;
}
