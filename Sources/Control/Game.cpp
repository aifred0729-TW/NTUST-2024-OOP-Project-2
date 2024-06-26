﻿#include <WorldMap.h>
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
#include "Store.h"
#include "Backpack.h"
#include "Item.h"

// Private
std::vector<Role*> Game::roles;
std::vector<Enemy*> Game::enemys;
std::vector<Tent*> Game::tents;
std::vector<Store*> Game::stores;
std::vector<Chest*> Game::chests;

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
    Kazusa.equipForce("WoodenSword");
    Kazusa.equipForce("LaurelWreath");
    Kazusa.equipForce("Bracelet");
    static Role Shiroko("砂狼白子", 3, 1);
    Shiroko.equipForce("RitualSword");
    Shiroko.equipForce("Robe");
    Shiroko.equipForce("Shoes");
    Shiroko.addItemToBackpack("HolyGrail");
    Shiroko.addItemToBackpack("LaurelWreath");
    Shiroko.addItemToBackpack("LeatherArmor");
    static Role Hoshino("小鳥游星野", 5, 1);
    Hoshino.equipForce("Hammer");
    Hoshino.equipForce("PlateArmor");
    Hoshino.equipForce("HolyGrail");

    // Role::backpack.useItem("物品名稱", 使用者); // 這邊 Parameter 可以再加更多東西

    /*
    std::string name;
    uint16_t price;
    ItemCommand* command;
    */

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
    prof_Ding.equipForce("Hammer");
    prof_S.equipForce("Hammer");
    prof_D.equipForce("Hammer");
    prof_P.equipForce("Hammer");
    prof_H.equipForce("Hammer");

    enemys = { &prof_D ,&prof_P ,&prof_H ,&prof_Ding , &prof_S };

    // static Tent tent("他媽的帳篷", 1, 7, 10);
    // static Tent tent2("他媽的帳篷2", 7, 1, 2);
    // tents = { &tent , &tent2 };

    static Store store1("TR-509 處刑場", 5, 5);
    stores = { &store1 };

    static Chest chest1(7, 1);
    chests = { &chest1 };

    WorldMap::SetTents(tents);
    WorldMap::SetRoles(roles);
    WorldMap::SetEnemys(enemys);
    WorldMap::SetStores(stores);
    WorldMap::SetChests(chests);

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
    for (int i = 0; i < 56; i++) {
        UI::displayFile("porf.txt", i, 0);
        Sleep(10);
    }

    for (auto R : roles) {
        WorldMap::SetFog(R->GetPosition().second, R->GetPosition().first);
    }
    UI::mapPhase();
    UI::PreWorldMap(roles);
    // vector<Role*> executionRoles;

    while (true) {
        turn++;
        for (int i = 0; i < roles.size(); i++) {
            for (int j = 0; j < tents.size(); j++) {
                if (tents[j]->timePass()) {
                    tents.erase(tents.begin() + j);
                    WorldMap::SetTents(tents);
                    j--;
                }
            }
            if (roles.size() == 0) {
                // 結束遊戲
                break;
            }
            if (roles.size() - 1 < i) {
                break;
            }
            OnePlayerMovePhase(roles[i]);
        }
        if (roles.size() == 0) {
            // 結束遊戲
            break;
        }
    }
    // 結束遊戲
    for (int i = 0; i < 56; i++) {
        UI::displayFile("porf.txt", i, 0);
        Sleep(10);
    }
    return;
}

