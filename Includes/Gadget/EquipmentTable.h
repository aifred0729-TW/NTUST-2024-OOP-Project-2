#ifndef EQUIPMENTTABLE_H
#define EQUIPMENTTABLE_H

#include <map>
#include <string>
#include "Equipment.h"

class EquipmentTable {
private:
	static void WeaponTableInitialize();
    static void ArmorTableInitialize();
    static void AccessoryTableInitialize();

public:
    static std::map<std::string, Weapon> weaponMap;
    static std::map<std::string, Armor> armorMap;
    static std::map<std::string, Accessory> accessoryMap;

    static void Initialize();
};

#endif
