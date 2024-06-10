#include <vector>
#include <iostream>

#include "ItemCommandSet.h"
#include "Role.h"
#include "UI.h"

void GodsbeardCommand::use(Role& role) {
	// UI::logEvent(role.GetName() + "消耗了 Godsbeard 回復了 25 點生命值。");
	role.heal(25);
}

void GoldenRootCommand::use(Role& role) {
	// UI::logEvent(role.GetName() + "消耗了 GoldenRoot 回復了 3 點專注力。");
	role.GetTotalAttribute().SetFocus(role.GetTotalAttribute().GetFocus() + 3);
}

void TeleportScrollCommand::use(Role& role) {
	// UI::logEvent("瞬間移動！！啊哈");
}

void TentCommand::use(Role& role) {
	// UI::logEvent("帳篷，放置！");
}