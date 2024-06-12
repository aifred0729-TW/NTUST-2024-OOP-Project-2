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
    activeMap["Provoke"] = Active("Provoke", 3, 1, new ProvokeActiveCommand(), 1);
    activeMap["ShockBlast"] = Active("ShockBlast", 2, 3, new ShockBlastActiveCommand(), 2);
    activeMap["Heal"] = Active("Heal", 2, 2, new HealActiveCommand(), 3);
    activeMap["SpeedUp"] = Active("SpeedUp", 4, 2, new SpeedUpActiveCommand(), 3);
}

void SkillTable::PassiveTableInitialize() {
    passiveMap["Run"] = Passive("Run", 0, new RunPassiveCommand(), 0);
    passiveMap["HammerSplash"] = Passive("HammerSplash", 0, new HammerSplashPassiveCommand(), 2);
    passiveMap["Destroy"] = Passive("Destroy", 0, new DestroyPassiveCommand(), 1);
    passiveMap["Fortify"] = Passive("Fortify", 6, new FortifyPassiveCommand(), 0);
}

void SkillTable::BuffTableInitialize() {
	buffMap["Angry"] = Buff("Angry", new AngryBuffCommand(), new AngryBuffDeConstructCommand(), 0);
	buffMap["Dizziness"] = Buff("Dizziness", new DizzinessBuffCommand(), nullptr, 0);
	buffMap["Poisoned"] = Buff("Poisoned", new PoisonedBuffCommand(), nullptr, 0);
	buffMap["SpeedUp"] = Buff("SpeedUp", new SpeedUpBuffCommand(), new SpeedUpBuffDeConstructCommand(), 0);
}