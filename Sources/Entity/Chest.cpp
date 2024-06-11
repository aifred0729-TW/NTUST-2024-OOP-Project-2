#include "../../Includes/Entity/Chest.h"
#include "ItemTable.h"
#include "Displayer.h"
#include "Backpack.h"
#include <string>
#include <Role.h>
#include <UI.h>
#include"Color.h"
// Public

void Chest::GiveTreasureTo(Role* role) {
    UI::logEvent("");
    UI::logDivider("隨機事件");
    UI::logEvent(role->GetName() +" 發現了一個寶箱！");
    std::vector<std::string> ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent" };
    using namespace Displayer;
    ItemTable itemList;
    uint16_t money, treasure;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int choiceIndex = rand() % (ITEM_TABLE.size() + 1);
    for (const auto& pair : itemList.itemMap) {
        if (choiceIndex == ITEM_TABLE.size()) {
            money = role->GetMoney();
            treasure = (rand() % 500) + 1;
            role->SetMoney(money + treasure);
            UI::displayString("Money :        " + std::to_string(Role::GetMoney()), 70, 3);
            UI::logEvent("獲得金錢 $ " + std::to_string(treasure) + "！現有 & " + std::to_string(role->GetMoney()));
            return;
        }
        else if (pair.first == ITEM_TABLE[choiceIndex]) {
            role->backpack.addItem(pair.second);
            UI::logEvent("獲得" + pair.first + "道具！");
            return;
        }
    }
}