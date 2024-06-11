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
    std::vector<std::string> randStr1 = { "一個寶箱","老舊的寶箱","神秘的骨灰罈","死亡的冒險者","乾枯的水井","陰暗角落的麻布袋","黃金寶箱" };
    UI::logEvent(role->GetName() + " 發現了" + randStr1[rand() % randStr1.size()]);
    std::vector<std::string> randStr2 = { "經過一番搜索"
        ,"什麼事都沒有發生，被路過的戴文凱施捨一些東西","坐在附近發呆，總之就是...","感到非常興奮","感到自己被幸運之神眷顧","仔細觀察隻遭" };
    UI::logEvent(randStr2[rand() % randStr2.size()]);
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

void Chest::SetPosition(const std::pair<uint32_t, uint32_t>& position) {
    this->position = position;
}

std::pair<uint32_t, uint32_t> Chest::GetPosition(void) const {
    return position;
}