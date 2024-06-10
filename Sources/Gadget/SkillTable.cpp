#include "SkillTable.h"

std::map<std::string, Active> SkillTable::activeMap;
std::map<std::string, Passive> SkillTable::passiveMap;
std::map<std::string, Buff> SkillTable::buffMap;

void SkillTable::Initialize() {
    SkillTable::ActiveTableInitialize();
    SkillTable::PassiveTableInitialize();
    SkillTable::BuffTableInitialize();
}

void SkillTable::ActiveTableInitialize() {
    activeMap["Attack"] = Active("Attack", 0, 1, new AttackCommand(), 1);
    activeMap["Flee"] = Active("Flee", 0, 1, new FleeCommand(), 0);
    activeMap["Provoke"] = Active("Provoke", 2, 1, new ProvokeCommand(), 1);
    activeMap["ShockBlast"] = Active("ShockBlast", 1, 3, new ShockBlastCommand(), 2);
    activeMap["Heal"] = Active("Heal", 1, 2, new HealCommand(), 3);
    activeMap["SpeedUp"] = Active("SpeedUp", 3, 2, new SpeedUpCommand(), 3);
}

void SkillTable::PassiveTableInitialize() {
    passiveMap["Run"] = Passive("Run", 0, nullptr, 0);
    passiveMap["HammerSplash"] = Passive("HammerSplash", 0, nullptr, 2);
    passiveMap["Destroy"] = Passive("Destroy", 0, nullptr, 1);
    passiveMap["Fortify"] = Passive("Fortify", 5, nullptr, 0);
}

void SkillTable::BuffTableInitialize() {
	buffMap["Angry"] = Buff("Angry", nullptr, 0);
	buffMap["Dizziness"] = Buff("Dizziness", nullptr, 0);
	buffMap["Poisoned"] = Buff("Poisoned", nullptr, 0);
	buffMap["SpeedUp"] = Buff("SpeedUp", nullptr, 0);
	buffMap["LaurelBuff"] = Buff("LaurelBuff", nullptr, 0);
}