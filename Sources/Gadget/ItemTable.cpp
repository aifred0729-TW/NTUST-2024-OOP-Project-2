#include "ItemTable.h"
#include "Item.h"
#include "ItemCommandSet.h"

std::map<std::string, Item*> ItemTable::itemMap;

void ItemTable::Initialize() {
    ItemTable::ItemTableInitialize();
}

void ItemTable::ItemTableInitialize() {
    srand(114514);
    itemMap["Godsbeard"] = new StackableItem("Godsbeard", (rand() % 19 + 1) * 5, new GodsbeardCommand());
    itemMap["GoldenRoot"] = new StackableItem("GoldenRoot", (rand() % 19 + 1) * 5, new GoldenRootCommand());
    itemMap["TeleportScroll"] = new StackableItem("TeleportScroll", (rand() % 19 + 1) * 5, new TeleportScrollCommand());
    itemMap["Tent"] = new StackableItem("Tent", (rand() % 19 + 1) * 5, new TentCommand());

    itemMap["WoodenSword"] = new NonStackableItem("WoodenSword", (rand() % 19 + 1) * 5, nullptr);
    itemMap["Hammer"] = new NonStackableItem("Hammer", (rand() % 19 + 1) * 5, nullptr);
    itemMap["GiantHammer"] = new NonStackableItem("GiantHammer", (rand() % 19 + 1) * 5, nullptr);
    itemMap["MagicWand"] = new NonStackableItem("MagicWand", (rand() % 19 + 1) * 5, nullptr);
    itemMap["RitualSword"] = new NonStackableItem("RitualSword", (rand() % 19 + 1) * 5, nullptr);
    itemMap["WoodenShield"] = new NonStackableItem("WoodenShield", (rand() % 19 + 1) * 5, nullptr);
    itemMap["PlateArmor"] = new NonStackableItem("PlateArmor", (rand() % 19 + 1) * 5, nullptr);
    itemMap["LeatherArmor"] = new NonStackableItem("LeatherArmor", (rand() % 19 + 1) * 5, nullptr);
    itemMap["Robe"] = new NonStackableItem("Robe", (rand() % 19 + 1) * 5, nullptr);
    itemMap["LaurelWreath"] = new NonStackableItem("LaurelWreath", (rand() % 19 + 1) * 5, nullptr);
    itemMap["HolyGrail"] = new NonStackableItem("HolyGrail", (rand() % 19 + 1) * 5, nullptr);
    itemMap["Shoes"] = new NonStackableItem("Shoes", (rand() % 19 + 1) * 5, nullptr);
    itemMap["Bracelet"] = new NonStackableItem("Bracelet", (rand() % 19 + 1) * 5, nullptr);
}

Item* ItemTable::getItem(const std::string& name) {
    auto it = itemMap.find(name);
    return it != itemMap.end() ? it->second : nullptr;
}
