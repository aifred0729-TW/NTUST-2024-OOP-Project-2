#include "../../Includes/Gadget/SkillCommandSet.h"
#include <iostream>

void AttackCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	int damage = 10;
	targets[0]->GetAttribute().SetHP(targets[0]->GetAttribute().GetHP() - damage);
	std::cout << "Attack caused " << damage << " damage to the targets." << std::endl;
}

void WoodenSwordAttackCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Wooden Sword Attack caused " << " damage to the targets." << std::endl;
}

void HammerAttackCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Hammer Attack caused " << " damage to the targets." << std::endl;
}

void GiantHammerAttackCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Giant Hammer Attack caused " << " damage to the targets." << std::endl;
}

void MagicWandAttackCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Magic Wand Attack caused " << " damage to the targets." << std::endl;
}

void RitualSwordAttackCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Ritual Sword Attack caused " << " damage to the targets." << std::endl;
}

void FleeCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Caster has fled from the battle." << std::endl;
}

void ProvokeCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Caster has provoked the targets." << std::endl;
}

void ShockBlastCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Shock Blast caused " << " damage to the targets." << std::endl;
}

void HealCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Heal restored " << " HP to the caster." << std::endl;
}

void SpeedUpCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Speed Up increased caster's speed by " << "." << std::endl;
}