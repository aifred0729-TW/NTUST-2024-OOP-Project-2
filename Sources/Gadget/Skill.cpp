#include "Skill.h"
#include <iostream>  // For demonstration purposes

Skill::Skill() : name("DefaultSkill"), type(SkillType::ACTIVE) {}
Skill::Skill(const std::string& name, SkillType type): name(name), type(type) {}

void Skill::SetName(const std::string& name) {
    this->name = name;
}

std::string Skill::GetName() const {
    return name;
}

void Skill::SetType(SkillType type) {
    this->type = type;
}

SkillType Skill::GetType() const {
    return type;
}

void Skill::Apply(Entity* user, std::vector<Entity*> targets) {
    std::cout << "Applying skill: " << name << " by user" << std::endl;
    // Add the logic to apply the skill effects
}