#include <iostream>

#include "../../Includes/Gadget/SkillCommandSet.h"
#include "../../Includes/Gadget/SkillTable.h"

void AttackCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	auto casterWeapon = caster.GetEquipment().GetWeapon();
	auto cta = caster.GetTotalAttribute();

	auto& casterDice = caster.GetDice();
	casterDice.resize(casterWeapon.GetDiceAmount());
	casterDice.SetSuccessRate(std::vector<uint8_t>(casterDice.GetAmount(), cta.GetACC()));
	casterDice.RollDice();

	int16_t damage = static_cast<int16_t>(cta.GetPA());
	std::cout << caster.GetName() << " 的 Attack 理想攻擊力為 " << damage << std::endl;
	casterDice.displayResult();
	damage = static_cast<int16_t>(damage * ((double)casterDice.GetMovementPoint() / casterDice.GetAmount()));
	std::string attackType = casterWeapon.GetAttackType() == 'P' ? "物理" : "魔法";
	std::cout << caster.GetName() << " 施放了攻擊力 " << damage << " 的" << attackType << "攻擊！" << std::endl;

	targets[0]->takeDamage(damage, casterWeapon.GetAttackType());
}

void FleeCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	auto cta = caster.GetTotalAttribute();

	auto& casterDice = caster.GetDice();
	casterDice.resize(1);
	uint8_t successRate = static_cast<uint8_t>((double)cta.GetHP() * (cta.GetSPD()) * 100 / (cta.GetMaxHP() + cta.GetMD() + cta.GetPD()));
	successRate = successRate > 98 ? 98 : successRate;
	std::cout << caster.GetName() << " 的成功逃跑機率為 " << (unsigned)successRate << "%" << std::endl;
	casterDice.SetSuccessRate(std::vector<uint8_t>(1, successRate));
	casterDice.RollDice();
	casterDice.displayResult();

	if (casterDice.GetMovementPoint() == 1) {
		std::cout << caster.GetName() << " 逃跑成功！！" << std::endl;
		// ctargets[0]->SetStatus(逃跑狀態);
	} else {
		std::cout << caster.GetName() << " 逃跑失敗，繼續坐牢。" << std::endl;
	}
}

void ProvokeCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	auto cta = caster.GetTotalAttribute();
	
	auto& casterDice = caster.GetDice();
	casterDice.resize(1);
	uint8_t successRate = static_cast<uint8_t>((double)cta.GetHP() / ((cta.GetMaxHP() + cta.GetMD() + cta.GetPA())));
	casterDice.SetSuccessRate(std::vector<uint8_t>(1, successRate));
	std::cout << caster.GetName() << " 的 Provoke 成功機率為 " << (unsigned)successRate << "%" << std::endl;
	casterDice.RollDice();
	casterDice.displayResult();

	if (casterDice.GetAmount() == 1) {
		std::cout << "挑釁成功，現在 " << targets[0]->GetName() << " 很想把 " << caster.GetName() << " 爆幹一頓。" << std::endl;
		// targets[0]->SetStatus(挑釁狀態);
	} else {
		std::cout << "挑釁失敗，" << targets[0]->GetName() << "只把" << caster.GetName() << " 當小丑。" << std::endl;
	}
}

void ShockBlastCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	auto casterWeapon = caster.GetEquipment().GetWeapon();
	auto cta = caster.GetTotalAttribute();

	auto& casterDice = caster.GetDice();
	casterDice.resize(3);
	casterDice.SetSuccessRate(std::vector<uint8_t>(3, cta.GetACC() - 5));
	casterDice.RollDice();

	int16_t damage = static_cast<int16_t>((double)((double)cta.GetMA() / 2));
	std::cout << caster.GetName() << " 的 ShockBlast 理想攻擊力為 " << damage << std::endl;
	casterDice.displayResult();
	damage = static_cast<int16_t>((double)((double)cta.GetMA() / 2) * ((double)casterDice.GetMovementPoint() / casterDice.GetAmount()));
	std::string attackType = casterWeapon.GetAttackType() == 'P' ? "物理" : "魔法";
	std::cout << caster.GetName() << " 對全體敵人施放了 " << damage << " 的" << attackType << "攻擊！" << std::endl;
	for (auto target : targets) {
		target->takeDamage(damage, casterWeapon.GetAttackType());
	}
}

void HealCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	auto cta = caster.GetTotalAttribute();

	auto& casterDice = caster.GetDice();
	casterDice.resize(3);
	casterDice.SetSuccessRate(std::vector<uint8_t>(3, cta.GetACC()));
	casterDice.RollDice();

	int16_t heal = static_cast<int16_t>((double)cta.GetMA() * 1.5);
	std::cout << caster.GetName() << " 的 Heal 理想治療量為 " << heal << std::endl;
	casterDice.displayResult();
	heal = static_cast<int16_t>(heal * ((double)casterDice.GetMovementPoint() / casterDice.GetAmount()));
	std::cout << caster.GetName() << " 對 "<< targets[0]->GetName() << " 施放了 " << heal << " 的治療！" << std::endl;
	targets[0]->heal(heal);
}

void SpeedUpCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	auto cta = caster.GetTotalAttribute();

	auto& casterDice = caster.GetDice();
	casterDice.resize(2);
	casterDice.SetSuccessRate(std::vector<uint8_t>(2, cta.GetACC()));
	std::cout << caster.GetName() << " 的 Speed Up 成功機率為 " << (unsigned)cta.GetACC() << "%" << std::endl;
	casterDice.RollDice();

	if (casterDice.GetMovementPoint() == 2) {
		std::cout << caster.GetName() << " 的 Speed Up 成功！給予 " << targets[0]->GetName() << " 1回合的 SpeedUp Buff。" << std::endl;
		// 給予SpeedUp Buff一回合
		Buff SpeedUp = SkillTable::buffMap.find("SpeedUp")->second;
		targets[0]->GetSkill().pushBuff(SpeedUp);
	} else {
		std::cout << caster.GetName() << " 的 Speed Up 失敗！" << std::endl;
	}
}