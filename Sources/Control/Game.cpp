#include <WorldMap.h>
#include <Role.h>
#include <Game.h>
#include <Enemy.h>
#include <WorldMap.h>
#include <Role.h>
#include <KeyBoard.h>
#include <EquipmentTable.h>
#include "Dice.h"
#include "Color.h"
#include "Field.h"
#include "EquipmentTable.h"
#include "ItemTable.h"
#include "Tent.h"
#include "Chest.h"

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

    // static Enemy fat_tonya("胖子 - Tonya", 1, 3);
    // static Enemy troll_tonya("巨魔 - Tonya", 3, 3);
    // static Enemy boomer_tonya("胖子炸彈 - Tonya", 5, 3);
    static Enemy prof_D("戴文凱", 1, 3);
    static Enemy prof_P("鮑興國", 3, 3);
    static Enemy prof_H("花凱龍", 5, 3);
    static Enemy prof_Ding("頂天端", 1, 5);
    static Enemy prof_S("項天瑞", 3, 5);
    enemys = { &prof_D ,&prof_P ,&prof_H ,&prof_Ding , &prof_S };

    static Tent tent("他媽的帳篷", 1, 7, 10);
    tents = { &tent };

    WorldMap::SetTents(tents);
    WorldMap::SetRoles(roles);
    WorldMap::SetEnemys(enemys);

    WorldMap::loadMap("W-1.txt");

    return;
}

void Game::MainProcess(void) {
    using namespace std;
    int turn = 1;

    Initialize();
    // cout << "done" << endl;
    UI::checkConsoleSize(50, 180);
    UI::ShowMenu();

    system("Pause");
    system("CLS");
    UI::mapPhase();
    UI::PreWorldMap(roles);
    // vector<Role*> executionRoles;

    while (true) {
        turn++;
        for (int i = 0; i < roles.size(); i++) {
            OnePlayerMovePhase(roles[i]);
        }
    }

    return;
}

