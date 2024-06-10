#include "../../Includes/Control/Game.h"

#include <WorldMap.h>
#include <Role.h>
#include <KeyBoard.h>
#include <EquipmentTable.h>
#include "Dice.h"

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
    for (unsigned int i = roles.size() - 1; i > 0; i--) {
        for (unsigned int j = 0; j < i; j++) {
            int jj = j + 1;
            Attribute rolesA = roles[j]->GetTotalAttribute();
            Attribute rolesB = roles[jj]->GetTotalAttribute();
            if (rolesA.GetSPD() < rolesB.GetSPD()) std::swap(roles[j], roles[jj]);
            else if (rolesA.GetSPD() > rolesB.GetSPD()) {}
            else if (rolesA.GetPA() + rolesA.GetMA() < rolesB.GetPA() + rolesB.GetMA()) std::swap(roles[j], roles[jj]);
            else if (rolesA.GetPA() + rolesA.GetMA() > rolesB.GetPA() + rolesB.GetMA()) {}
            else if (rolesA.GetPD() + rolesA.GetMD() < rolesB.GetPD() + rolesB.GetMD()) std::swap(roles[j], roles[jj]);
            else if (rolesA.GetPD() + rolesA.GetMD() > rolesB.GetPD() + rolesB.GetMD()) {}
            else if (rolesA.GetMaxHP() < rolesB.GetMaxHP()) std::swap(roles[j], roles[jj]);
        }
    }
    return;
}

// Public

void Game::Initialize() {
    SkillTable::Initialize();
    EquipmentTable::Initialize();
    ItemTable::Initialize();

    static Role Kazusa("杏山千紗", 1, 1);
    static Role Shiroko("砂狼白子", 3, 1);
    static Role Hoshino("小鳥游星野", 5, 1);
    roles = { &Kazusa ,&Shiroko ,&Hoshino };

    // static Role* KazusaRef = &Kazusa;
    // static Role* ShirokoRef = &Shiroko;
    // static Role* HoshinoRef = &Hoshino;
    // roles.push_back(KazusaRef);
    // roles.push_back(ShirokoRef);
    // roles.push_back(HoshinoRef);
    sortExecutionRole();

    static Enemy fat_tonya("胖子 - Tonya", 1, 3);
    static Enemy troll_tonya("巨魔 - Tonya", 3, 3);
    static Enemy boomer_tonya("胖子炸彈 - Tonya", 5, 3);
    enemys = { &fat_tonya ,&troll_tonya ,&boomer_tonya };

    return;
}

void Game::MainProcess(void) {
    using namespace std;

    long long turn = 0;

    Initialize();
    // cout << "done" << endl;
    UI::checkConsoleSize(50, 180);
    UI::ShowMenu();

    system("Pause");
    system("CLS");


    WorldMap::loadMap("W-1.txt");
    UI::PreWorldMap(roles);
    // vector<Role*> executionRoles;

    OnePlayerMovePhase(roles[0]);

    while (true) {
        turn++;
        for (int i = 0; i < roles.size(); i++) {
            OnePlayerMovePhase(roles[i]);
        }
    }

    return;
}

int Game::OnePlayerMovePhase(Role* currentActRole) {
    // Move Stage
    int movementPoint = GenerateMovementPoint(currentActRole);

    bool keyState[KeyBoard::INVALID];
    KeyBoard::keyUpdate(keyState);
    if (keyState[KeyBoard::EP]) {
    }
    else if (keyState[KeyBoard::EI]) {
        // backpack process

    }
    else if (keyState[KeyBoard::EDU] || keyState[KeyBoard::EDL] || keyState[KeyBoard::EDR] || keyState[KeyBoard::EDD]) {
        // - Roll Dice
        // Display Please Roll Dice (UI)
        // displayRollDice();
        // ditect entity is interactiveable


    }
    // check is on interactiveable object
    // if checkIsOnShop
    // enterShop

    // if checkIsOnEnemy
    // enterCombat

    return 0;
}

int Game::GenerateMovementPoint(Role* currentActRole) {
    int SPD = currentActRole->GetTotalAttribute().GetSPD();
    int MaxmovementPoint = SPD / 10;
    Dice dice;
    dice.SetAmount(MaxmovementPoint);
    int succesRate = SPD > 90 ? 90 : SPD;
    std::vector<uint8_t> RateVec(MaxmovementPoint, succesRate);
    dice.SetSuccessRate(RateVec);
    dice.RollDiceMove();
    return dice.GetMovementPoint();
}

bool Game::checkIsOnShop() {
    using namespace std;

    // if 

    return 0;
}