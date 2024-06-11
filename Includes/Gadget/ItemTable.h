#ifndef ITEMTABLE_H
#define ITEMTABLE_H

#include <map>
#include <string>

class Item;

class ItemTable {
private:
    static void ItemTableInitialize();

public:
    static std::map<std::string, Item*> itemMap;

    static void Initialize();
    static Item* getItem(const std::string& name);
};

#endif