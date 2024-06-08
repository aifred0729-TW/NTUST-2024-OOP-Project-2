#include "Control/WorldMap.h"
#include <Process.h>
#include <string>

int main() {
    SkillTable::Initialize();
    EquipmentTable::Initialize();

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

    hero.equip("MagicWand");
    profPao.equip("Hammer");
    myWife.equip("RitualSword");

    profPao.GetAttribute().SetMaxFocus(20);
    profPao.GetAttribute().SetFocus(20);

    //system("Pause");


    //Process::HandlePreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });

    //UI::PreBattle({ &dragon , &porfDai  , &tonya }, { &hero ,&profPao  , &myWife });
    UI::moveCursor(2, 9);

    Field battle({ &hero ,&profPao  , &myWife } , { &dragon , &porfDai  , &tonya });
    battle.StartBattle();
    
/*
    std::vector<Entity*> targets;
    targets.push_back(&dragon);
    for (int i = 0; i < 2; i++) {
        auto skills = hero.GetTotalSkill().GetActive();
        std::string skillToUse = UI::makeChoice(skills, 6, 9).first;
        UI::logDivider(skillToUse);
        hero.useActive(skillToUse, { &dragon });
    }

    UI::logDivider("");
    hero.GetDice().SetFocusCount(3);
    hero.useActive("Attack", { &dragon });
    UI::logDivider("");
    hero.useActive("Flee", { &hero });
    UI::logDivider("");
    hero.useActive("ShockBlast", { &dragon });
    UI::logDivider("");
    hero.useActive("Heal", { &hero });
    UI::logDivider("");
    hero.useActive("Heal", { &dragon });
    UI::logDivider("");

    UI::logDivider("Equip WoodenSword");
    hero.equip("WoodenSword");
    hero.useActive("SpeedUp", { &hero });

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
    hero.useActive("Attack", targets);
    UI::logDivider("2");
    hero.useActive("Attack", targets);
    UI::logDivider("3");
    hero.useActive("Attack", targets);
    UI::logDivider("4");
    hero.useActive("Attack", targets);
    UI::logDivider("5");
    hero.useActive("Attack", targets);
    UI::logDivider("6");
    hero.useActive("Attack", targets);
    UI::logDivider("7");
    hero.useActive("Attack", targets);
    UI::logDivider("8");
    hero.useActive("Flee", targets);
    UI::logDivider("9");
    hero.useActive("Heal", targets);
    UI::logDivider("10");
    //hero.useActive("SpeedUp", targets);

    UI::logDivider("UnEquip Equipment");
    hero.unEquip(hero.GetEquipment().GetWeapon().GetName());
    hero.unEquip(hero.GetEquipment().GetArmor().GetName());
    hero.unEquip(hero.GetEquipment().GetAccessory().GetName());
    hero.useActive("Attack", targets);
    hero.useActive("Flee", targets);
    //hero.useActive("Heal", targets);
    //hero.useActive("SpeedUp", targets);
    UI::logDivider("Hero");
    //hero.GetTotalAttribute().display();
    UI::logDivider("Dragon");
    //dragon.GetTotalAttribute().display();
    //std::cout << std::endl;
    */

    return 0;
}
