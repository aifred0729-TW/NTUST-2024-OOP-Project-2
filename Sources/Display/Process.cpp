#include "../../Includes/Display/Process.h"

#include <skill.h>
#include <Entity.h>

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
            int focus = roles[i]->GetAttribute().GetFocus();
            int focusUse = focusUseSimulator(focus, diceAmount);
            if (focusUse == -1) {
                i--;
                UI::logEvent("行動已取消");
                UI::logEvent("");
                continue;
            }
            else if (focusUse != 0) {
                UI::logEvent("使用 " + std::to_string(focusUse) + " 專注點數");
            }

            roles[i]->GetAttribute().SetFocus(focus - focusUse);
            roles[i]->GetDice().SetFocusCount(focusUse);
            roles[i]->useSkill(skillToUse.first, { enemys[i] });
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

int Process::HandleMemu(void) {
    return 0;
}

int Process::Handle(std::vector<std::pair<int, int>>*) {
    return 0;
}

int Process::Handle(std::vector<Dice*>) {
    return 0;
}

int Process::Handle(std::vector<Entity*>) {
    return 0;
}

int Process::Handle(Field*) {
    return 0;
}

int Process::Handle(Store*) {
    return 0;
}

int Process::Handle(Interactive*) {
    return 0;
}