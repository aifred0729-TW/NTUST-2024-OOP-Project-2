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
	activeMap["Attack"] = Active("Attack", 0, 1);
	activeMap["WoodenSwordAttack"] = Active("WoodenSwordAttack", 0, 3);
	activeMap["HammerAttack"] = Active("HammerAttack", 0, 4);
	activeMap["GiantHammerAttack"] = Active("GiantHammerAttack", 0, 5);
	activeMap["MagicWandAttack"] = Active("MagicWandAttack", 0, 3);
	activeMap["RitualSwordAttack"] = Active("RitualSwordAttack", 0, 4);

	activeMap["Flee"] = Active("Flee", 0, 1);
	activeMap["Provoke"] = Active("Provoke", 1, 3);
	activeMap["ShockBlast"] = Active("ShockBlast", 1, 2);
	activeMap["Heal"] = Active("Heal", 1, 2);
	activeMap["SpeedUp"] = Active("SpeedUp", 1, 2);
}

void SkillTable::PassiveTableInitialize() {
	passiveMap["Run"] = Passive("Run", 0);
	passiveMap["HammerSplash"] = Passive("HammerSplash", 0);
	passiveMap["Destroy"] = Passive("Destroy", 0);
	passiveMap["Fortify"] = Passive("Fortify", 5);
}

void SkillTable::BuffTableInitialize() {
	buffMap["Angry"] = Buff("Angry");
	buffMap["Dizziness"] = Buff("Dizziness");
	buffMap["Poisoned"] = Buff("Poisoned");
	buffMap["SpeedUp"] = Buff("SpeedUp");
	buffMap["LaurelBuff"] = Buff("LaurelBuff");
}