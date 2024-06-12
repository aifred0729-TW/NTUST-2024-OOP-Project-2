#include <vector>
#include <iostream>

#include "ItemCommandSet.h"
#include "Role.h"
#include "UI.h"
#include "WorldMap.h"
#include "Game.h"
#include "Backpack.h"
#include "Item.h"
#include "ItemTable.h"
#include "KeyBoard.h"
#include "Color.h"

void GodsbeardCommand::use(Role& role) {
    UI::logDivider("使用道具");
    UI::logEvent(role.GetName() + "消耗了 Godsbeard 回復了 25 點生命值。");
    role.heal(25);
}

void GoldenRootCommand::use(Role& role) {
    UI::logDivider("使用道具");
    UI::logEvent(role.GetName() + "消耗了 GoldenRoot 回復了 3 點專注力。");
    role.GetTotalAttribute().SetFocus(role.GetTotalAttribute().GetFocus() + 3);
}

void TeleportScrollCommand::use(Role& role) {
    UI::logEvent("不可名狀的聲音似乎正在告訴你選擇一個座標....");
    UI::logEvent(role.GetName() + " : 座標這個單字是什麼意思...?");

    bool keyState[KeyBoard::INVALID];

    std::cout << BG_WHITE;
    UI::displayMapGrid();

    while (true) {

        std::cout << BG_MAGENTA;
        UI::distanceDisplay(0, 0, 0);

        KeyBoard::keyUpdate(keyState);

        if (keyState[KeyBoard::EW]) WorldMap::movePos(0, -1);
        else if (keyState[KeyBoard::EA]) WorldMap::movePos(-1, 0);
        else if (keyState[KeyBoard::ES]) WorldMap::movePos(0, 1);
        else if (keyState[KeyBoard::ED]) WorldMap::movePos(1, 0);
        else if (keyState[KeyBoard::ESPACE]) {
            role.GetPosition();
            role.movePos(WorldMap::getPos());
            UI::PrintWorldMap();
            UI::logEvent("瞬間移動！！啊哈");
            return;
        }

        UI::PrintWorldMap();
    }
}

void TentCommand::use(Role& role) {
    UI::logDivider("使用道具");
    Rect R = WorldMap::GetRect(&role);
    if (UI::phase == 1) {
        UI::logEvent("[失敗 無法在戰鬥中紮營]");
    }
    else if (!R.enemys.empty()) {
        UI::logEvent("[失敗 無法在敵人頭上紮營]");
    }
    else if (!R.stores.empty()) {
        UI::logEvent("[失敗 無法在商店屋頂上紮營]");
    }
    else if (!R.tents.empty()) {
        UI::logEvent("[失敗 無法在帳篷上紮營]");
    }
    else if (!R.moveable) {
        UI::logEvent("[失敗 不對你他媽怎麼走到那裡的]");
    }
    else {
        UI::logEvent(role.GetName() + " 帳篷，放置！");
        Game::createTent(&role);
        return;
    }
    Role::backpack.addItem(ItemTable::getItem("Tent"));
}