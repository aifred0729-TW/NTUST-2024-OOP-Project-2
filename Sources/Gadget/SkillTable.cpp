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
	activeMap["Attack"] = Active("Attack", 0, 0, new AttackCommand());
	activeMap["Flee"] = Active("Flee", 0, 1, new FleeCommand());
	activeMap["Provoke"] = Active("Provoke", 1, 3, new ProvokeCommand());
	activeMap["ShockBlast"] = Active("ShockBlast", 1, 2, new ShockBlastCommand());
	activeMap["Heal"] = Active("Heal", 1, 2, new HealCommand());
	activeMap["SpeedUp"] = Active("SpeedUp", 1, 2, new SpeedUpCommand());
}

void SkillTable::PassiveTableInitialize() {
	passiveMap["Run"] = Passive("Run", 0);
	passiveMap["HammerSplash"] = Passive("HammerSplash", 0);
	passiveMap["Destroy"] = Passive("Destroy", 0);
	passiveMap["Fortify"] = Passive("Fortify", 5);
}

void SkillTable::BuffTableInitialize() {
	buffMap["Angry"] = Buff("Angry", 0);
	buffMap["Dizziness"] = Buff("Dizziness", 0);
	buffMap["Poisoned"] = Buff("Poisoned", 0);
	buffMap["SpeedUp"] = Buff("SpeedUp", 0);
	buffMap["LaurelBuff"] = Buff("LaurelBuff", 0);
}