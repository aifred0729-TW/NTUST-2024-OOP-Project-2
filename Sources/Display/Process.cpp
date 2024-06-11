#include <Process.h>
#include <UI.h>
#include <KeyBoard.h>
#include <Color.h>
#include <Role.h>
#include <Enemy.h>
#include <WorldMap.h>
#include <Dice.h>
#include <Field.h>
#include <KeyBoard.h>
#include <color.h>
#include <Displayer.h>
#include <WorldMap.h>
#include "Equipment.h"
#include "Store.h"

int Process::HandlePreBattle(std::vector<Enemy*> enemys, std::vector<Role*> roles) {
    UI::PreBattle(enemys, roles);
    for (int i = 0; i < enemys.size(); i++) {
        //enemys[i]->SetEventID(i); // 待修改 之後改成Action
    }
    for (int i = 0; i < roles.size(); i++) {
        //roles[i]->SetEventID(i + 3); // 待修改 
    }
    fightSimulator(enemys, roles);
    return 0;
}

int Process::fightSimulator(std::vector<Enemy*>enemys, std::vector<Role*>roles) {
    for (int round = 0; round < 5; round++) {
        for (int i = 0; i < roles.size(); i++) {
            UI::BuildVoid(121, 7, 0, 27);
            UI::PlayerFrame({ 0,1,2,3,4,5 });
            std::cout << YELLOW;
            UI::PlayerFrame(i + 3);

            auto skills = roles[i]->GetTotalSkill().GetActive();
            auto skillToUse = UI::makeChoice(skills, 6, 9);
            UI::logDivider(roles[i]->GetName(), skillToUse.first);

            int diceAmount = skillToUse.first == "Attack" ?
                roles[i]->GetEquipment().GetWeapon().GetDiceAmount() : skills[skillToUse.second].GetDiceAmount();
            int focus = roles[i]->GetTotalAttribute().GetFocus();

            UI::displayDice(diceAmount, 0);

            auto target = targetChoiceSimulator(enemys, roles, roles[i], skills[skillToUse.second].GetTargetType());
            if (target.empty()) {
                i--;
                UI::logEvent("行動已取消");
                UI::logEvent("");
                continue;
            }
            int focusUse = focusUseSimulator(focus, diceAmount);
            if (focusUse == -1) {
                i--;
                UI::logEvent("行動已取消");
                UI::logEvent("");
                continue;
            }
            if (focusUse != 0) {
                UI::logEvent("使用 " + std::to_string(focusUse) + " 專注點數");
                roles[i]->GetTotalAttribute().SetFocus(focus - focusUse);
                roles[i]->GetDice().SetFocusCount(focusUse);
            }
            roles[i]->useActive(skillToUse.first, target);
            UI::logEvent("");
        }
    }
    return 0;
}

int Process::focusUseSimulator(int focusPoint, int diceAmount) {
    int focusUse = 0;
    bool keyState[KeyBoard::INVALID];
    UI::displayDice(diceAmount, focusUse);
    //UI::renewPlayerInfo();
    while (1) {
        KeyBoard::keyUpdate(keyState);
        if (keyState[KeyBoard::EA]) {
            if (focusUse > 0) {
                focusUse--;
            }
        }
        else if (keyState[KeyBoard::ED]) {
            if (focusUse < focusPoint && focusUse < diceAmount) {
                focusUse++;
            }
        }
        else if (keyState[KeyBoard::ESPACE] || keyState[KeyBoard::EENTER]) {
            return focusUse;
        }
        else if (keyState[KeyBoard::EESC]) {
            return -1;
        }
        else {
            continue;
        }
        UI::displayDice(diceAmount, focusUse);
        //UI::renewPlayerInfo();
    }
}

