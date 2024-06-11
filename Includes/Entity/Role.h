#ifndef ROLE_H
#define ROLE_H

#include <cstdint>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <Entity.h>

class Backpack;

class Role : public Entity {
private:
    uint8_t movementPoint;
    uint32_t step;
    std::pair<uint32_t, uint32_t> position;
    static uint16_t money;
public:
    static Backpack backpack;

    Role();  // Default constructor
    Role(std::string name);  // Constructor with name (Role Name
    Role(std::string name, int x, int y);

    void SetMovementPoint(const uint8_t);
    void SetStep(const uint32_t);
    void SetPosition(const std::pair<uint32_t, uint32_t>&);
    static void SetMoney(const uint16_t);

    bool movePos(int x, int y);
    bool movePos(std::pair<int, int>);

    uint8_t GetMovementPoint() const;
    uint32_t GetStep() const;
    std::pair<uint32_t, uint32_t> GetPosition() const;
    static uint16_t GetMoney();

public:
    void addItemToBackpack(const std::string& name);
    void useItemFromBackpack(const std::string& name);

    void equip(const std::string& name);
    void unEquip(const std::string& name);
};

#endif