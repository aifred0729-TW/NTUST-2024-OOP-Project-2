#ifndef SKILLCOMMAND_H
#define SKILLCOMMAND_H

#include <vector>

class Entity;

class SkillCommand {
public:
    virtual ~SkillCommand() = default;
    virtual void execute(Entity& caster, std::vector<Entity*> targets) {};
    virtual void execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {};
};

#endif