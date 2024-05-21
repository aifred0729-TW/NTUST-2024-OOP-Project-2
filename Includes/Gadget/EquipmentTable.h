#ifndef EQUIPMENTTABLE_H
#define EQUIPMENTTABLE_H

#include <map>
#include <string>
#include "Equipment.h"

class EquipmentTable {
public:
    static std::map<std::string, Equipment> equipmentMap;

    static void Initialize();
};

#endif
