#include <vector>
#include <iostream>

#include "ItemCommandSet.h"
#include "Role.h"
#include "UI.h"
#include "WorldMap.h"
#include "Game.h"

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
    // UI::logEvent("瞬間移動！！啊哈");
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

}