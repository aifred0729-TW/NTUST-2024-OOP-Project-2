#ifndef ACTIVE_H
#define ACTIVE_H

#include <vector> 

#include "Dice.h"
#include "Attribute.h"
#include "SkillCommand.h"

class Entity;

class Active {
private:
    std::string name;
    uint8_t cooldown;
    uint8_t diceAmount;
    SkillCommand* command;
    uint8_t targetType = 0;
public:
    Active();
    Active(std::string name, uint8_t cooldown, uint8_t diceAmount, SkillCommand* command);
    //targetType: 1敵方單體 2敵方全體 3友方單體 4友方全體 5自身
    Active(std::string name, uint8_t cooldown, uint8_t diceAmount, SkillCommand* command, uint8_t targetType);

    std::string GetName() const;
    uint8_t GetCooldown() const;
    uint8_t GetDiceAmount() const;

    void SetName(const std::string&);
    void SetCooldown(const uint8_t&);
    void SetDiceAmount(const uint8_t&);

public:
    void apply(Entity& caster, std::vector<Entity*> targets);
};

#endif