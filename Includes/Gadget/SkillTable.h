#ifndef SKILLTABLE_H
#define SKILLTABLE_H

#include <map>
#include <string>
#include "Skill.h"
#include "SkillCommandSet.h"

class SkillTable {
private:
    static void ActiveTableInitialize();
    static void PassiveTableInitialize();
    static void BuffTableInitialize();

public:
    static std::map<std::string, Active> activeMap;
    static std::map<std::string, Passive> passiveMap;
    static std::map<std::string, Buff> buffMap;

    static void Initialize();
};

#endif