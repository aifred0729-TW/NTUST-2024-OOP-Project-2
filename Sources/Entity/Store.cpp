#include "../../Includes/Entity/Store.h"
#include "ItemTable.h"
#include "Displayer.h"
#include "Backpack.h"
#include "UI.h"
#include "Role.h"
#include <Item.h>

// Public
Store::Store(std::string name, std::pair<int, int> position) {
    this->name = name;
    this->position = position;
};

Store::Store(std::string name, int x, int y) {
    this->name = name;
    this->position = { x,y };
}

std::pair<int, int> Store::GetPosition(void) const {
    return position;
}

std::string Store::GetName(void) const {
    return name;
}

void Store::SellItemTo(Role* player) {
    std::vector<std::string> ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent", "WoodenSword", "Hammer", "GiantHammer", "MagicWand",
    "RitualSword", "WoodenShield", "PlateArmor", "LeatherArmor", "Robe", "LaurelWreath", "HolyGrail", "Shoes", "Bracelet" };
    ItemTable itemList;
    uint16_t price, money;
    int index = 0;
    for (const auto& pair : itemList.itemMap) {
        for (int i = 0; i < ITEM_TABLE.size(); ++i) {
            if (pair.first == ITEM_TABLE[i]) {
                ITEM_TABLE[i] += ": $";
                ITEM_TABLE[i] += std::to_string(pair.second->getPrice());
                break;
            }
        }
    }
    int choiceIndex = UI::makeChoice(ITEM_TABLE, 100, 10); // 要跟左呈討論makeChoice
    ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent", "WoodenSword", "Hammer", "GiantHammer", "MagicWand",
    "RitualSword", "WoodenShield", "PlateArmor", "LeatherArmor", "Robe", "LaurelWreath", "HolyGrail", "Shoes", "Bracelet" };
    for (const auto& pair : itemList.itemMap) {
        if (pair.first == ITEM_TABLE[choiceIndex]) {
            if (!pair.second->isStackable()) { // 由於裝備不能疊加，所以多判斷背包是否已經有裝備
                std::vector<Item*> items = player->backpack.getItems();
                for (int i = 0; i < items.size(); ++i) {
                    if (items[i] == pair.second) {
                        std::cout << "you have bought this equipment.\n"; // 要跟左呈討論display
                        return;
                    }
                }
            }
            price = pair.second->getPrice();
            money = player->GetMoney();
            if (price > money) {
                std::cout << "you can't buy.\n"; // 要跟左呈討論display
                return;
            }
            player->SetMoney(money - price);
            player->backpack.addItem(pair.second);
            return;
        }
    }
}

int Store::OpenShop() {
    std::string playerMoneyStr = "玩家持有金錢";
    playerMoneyStr.resize(44, ' ');
    playerMoneyStr += "$ ";
    std::ostringstream oss;
    oss << std::setw(3) << std::setfill(' ') << Role::GetMoney();
    playerMoneyStr += oss.str();
    oss.str("");
    oss.clear();
    UI::displayString(playerMoneyStr, 126, 26);

    std::vector<std::string> ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent", "WoodenSword", "Hammer", "GiantHammer", "MagicWand",
    "RitualSword", "WoodenShield", "PlateArmor", "LeatherArmor", "Robe", "LaurelWreath", "HolyGrail", "Shoes", "Bracelet" };
    ItemTable itemList;
    uint16_t price, money;
    int index = 0;
    for (const auto& pair : itemList.itemMap) {
        for (int i = 0; i < ITEM_TABLE.size(); ++i) {
            if (pair.first == ITEM_TABLE[i]) {
                UI::displayString("Money :        " + std::to_string(Role::GetMoney()), 70, 3);
                ITEM_TABLE[i].resize(44, ' ');
                ITEM_TABLE[i] += "$ ";
                oss << std::setw(3) << std::setfill(' ') << pair.second->getPrice();
                ITEM_TABLE[i] += oss.str();
                oss.str("");
                oss.clear();
                break;
            }
        }
    }
    int choiceIndex = UI::makeChoice(ITEM_TABLE, 126, 2);
    if (choiceIndex == -1) {
        return -1;
    }
    ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent", "WoodenSword", "Hammer", "GiantHammer", "MagicWand",
    "RitualSword", "WoodenShield", "PlateArmor", "LeatherArmor", "Robe", "LaurelWreath", "HolyGrail", "Shoes", "Bracelet" };
    for (const auto& pair : itemList.itemMap) {
        if (pair.first == ITEM_TABLE[choiceIndex]) {
            if (!pair.second->isStackable()) {
                std::vector<Item*> items = Role::backpack.getItems();
                for (int i = 0; i < items.size(); ++i) {
                    if (items[i] == pair.second) {
                        UI::logEvent("");
                        UI::logDivider("商店系統");
                        UI::logEvent("無法購買 已經有此裝備");
                        return 0;
                    }
                }
            }
            price = pair.second->getPrice();
            money = Role::GetMoney();
            if (price > money) {
                UI::logEvent("");
                UI::logDivider("商店系統");
                UI::logEvent("無法購買 金錢不足");
                return 0;
            }
            UI::logEvent("");
            UI::logDivider("商店系統");
            Role::SetMoney(money - price);
            UI::logEvent("已購買 " + pair.first + " 剩餘 $ " + std::to_string(Role::GetMoney()));
            Role::backpack.addItem(pair.second);
            return 0;
        }
    }
}