int Game::OnePlayerMovePhase(Role* currentActRole) {
    UI::logEvent("");
    UI::logDivider(currentActRole->GetName(), "的回合");
    // Move Stage
    // 投骰子
    int maxMovementPoint = GenerateMovementPoint(currentActRole);
    int movementPoint = maxMovementPoint;
    std::cout << BG_WHITE;
    UI::displayMapGrid();
    UI::PrintWorldMap();
    bool keyState[KeyBoard::INVALID];
    static bool distanceDisplayWork = 0;

    UI::displayString("MovementPoint: " + UI::FocusDisplayer(movementPoint, maxMovementPoint), 70, 4);

    std::cout << BG_WHITE;
    UI::displayMapGrid();

    while (1) {
        UI::stackHeight = 0;
        bool moved = false;
        KeyBoard::keyUpdate(keyState);
        std::pair<int, int> Rpos = { currentActRole->GetPosition().first ,currentActRole->GetPosition().second };
        if (keyState[KeyBoard::EP]) {
            // 回合結算
            UI::logEvent("");
            UI::logDivider("回合結算");
            currentActRole->heal(movementPoint);
            break;
        }
        else if (keyState[KeyBoard::EI]) {
            // backpack process
        }
        else if (keyState[KeyBoard::EDU] || keyState[KeyBoard::EDL] || keyState[KeyBoard::EDR] || keyState[KeyBoard::EDD]) {
            // - Roll Dice
            // Display Please Roll Dice (UI)
            // displayRollDice();
            // ditect entity is interactiveable

            if (Rpos == WorldMap::pos && movementPoint > 0) {
                if (keyState[KeyBoard::EDU]) {
                    moved = currentActRole->movePos(0, -1);
                }
                else if (keyState[KeyBoard::EDD]) {
                    moved = currentActRole->movePos(0, 1);
                }
                else if (keyState[KeyBoard::EDL]) {
                    moved = currentActRole->movePos(-1, 0);
                }
                else if (keyState[KeyBoard::EDR]) {
                    moved = currentActRole->movePos(1, 0);
                }
            }
            else if (movementPoint <= 0) {
                continue;
            }
            Rpos = { currentActRole->GetPosition().first ,currentActRole->GetPosition().second };
            WorldMap::setPos(Rpos);
        }
        else if (keyState[KeyBoard::EW]) {
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
        UI::PrintWorldMap();

        if (moved) {
            // 移動判定
            movementPoint--;
            UI::displayString("MovementPoint: " + UI::FocusDisplayer(movementPoint, maxMovementPoint), 70, 4);
        }
        // 跑到敵人頭上了
        if (moved && !WorldMap::GetRect().enemys.empty()) {
            // 打架

            std::vector<Enemy* > battleE;
            std::vector<Role* > battleR;

            for (auto E : enemys) {
                int distance = WorldMap::manhattanDistance(currentActRole->GetPosition(), E->GetPosition());
                if (distance <= 3 && battleE.size() < 3) {
                    battleE.push_back(E);
                }
            }
            for (auto R : roles) {
                int distance = WorldMap::manhattanDistance(currentActRole->GetPosition(), R->GetPosition());
                if (distance <= 3 && !(R->GetStatus() & DEAD)) {
                    battleR.push_back(R);
                }
            }
            UI::battlePhase();
            Field F(battleR, battleE);
            F.StartBattle();
            UI::PreWorldMap(roles);

            UI::mapPhase();
        }
        if (moved) {
            // 隨機事件判定
            if (rand() % 100 < 15) {
                Chest chest;
                chest.GiveTreasureTo(currentActRole);
            }
        }
        // 跑到帳篷上了
        if (moved && !WorldMap::GetRect().tents.empty()) {

            std::vector<Enemy* > battleE;
            std::vector<Role* > battleR;

            for (auto E : enemys) {
                int distance = WorldMap::manhattanDistance(currentActRole->GetPosition(), E->GetPosition());
                if (distance <= 3 && battleE.size() < 3) {
                    battleE.push_back(E);
                }
            }
            for (auto R : roles) {
                int distance = WorldMap::manhattanDistance(currentActRole->GetPosition(), R->GetPosition());
                if (distance <= 3 && !(R->GetStatus() & DEAD)) {
                    battleR.push_back(R);
                }
            }
            UI::battlePhase();
            Field F(battleR, battleE);
            F.StartBattle();
            UI::PreWorldMap(roles);

            UI::mapPhase();
        }

        // 行動後顯示階段
        if (distanceDisplayWork == 1) {
            std::cout << BG_WHITE;
            UI::displayMapGrid();
            distanceDisplayWork = 0;
        }

        if (!WorldMap::GetRect().enemys.empty() || !WorldMap::GetRect().roles.empty()) {
            // 右側欄位顯示實體
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
            if (!WorldMap::GetRect().roles.empty()) {
                distanceDisplayWork = 1;
                std::cout << BG_WHITE;
                UI::displayMapGrid();
                std::cout << BG_BRIGHT_CYAN;
                UI::distanceDisplay(0, 0, 3);
                for (auto R : WorldMap::GetRect().roles) {
                    entitysToDisplay.push_back(R);
                    if (R == currentActRole) {
                        std::cout << BG_BRIGHT_YELLOW;
                        int x = currentActRole->GetPosition().first - WorldMap::getPos().first;
                        int y = currentActRole->GetPosition().second - WorldMap::getPos().second;
                        UI::distanceDisplay(x, y, movementPoint);
                    }
                }
            }
            UI::displayPlayerInfo(121, 0, entitysToDisplay);
        }
        if (!WorldMap::GetRect().stores.empty()) {
            //UI::BuildFrame(121, 0, 179, 28);
            UI::DisplayStore(121, 0, WorldMap::GetRect().stores);
            //WorldMap::GetRect().stores[0]->SellItemTo();
        }
        if (!WorldMap::GetRect().tents.empty()) {
            //UI::BuildFrame(121, 0, 179, 28);
            UI::DisplayTent(121, 0, WorldMap::GetRect().tents);
            //WorldMap::GetRect().stores[0]->SellItemTo();
        }


        if (!WorldMap::GetRect().enemys.empty() || !WorldMap::GetRect().roles.empty()) {}
        else {
            if (WorldMap::VisibleOnMap(currentActRole->GetPosition())) {
                distanceDisplayWork = 1;
                std::cout << BG_BRIGHT_YELLOW;
                int x = currentActRole->GetPosition().first - WorldMap::getPos().first;
                int y = currentActRole->GetPosition().second - WorldMap::getPos().second;
                UI::distanceDisplay(x, y, movementPoint);
            }
            std::cout << BG_BRIGHT_CYAN;
            UI::distanceDisplay(0, 0, 0);
        }

        for (int i = 0; i < roles.size(); i++) {
            UI::displayPlayerInfo(121, 28 + i * 7, roles[i]);
        }
        UI::moveCursor(0, 0);
        //UI::renewPlayerInfo();
        // check is on interactiveable object
        // if checkIsOnShop
        // enterShop

        // if checkIsOnEnemy
        // enterCombat

        if (movementPoint <= 0) {
            // 按P跳過回合 不會自動跳
            // break;
        }
    }

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