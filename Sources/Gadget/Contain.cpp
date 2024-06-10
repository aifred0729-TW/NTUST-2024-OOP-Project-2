#include "Contain.h"

#include <vector>
#include <cstdint>
#include <string>
#include <ConstData.h>

class Role;
/*
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
*/

Contain::Contain()
	: name(""), type(""), amount(0) {}
Contain::Contain(std::string name, std::string type)
	: name(name), type(type), amount(0) {}