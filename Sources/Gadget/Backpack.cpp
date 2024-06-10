#include "Backpack.h"
#include "Item.h"
#include "Role.h"

void Backpack::addItem(Item* item) {
    if (item->isStackable()) {
        for (auto& existingItem : items) {
            if (existingItem->getName() == item->getName() && existingItem->isStackable()) {
                StackableItem* stackableItem = dynamic_cast<StackableItem*>(existingItem);
                stackableItem->addQuantity(1);
                return;
            }
        }
    }
    items.push_back(item);
}

void Backpack::useItem(const std::string& itemName, Role& role) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            if ((*it)->isStackable()) {
                (*it)->use(role);
                StackableItem* stackableItem = dynamic_cast<StackableItem*>(*it);
                stackableItem->removeQuantity(1);
                if (stackableItem->getQuantity() == 0) {
                    delete* it;
                    items.erase(it);
                }
            } else {
                role.equip((*it)->getName());
                items.erase(it);
            }
            return;
        }
    }
    std::cout << "Item not found!" << std::endl;
}

std::vector<Item*> Backpack::getItems() {
    return items;
}