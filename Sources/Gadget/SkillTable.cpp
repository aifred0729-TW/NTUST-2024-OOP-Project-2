#include "SkillTable.h"
#include "SkillCommandSet.h"
#include "Skill.h"

std::map<std::string, Active> SkillTable::activeMap;
std::map<std::string, Passive> SkillTable::passiveMap;
std::map<std::string, Buff> SkillTable::buffMap;

void SkillTable::Initialize() {
    SkillTable::ActiveTableInitialize();
    SkillTable::PassiveTableInitialize();
    SkillTable::BuffTableInitialize();
}

void SkillTable::ActiveTableInitialize() {
    activeMap["Attack"] = Active("Attack", 0, 1, new AttackActiveCommand(), 1);
    activeMap["Flee"] = Active("Flee", 0, 1, new FleeActiveCommand(), 0);
    activeMap["Provoke"] = Active("Provoke", 2, 1, new ProvokeActiveCommand(), 1);
    activeMap["ShockBlast"] = Active("ShockBlast", 1, 3, new ShockBlastActiveCommand(), 2);
    activeMap["Heal"] = Active("Heal", 1, 2, new HealActiveCommand(), 3);
    activeMap["SpeedUp"] = Active("SpeedUp", 3, 2, new SpeedUpActiveCommand(), 3);
}

void SkillTable::PassiveTableInitialize() {
    passiveMap["Run"] = Passive("Run", 0, new RunPassiveCommand(), 0);
    passiveMap["HammerSplash"] = Passive("HammerSplash", 0, new HammerSplashPassiveCommand(), 2);
    passiveMap["Destroy"] = Passive("Destroy", 0, new DestroyPassiveCommand(), 1);
    passiveMap["Fortify"] = Passive("Fortify", 5, new FortifyPassiveCommand(), 0);
}

void SkillTable::BuffTableInitialize() {
	buffMap["Angry"] = Buff("Angry", nullptr, 0);
	buffMap["Dizziness"] = Buff("Dizziness", nullptr, 0);
	buffMap["Poisoned"] = Buff("Poisoned", nullptr, 0);
	buffMap["SpeedUp"] = Buff("SpeedUp", nullptr, 0);
}