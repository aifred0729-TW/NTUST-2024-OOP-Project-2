#ifndef SKILL_H
#define SKILL_H

#include <cstdint>
#include <vector>
#include "Dice.h"
#include "ConstData.h"

class Entity;

enum SkillType {
    ACTIVE,
    PASSIVE
};

class Skill {
private:
    std::string name;
    SkillType type;

public:
    Skill();
    Skill(const std::string& name, SkillType type);

    // Setter and Getter for skill
    void SetName(const std::string& name);
    void SetType(SkillType type);

    std::string GetName() const;
    SkillType GetType() const;

    // Apply the skill
    void Apply(Entity* user, std::vector<Entity*> targets);

    bool operator==(const Skill& other) const {
        return name == other.name && type == other.type;
    }

    struct HashFunction {
        std::size_t operator()(const Skill& skill) const {
            return std::hash<std::string>()(skill.name) ^ std::hash<int>()(static_cast<int>(skill.type));
        }
    };
};

#endif
