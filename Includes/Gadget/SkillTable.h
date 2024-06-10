#ifndef SKILLTABLE_H
#define SKILLTABLE_H

#include <map>
#include <string>

class Active;
class Passive;
class Buff;

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