std::vector<Entity*> Process::targetChoiceSimulator(std::vector<Enemy*>enemys, std::vector<Role*>roles, Role* caster, int TargetType) {
    std::vector<std::string> targetName;
    std::vector<std::vector<Entity*>> targetPtr;
    std::vector<Entity*> enemysToEntity;
    std::vector<Entity*> rolesToEntity;
    switch (TargetType) {
    case 0:
        targetName.push_back("《 Self 》");
        targetPtr.push_back({ caster });
        break;
    case 1:
        for (Enemy* E : enemys) {
            targetName.push_back(E->GetName());
            targetPtr.push_back({ E });
        }
        break;
    case 2:
        targetName.push_back("《 All enemies 》");
        for (Enemy* E : enemys) {
            enemysToEntity.push_back(E);
        }
        targetPtr.push_back(enemysToEntity);
        break;
    case 3:
        for (Role* R : roles) {
            targetName.push_back(R->GetName());
            targetPtr.push_back({ R });
        }
        break;
    case 4:
        targetName.push_back("《 All teammates 》");
        for (Role* R : roles) {
            rolesToEntity.push_back(R);
        }
        targetPtr.push_back(rolesToEntity);
        break;
    default:
        for (Enemy* E : enemys) {
            targetName.push_back(E->GetName());
            targetPtr.push_back({ E });
        }
        for (Role* R : roles) {
            targetName.push_back(R->GetName());
            targetPtr.push_back({ R });
        }
        break;
    }
    int targetNumber = UI::makeChoice(targetName, 26, 9);
    if (targetNumber == -1) {
        return {};
    }
    return targetPtr[targetNumber];
}

int Process::worldMapViewSimulator() {
    bool keyState[KeyBoard::INVALID];
    bool distanceDisplayWork = 0;
    while (1) {
        KeyBoard::keyUpdate(keyState);
        if (keyState[KeyBoard::EW]) {
            WorldMap::movePos(0, -1);
        }
        else if (keyState[KeyBoard::EA]) {
            WorldMap::movePos(-1, 0);
        }
        else if (keyState[KeyBoard::ES]) {
            WorldMap::movePos(0, 1);
        }
        else if (keyState[KeyBoard::ED]) {
            WorldMap::movePos(1, 0);
        }
        else if (keyState[KeyBoard::ESPACE] || keyState[KeyBoard::EENTER]) {
        }
        else if (keyState[KeyBoard::EESC]) {
        }
        else {
            continue;
        }

        if (distanceDisplayWork == 1) {
            std::cout << BG_WHITE;
            UI::displayMapGrid();
            distanceDisplayWork = 0;
        }

        UI::PrintWorldMap();
        if (!WorldMap::GetRect().stores.empty()) {
            UI::BuildFrame(121, 0, 179, 28);

            std::vector<Store*> storesToDisplay;
            //UI::displayDiceMove({ 0, 1, 0, 1, 0, 1 });
            //WorldMap::GetRect().stores[0]->SellItemTo();
        }
        else if (!WorldMap::GetRect().enemys.empty() || !WorldMap::GetRect().roles.empty()) {

            UI::BuildFrame(121, 0, 179, 28);

            std::vector<Entity*> entitysToDisplay;
            if (!WorldMap::GetRect().enemys.empty()) {
                distanceDisplayWork = 1;
                std::cout << BG_WHITE;
                UI::displayMapGrid();
                std::cout << BG_BRIGHT_RED;
                UI::distanceDisplay(0, 0, 3);
                for (auto E : WorldMap::GetRect().enemys) {
                    entitysToDisplay.push_back(E);
                }
            }
            else if (!WorldMap::GetRect().roles.empty()) {
                distanceDisplayWork = 1;
                std::cout << BG_WHITE;
                UI::displayMapGrid();
                std::cout << BG_BRIGHT_CYAN;
                UI::distanceDisplay(0, 0, 3);
                for (auto R : WorldMap::GetRect().roles) {
                    entitysToDisplay.push_back(R);
                }
            }
            UI::displayPlayerInfo(121, 0, entitysToDisplay);
        }
        else {
            std::cout << BG_BRIGHT_CYAN;
            UI::distanceDisplay(0, 0, 0);
        }
        UI::moveCursor(0, 0);
        //UI::renewPlayerInfo();
    }
    return 0;
}
