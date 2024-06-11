#include "../../Includes/Entity/Chest.h"
#include "ItemTable.h"
#include "Displayer.h"
#include "Backpack.h"
#include <Role.h>
// Public

void Chest::GiveTreasureTo(Role* player) {
    std::vector<std::string> ITEM_TABLE = { "Godsbeard", "GoldenRoot", "TeleportScroll", "Tent"};
    using namespace Displayer;
    ItemTable itemList;
    uint16_t money, treasure;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int choiceIndex = rand() % (ITEM_TABLE.size() + 1);
    for (const auto& pair : itemList.itemMap) {
        if (choiceIndex == ITEM_TABLE.size()) {
            money = player->GetMoney();
            treasure = (rand() % 500) + 1;
            player->SetMoney(money + treasure);
            std::cout << "you get money.\n"; // 要跟左呈討論display
            return;
        }
        else if (pair.first == ITEM_TABLE[choiceIndex]) {
            player->backpack.addItem(pair.second);
            std::cout << "you get an item.\n"; // 要跟左呈討論display
            return;
        }
    }
}