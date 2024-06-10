#include "../../Includes/Entity/Store.h"
#include "ItemTable.h"
#include "Displayer.h"

// Public

void Store::SellItemTo(Role* player) {
    std::vector<std::string> ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent", "WoodenSword", "Hammer", "GiantHammer", "MagicWand",
    "RitualSword", "WoodenShield", "PlateArmor", "LeatherArmor", "Robe", "LaurelWreath", "HolyGrail", "Shoes", "Bracelet" };
    using namespace Displayer;
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
    int choiceIndex = makeChoice(ITEM_TABLE, 100, 10); // 要跟左呈討論makeChoice
    ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent", "WoodenSword", "Hammer", "GiantHammer", "MagicWand",
    "RitualSword", "WoodenShield", "PlateArmor", "LeatherArmor", "Robe", "LaurelWreath", "HolyGrail", "Shoes", "Bracelet" };
    for (const auto& pair : itemList.itemMap) {
        if (pair.first == ITEM_TABLE[choiceIndex]) {
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