#include "Backpack.h"
#include "Item.h"
#include "Role.h"

void Backpack::addItem(Item* item) {
    if (item->isStackable()) {
        for (auto& existingItem : items) {
            if (existingItem->getName() == item->getName() && existingItem->isStackable()) {
                StackableItem* stackableItem = dynamic_cast<StackableItem*>(existingItem);
                stackableItem->addQuantity(dynamic_cast<StackableItem*>(item)->getQuantity());
                delete item;
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
            }
            return;
        }
    }
    std::cout << "Item not found!" << std::endl;
}