#include "../../Includes/Gadget/SkillCommandSet.h"
#include <iostream>

void AttackCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	std::cout << "Attack DiceAmount: " << caster.GetEquipment().GetWeapon().GetDiceAmount() << std::endl;
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