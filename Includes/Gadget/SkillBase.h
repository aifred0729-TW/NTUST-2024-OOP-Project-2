﻿#ifndef SKILL_BASE_H
#define SKILL_BASE_H

#include <vector> 
#include <string>

#include <SkillCommand.h>

class Attribute;

class SkillBase {
protected:
    std::string name;
    SkillCommand* command;
    uint8_t tick;
    uint8_t targetType;

public:
    SkillBase();
    SkillBase(std::string name, SkillCommand* command, uint8_t targetType);

    std::string GetName() const { return name; }
    SkillCommand* GetCommand() const { return command; }
    uint8_t GetTick() const { return tick; }
    uint8_t GetTargetType() const { return targetType; }
    void SetName(const std::string& name) { this->name = name; }
    void SetCommand(SkillCommand* command) { this->command = command; }
    void SetTick(const uint8_t& tick) { this->tick = tick; }
    void SetTargetType(const uint8_t& targetType) { this->targetType = targetType; }

    bool operator==(const SkillBase& other) const {
        return name == other.name;
    }

public:
    virtual void apply(Entity& caster, std::vector<Entity*> targets) {};
};

class Buff : public SkillBase {
public:
    Buff();
    Buff(std::string name, SkillCommand* command, uint8_t targetType);
};

class Passive : public SkillBase {
private:
    uint8_t coolDown;

public:
    Passive();
    Passive(std::string name, uint8_t coolDown, SkillCommand* command, uint8_t targetType);

    uint8_t GetCoolDown() const { return coolDown; }
    void SetCoolDown(const uint8_t& coolDown) { this->coolDown = coolDown; }
};

class Entity;

class Active : public SkillBase {
private:
    uint8_t coolDown;
    uint8_t diceAmount;

public:
    Active();
    //targetType: 0自身 1敵方單體 2敵方全體 3友方單體 4友方全體
    Active(std::string name, uint8_t cooldown, uint8_t diceAmount, SkillCommand* command, uint8_t targetType);

    uint8_t GetCoolDown() const { return coolDown; }
    uint8_t GetDiceAmount() const { return diceAmount; }
    void SetCoolDown(const uint8_t& coolDown) { this->coolDown = coolDown; }
    void SetDiceAmount(const uint8_t& diceAmount) { this->diceAmount = diceAmount; }

    void apply(Entity& caster, std::vector<Entity*> targets) override;
};

#endif