#include "../../Includes/Control/Game.h"

#include <WorldMap.h>
#include <Role.h>
#include <KeyBoard.h>
#include <EquipmentTable.h>

// Private

int Game::Move(void) {
    return 0;
}

int Game::GetKeyboard(void) {
    return 0;
}

int Game::GiveRandomAttribate(void) {
    return 0;
}

void Game::sortExecutionRole() {
    for (unsigned int i = roles.size()-1; i > 0; i--) {
        for (unsigned int j = 0; j < i; j++) {
            Attribute rolesA = roles[j].GetAttribute();
            Attribute rolesB = roles[j + 1].GetAttribute();
            if (rolesA.GetSPD() < rolesB.GetSPD()) std::swap(roles[j], roles[j + 1]);
            else if (rolesA.GetPA() + rolesA.GetMA() < rolesB.GetPA() + rolesB.GetMA()) std::swap(roles[j], roles[j + 1]);
            else if (rolesA.GetPD() + rolesA.GetMD() < rolesB.GetPD() + rolesB.GetMD()) std::swap(roles[j], roles[j + 1]);
            else if (rolesA.GetMaxHP() < rolesB.GetMaxHP()) std::swap(roles[j], roles[j + 1]);
        }
    }
    return;
}

// Public

void Game::Initialize() {
    SkillTable::Initialize();
    EquipmentTable::Initialize();
    ItemTable::Initialize();
    Role Kazusa("杏山千紗", 1, 1);
    Role Shiorko("砂狼白子", 3, 1);
    Role Hoshino("小鳥游星野", 5, 1);
    
    Role& KazusaRef = Kazusa;
    Role& ShiorkoRef = Shiorko;
    Role& HoshinoRef = Hoshino;
    roles.push_back(KazusaRef);
    roles.push_back(ShiorkoRef);
    roles.push_back(HoshinoRef);
    sortExecutionRole();

    Enemy fat_tonya("胖子 - Tonya", 1, 3);
    Enemy troll_tonya("巨魔 - Tonya", 3, 3);
    Enemy boomer_tonya("胖子炸彈 - Tonya", 5, 3);

    return;
}

void Game::MainProcess(void) {
    using namespace std;

    long long turn = 0;

    Initialize();
    cout << "done" << endl;
    UI::checkConsoleSize(50, 180);
    UI::ShowMenu();

    system("Pause");
    system("CLS");

    vector<Role> executionRoles;
    bool keyState[KeyBoard::INVALID];



    while (true) {
        turn++;
        // Move Stage

        KeyBoard::keyUpdate(keyState);
        if (keyState[KeyBoard::EP]) {
        }
        else if (keyState[KeyBoard::EI]) {
            // backpack process
            ;
        }
        else if (keyState[KeyBoard::EDU] || keyState[KeyBoard::EDL] || keyState[KeyBoard::EDR] || keyState[KeyBoard::EDD]) {
            // - Roll Dice
            // Display Please Roll Dice (UI)
            // displayRollDice();
            // ditect entity is interactiveable

            ;
        }
        // check is on interactiveable object
        // if checkIsOnShop
        // enterShop

        // if checkIsOnEnemy
        // enterCombat
    }

    return;
}

bool Game::checkIsOnShop() {
    using namespace std;

    // if 

    return 0;
}