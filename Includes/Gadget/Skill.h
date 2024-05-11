#pragma once
#include <cstdint>

#include "../Entity/Entity.h"
#include "../Gadget/Dice.h"
#include "../ConstData.h"

// skillTable[ATTACK]();
// Used ATTACK¡Acorresponding to ApplyAttack function
// #include <cstdint>

class Skill {
private:
	uint8_t   skillID;           // Skill ID
	uint8_t   coolDownTime;      // Skill CD
	Dice      dice;              // Dice
	Entity* skillUser;           // Role of use skill
	std::vector<Entity*> skillTargets; // Target of skill

	// Skill Table (need initialize)
	static void (* const skillTable[SKILL_TOTAL_SIZE])(void);

private:
	static void ApplyAttack(void);       // Skill - Attack
	static void ApplyFlee(void);         // Skill - Flee
	static void ApplyProvoke(void);      // Skill - Provoke
	static void ApplyShockBlast(void);   // Skill - Shock Blast
	static void ApplyHeal(void);         // Skill - Heal
	static void ApplySpeedUp(void);      // Skill - Speed Up
	static void ApplyRun(void);          // Skill - Run
	static void ApplyHammerSplash(void); // Skill - Hammer Splash
	static void ApplyDestory(void);      // Skill - Destory
	static void ApplyFortify(void);      // Skill - Fortify
	static void ApplySKILL111(void);     // Skill - Custom 1
	static void ApplySKILL222(void);     // Skill - Custom 2
	static void ApplySKILL333(void);     // Skill - Custom 3

public:
	// Use Skill (SkillType, Skilluser, Skilltarget)
	void ApplySkill(uint8_t, Entity*, std::vector<Entity*>);
};