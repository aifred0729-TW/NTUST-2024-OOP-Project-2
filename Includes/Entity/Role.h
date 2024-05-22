#ifndef ROLE_H
#define ROLE_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include "Entity.h"
#include "Item.h"
#include "Equipment.h"
#include "EquipmentTable.h"

class Role : public Entity {
private:
    Item pack;
    uint8_t movementPoint;
    uint32_t step;
    std::pair<uint32_t, uint32_t> position;

public:
    Role();  // Default constructor

    void SetPack(const Item&);
    void SetMovementPoint(const uint8_t);
    void SetStep(const uint32_t);
    void SetPosition(const std::pair<uint32_t, uint32_t>&);

    Item GetPack(void);
    uint8_t GetMovementPoint(void);
    uint32_t GetStep(void);
    std::pair<uint32_t, uint32_t> GetPosition(void);

public:
};

#endif
