#ifndef CONTAIN_H
#define CONTAIN_H

#include <vector>
#include <cstdint>
#include <ConstData.h>

// itemTable[COIN]();
// Used COIN，corresponding to ApplyCoin function
// #include <vector>

class Role;

class Contain {
private:
    std::string name;
    std::string type; // ITEM, EQUIPMENT
    uint8_t amount;

public:
    Contain();
    Contain(std::string name, std::string type);

    void SetName(const std::string&);
    void SetType(const std::string&);
    void SetAmount(const uint8_t&);

    std::string GetName() const;
    std::string GetType() const;
    uint8_t GetAmount() const;

    void useContain();
};

#endif