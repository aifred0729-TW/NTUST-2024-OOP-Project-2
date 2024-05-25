#ifndef SKILLCOMMAND_H
#define SKILLCOMMAND_H

#include <vector>

class Entity;

class SkillCommand {
public:
    virtual ~SkillCommand() = default;
    virtual void execute(Entity& caster, std::vector<Entity*> targets) = 0;
};

#endif