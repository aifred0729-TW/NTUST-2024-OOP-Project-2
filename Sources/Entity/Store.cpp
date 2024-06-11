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

void Store::SellItemTo() {
    std::vector<std::string> ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent", "WoodenSword", "Hammer", "GiantHammer", "MagicWand",
    "RitualSword", "WoodenShield", "PlateArmor", "LeatherArmor", "Robe", "LaurelWreath", "HolyGrail", "Shoes", "Bracelet" };
    ItemTable itemList;
    uint16_t price, money;
    int index = 0;
    for (const auto& pair : itemList.itemMap) {
        for (int i = 0; i < ITEM_TABLE.size(); ++i) {
            if (pair.first == ITEM_TABLE[i]) {
                ITEM_TABLE[i].resize(45, ' ');
                ITEM_TABLE[i] += "$ ";
                ITEM_TABLE[i] += std::to_string(pair.second->getPrice());
                break;
            }
        }
    }
    int choiceIndex = UI::makeChoice(ITEM_TABLE, 126, 2); // 要跟左呈討論makeChoice
    ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent", "WoodenSword", "Hammer", "GiantHammer", "MagicWand",
    "RitualSword", "WoodenShield", "PlateArmor", "LeatherArmor", "Robe", "LaurelWreath", "HolyGrail", "Shoes", "Bracelet" };
    for (const auto& pair : itemList.itemMap) {
        if (pair.first == ITEM_TABLE[choiceIndex]) {
            if (!pair.second->isStackable()) { // 由於裝備不能疊加，所以多判斷背包是否已經有裝備
                std::vector<Item*> items = Role::backpack.getItems();
                for (int i = 0; i < items.size(); ++i) {
                    if (items[i] == pair.second) {
                        std::cout << "you have bought this equipment.\n"; // 要跟左呈討論display
                        return;
                    }
                }
            }
            price = pair.second->getPrice();
            money = Role::GetMoney();
            if (price > money) {
                std::cout << "you can't buy.\n"; // 要跟左呈討論display
                return;
            }
            Role::SetMoney(money - price);
            Role::backpack.addItem(pair.second);
            return;
        }
    }
}