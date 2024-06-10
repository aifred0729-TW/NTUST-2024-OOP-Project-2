#ifndef BACKPACK_H
#define BACKPACK_H

#include <vector>
#include <string>

class Item;
class Role;

class Backpack {
private:
    std::vector<Item*> items;

public:
    Backpack() : items(std::vector<Item*>(0)) {}

    void addItem(Item* item);
    void useItem(const std::string& name, Role& entity);
    std::vector<Item*> getItems();
};

#endif