int Game::OnePlayerMovePhase(Role* currentActRole) {

    int chestX = currentActRole->GetPosition().first - 5 + rand() % 10;
    int chestY = currentActRole->GetPosition().second - 5 + rand() % 10;
    if (!WorldMap::GetRect({ chestX, chestY }).Interact && WorldMap::GetRect({ chestX, chestY }).moveable) {
        createChest(chestX, chestY);
    }


    UI::logEvent("");
    UI::logDivider(currentActRole->GetName(), "的回合");
    // Move Stage
    // 投骰子
    int maxMovementPoint = GenerateMovementPoint(currentActRole);
    int movementPoint = maxMovementPoint;
    WorldMap::setPos(currentActRole->GetPosition());
    std::cout << BG_WHITE;
    UI::displayMapGrid();
    UI::PrintWorldMap();
    bool keyState[KeyBoard::INVALID];
    static bool distanceDisplayWork = 0;

    UI::displayString("Money :        " + std::to_string(Role::GetMoney()) + "    ", 70, 3);
    UI::displayString("                                    ", 70, 4);
    UI::displayString("MovementPoint: " + UI::FocusDisplayer(movementPoint, maxMovementPoint), 70, 4);

    std::cout << BG_WHITE;
    UI::displayMapGrid();

    while (1) {
        UI::stackHeight = 0;
        bool moved = false;
        bool checkOut = false;
        std::pair<int, int> undo = { 0,0 };
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
            choiceItem(currentActRole);
            /*
            Game::createTent(currentActRole);
            WorldMap::SetTents(tents);
            UI::PrintWorldMap();
            */
            // backpack process
        }
        else if (keyState[KeyBoard::EQ]) {
            UI::BuildFrame(121, 0, 179, 28);
            std::vector<std::string> roleNames;
            for (auto R : roles) {
                roleNames.push_back(R->GetName());
            }
            int displayIndex = UI::makeChoice(roleNames, 126, 2);
            if (displayIndex == -1) {
                UI::BuildFrame(121, 0, 179, 28);
                continue;
            }
            else {
                displayEquipment(roles[displayIndex]);
                continue;
            }
        }
        else if (keyState[KeyBoard::EDU] || keyState[KeyBoard::EDL] || keyState[KeyBoard::EDR] || keyState[KeyBoard::EDD]) {
            // - Roll Dice
            // Display Please Roll Dice (UI)
            // displayRollDice();
            // ditect entity is interactiveable

            if (Rpos == WorldMap::pos && movementPoint > 0) {
                if (keyState[KeyBoard::EDU]) {
                    moved = currentActRole->movePos(0, -1);
                    undo = { 0, 1 };
                }
                else if (keyState[KeyBoard::EDD]) {
                    moved = currentActRole->movePos(0, 1);
                    undo = { 0, -1 };
                }
                else if (keyState[KeyBoard::EDL]) {
                    moved = currentActRole->movePos(-1, 0);
                    undo = { 1, 0 };
                }
                else if (keyState[KeyBoard::EDR]) {
                    moved = currentActRole->movePos(1, 0);
                    undo = { -1, 0 };
                }
                WorldMap::SetFog(currentActRole->GetPosition().second, currentActRole->GetPosition().first);
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
            Rpos = { currentActRole->GetPosition().first ,currentActRole->GetPosition().second };
            distanceDisplayWork = 1;
            WorldMap::setPos(Rpos);
            checkOut = true;
        }
        else if (keyState[KeyBoard::EESC]) {
            WorldMap::RemoveFog();
        }
        else {
            continue;
        }
        UI::PrintWorldMap();

        if (moved) {
            // 移動判定
            movementPoint--;
            UI::displayString("Money :        " + std::to_string(Role::GetMoney()) + "    ", 70, 3);
            UI::displayString("MovementPoint: " + UI::FocusDisplayer(movementPoint, maxMovementPoint), 70, 4);
        }
        // 踩上可互動物件
        if ((moved && WorldMap::GetRect().Interact) || checkOut) {
            // 跑到敵人頭上了
            if (!WorldMap::GetRect().enemys.empty()) {
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

                UI::PrintWorldMap();
                //std::cout << BG_WHITE;
                UI::displayMapGrid();
                std::cout << BG_BRIGHT_RED;
                UI::distanceDisplay(0, 0, 3);
                std::vector<Entity*> entitysToDisplay;
                for (auto E : battleE) {
                    entitysToDisplay.push_back(E);
                }
                for (auto R : battleR) {
                    entitysToDisplay.push_back(R);
                }
                UI::displayPlayerInfo(121, 0, entitysToDisplay);

                std::string Ecount = std::to_string(battleE.size());
                std::string Rcount = std::to_string(battleR.size());
                std::vector<std::string> choices = { (Rcount + "位隊員與" + Ecount + "位敵人戰鬥") , "撤退" };
                int result = UI::makeChoice(choices, 70, 1);
                UI::BuildVoid(65, 0, 110, 3);
                if (result == 0) {
                    movementPoint = 0;
                    UI::battlePhase();
                    Field F(battleR, battleE);
                    F.StartBattle();
                    UI::stackHeight = 0;
                    for (int i = 0; i < roles.size(); i++) {
                        if (roles[i]->GetStatus() & DEAD) {
                            roles.erase(roles.begin() + i);
                            WorldMap::SetRoles(roles);
                            i--;
                        }
                    }
                    for (int i = 0; i < enemys.size(); i++) {
                        if (enemys[i]->GetStatus() & DEAD) {
                            enemys.erase(enemys.begin() + i);
                            WorldMap::SetEnemys(enemys);
                            i--;
                        }
                    }
                    if (enemys.size() == 0) {
                        //戰鬥勝利
                    }
                    else if (roles.size() == 0) {
                        //被幹死了
                        return 0;
                    }
                    else {
                        //烙幹了
                        currentActRole->movePos(undo);
                    }
                    UI::PreWorldMap(roles);
                    UI::mapPhase();
                    break;
                }
                else {
                    currentActRole->movePos(undo);
                    UI::stackHeight = 0;
                    UI::PrintWorldMap();
                    UI::displayMapGrid();
                }
            }

            // 跑到帳篷上了
            if (!WorldMap::GetRect().tents.empty()) {
                std::vector<std::string> choices = { "休息" , "取消" };
                int result = UI::makeChoice(choices, 70, 1);
                UI::BuildVoid(65, 0, 110, 3);
                if (result == 0) {
                    WorldMap::GetRect().tents[0]->Recover(currentActRole);
                    movementPoint = 0;
                    UI::logEvent("");
                    UI::logDivider("回合結算");
                    UI::logEvent(currentActRole->GetName() + " 在帳篷中休息一回合");
                    break;
                }
            }
            // 商店
            if (!WorldMap::GetRect().stores.empty()) {
                std::vector<std::string> choices = { "進入商店" , "取消" };
                int result = UI::makeChoice(choices, 70, 1);
                UI::BuildVoid(65, 0, 110, 3);
                if (result == 0) {
                    UI::BuildFrame(121, 0, 179, 28);
                    while (1) {
                        int quitShop = WorldMap::GetRect().stores[0]->OpenShop();
                        if (quitShop == -1) {
                            break;
                        }
                    }
                }
            }
            if (!WorldMap::GetRect().chests.empty()) {
                std::vector<std::string> choices = { "隨機事件" , "取消" };
                int result = UI::makeChoice(choices, 70, 1);
                UI::BuildVoid(65, 0, 110, 3);
                if (result == 0) {
                    WorldMap::GetRect().chests[0]->GiveTreasureTo(currentActRole);
                    for (auto it = chests.begin(); it != chests.end();) {
                        if ((*it) == WorldMap::GetRect().chests[0]) {
                            it = chests.erase(it);
                        } else {
                            ++it;
                        }
                    }
                    WorldMap::SetChests(chests);
                }

                UI::PrintWorldMap();
            }
        }
        if (moved) {
            // 隨機事件判定
            if (rand() % 100 < 0) {
                Chest chest;
                chest.GiveTreasureTo(currentActRole);
            }
        }

        // 行動後顯示階段
        if (distanceDisplayWork == 1) {
            std::cout << BG_WHITE;
            UI::displayMapGrid();
            distanceDisplayWork = 0;
        }
        if (WorldMap::getFog(1)) {
            UI::BuildFrame(121, 0, 179, 28);
        }
        if (!WorldMap::GetRect().enemys.empty() || !WorldMap::GetRect().roles.empty()) {
            // 右側欄位顯示實體
            UI::BuildFrame(121, 0, 179, 28);

            std::vector<Entity*> entitysToDisplay;
            if (!WorldMap::GetRect().enemys.empty() && !WorldMap::getFog(1)) {
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
        if (!WorldMap::GetRect().stores.empty() && !WorldMap::getFog(1)) {
            UI::DisplayStore(121, 0, WorldMap::GetRect().stores);
        }
        if (!WorldMap::GetRect().tents.empty() && !WorldMap::getFog(1)) {
            UI::DisplayTent(121, 0, WorldMap::GetRect().tents);
        }
        if (!WorldMap::GetRect().chests.empty() && !WorldMap::getFog(1)) {
            UI::DisplayChest(121, 0);
        }

        if ((!WorldMap::GetRect().enemys.empty() || !WorldMap::GetRect().roles.empty()) && !WorldMap::getFog(1)) {}
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
    Dice& dice = currentActRole->GetDice();
    dice.SetAmount(MaxmovementPoint);
    int succesRate = SPD > 90 ? 90 : SPD;
    std::vector<uint8_t> RateVec(MaxmovementPoint, succesRate);
    dice.SetSuccessRate(RateVec);

    if (currentActRole->findAvailablePassive("Run")) {
        currentActRole->usePassive("Run", { currentActRole });
    }
    dice.RollDiceMove();
    return dice.GetMovementPoint();
}

void Game::createTent(Role* role) {
    std::string name = (role->GetName() + " 的帳篷");
    Tent* tentToPush = new Tent(name, role->GetPosition());
    tents.push_back(tentToPush);
    WorldMap::SetTents(tents);
    UI::PrintWorldMap();
}

void Game::createChest(int x, int y) {
    Chest* chestToPush = new Chest(x, y);
    chests.push_back(chestToPush);
    WorldMap::SetChests(chests);
    UI::PrintWorldMap();
}

void Game::displayEquipment(Role* role) {
    using namespace std;
    int i = 0;
    UI::BuildFrame(121, 0, 179, 28);
    UI::moveCursor(124, 2 + i);
    cout << YELLOW << UI::horizontalLine(role->GetName(), 53, '-') << RESET;
    std::string EquipmentType[3] = { "Weapon:    " , "Armor:     " , "Accessory: " };
    UI::moveCursor(124, 4 + i);
    cout << EquipmentType[0] << role->GetEquipment().GetWeapon().GetName() << RESET;

    for (int j = 0; j < role->GetEquipment().GetWeapon().GetSkill().GetActive().size(); j++) {
        UI::moveCursor(124, 5 + i);
        cout << "Active:    " << role->GetEquipment().GetWeapon().GetSkill().GetActive()[j].GetName();
        i++;
    }
    for (int j = 0; j < role->GetEquipment().GetWeapon().GetSkill().GetPassive().size(); j++) {
        UI::moveCursor(124, 5 + i);
        cout << "Passive:   " << role->GetEquipment().GetWeapon().GetSkill().GetPassive()[j].GetName();
        i++;
    }
    UI::moveCursor(124, 5 + i);
    displayAttribute(role->GetEquipment().GetWeapon().GetAttribute());
    i += 3;
    UI::moveCursor(124, 4 + i);
    cout << EquipmentType[1] << role->GetEquipment().GetArmor().GetName() << RESET;

    for (int j = 0; j < role->GetEquipment().GetArmor().GetSkill().GetActive().size(); j++) {
        UI::moveCursor(124, 5 + i);
        cout << "Active:    " << role->GetEquipment().GetArmor().GetSkill().GetActive()[j].GetName();
        i++;
    }
    for (int j = 0; j < role->GetEquipment().GetArmor().GetSkill().GetPassive().size(); j++) {
        UI::moveCursor(124, 5 + i);
        cout << "Passive:   " << role->GetEquipment().GetArmor().GetSkill().GetPassive()[j].GetName();
        i++;
    }
    UI::moveCursor(124, 5 + i);
    displayAttribute(role->GetEquipment().GetArmor().GetAttribute());
    i += 3;

    UI::moveCursor(124, 4 + i);
    cout << EquipmentType[2] << role->GetEquipment().GetAccessory().GetName() << RESET;
    for (int j = 0; j < role->GetEquipment().GetAccessory().GetSkill().GetActive().size(); j++) {
        UI::moveCursor(124, 5 + i);
        cout << "Active:    " << role->GetEquipment().GetAccessory().GetSkill().GetActive()[j].GetName();
        i++;
    }
    for (int j = 0; j < role->GetEquipment().GetAccessory().GetSkill().GetPassive().size(); j++) {
        UI::moveCursor(124, 5 + i);
        cout << "Passive:   " << role->GetEquipment().GetAccessory().GetSkill().GetPassive()[j].GetName();
        i++;
    }
    UI::moveCursor(124, 5 + i);
    displayAttribute(role->GetEquipment().GetAccessory().GetAttribute());
}

void Game::displayAttribute(Attribute att) {
    using namespace std;
    cout << "PA: " << ((att.GetPA() == 0) ? DARK : GREEN) << setw(2) << setfill('0') << att.GetPA() << RESET;
    cout << "   PD: " << ((att.GetPD() == 0) ? DARK : GREEN) << setw(2) << setfill('0') << att.GetPD() << RESET;
    cout << "   MA: " << ((att.GetMA() == 0) ? DARK : GREEN) << setw(2) << setfill('0') << att.GetMA() << RESET;
    cout << "   MD: " << ((att.GetMD() == 0) ? DARK : GREEN) << setw(2) << setfill('0') << att.GetMD() << RESET;
    cout << "   SPD: " << ((att.GetSPD() == 0) ? DARK : GREEN) << setw(2) << setfill('0') << att.GetSPD() << RESET;
    cout << "   ACC: " << ((att.GetACC() == 0) ? DARK : GREEN) << setw(2) << setfill('0') << att.GetACC() << RESET;
}

void Game::choiceItem(Role* role) {
    UI::BuildFrame(121, 0, 179, 28);
    using namespace std;
    std::vector<Item*> items = Role::backpack.getItems();
    if (items.empty()) {
        UI::displayString("[背包空空如也...] ", 126, 2);
        system("Pause");
        return;
    }
    std::vector<std::string> choices;
    for (const auto& item : items) {
        std::string itemStr = item->getName();
        if (item->isStackable()) {
            itemStr.resize(44, ' ');
            StackableItem* stackableItem = dynamic_cast<StackableItem*>(item);
            if (stackableItem) {
                itemStr += " : " + std::to_string(stackableItem->getQuantity());
            }
        }
        else {
            itemStr += " : *";
        }
        choices.push_back(itemStr);
    }
    int choiceIndex = UI::makeChoice(choices, 126, 2, 20);
    if (choiceIndex == -1) {
        return;
    }
    Role::backpack.useItem(items[choiceIndex]->getName(), *role);
}