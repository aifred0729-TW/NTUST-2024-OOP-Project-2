#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <ItemCommand.h>

class Item {
protected:
	std::string name;
	uint16_t price;
    ItemCommand* command;

public:
    Item(std::string name, uint16_t price, ItemCommand* command) : name(name), price(price), command(command) {}
    virtual ~Item() = default;

    void setName(const std::string& name) { this->name = name; }
    void setPrice(const uint16_t& price) { this->price = price; }
    void setCommand(ItemCommand* command) { this->command = command; }
    std::string getName() const { return name; }
    uint16_t getPrice() const { return price; }
    ItemCommand* getCommand() const { return command; }

    void use(Role& role) { command->use(role); }
    virtual bool isStackable() const = 0;
};

class StackableItem : public Item {
private:
    uint16_t quantity;

public:
    StackableItem(std::string name, uint16_t price, ItemCommand* command): Item(name, price, command), quantity(1) {}

    bool isStackable() const override { return true; }
    uint16_t getQuantity() const { return quantity; }
    void setQuantity(const uint16_t& quantity) { this->quantity = quantity; }
    void addQuantity(const uint16_t& amount) { this->quantity += amount; }
    void removeQuantity(const uint16_t& amount) { quantity = (quantity >= amount) ? quantity : 0; }
};

class NonStackableItem : public Item {
public:
	NonStackableItem(std::string name, uint16_t price, ItemCommand* command): Item(name, price, command) {}

	bool isStackable() const override { return false; }
};

#endif