﻿#include <SkillCommandSet.h>
#include <SkillTable.h>
#include "SkillCommand.h"
#include <UI.h>
#include <Dice.h>
#include "Entity.h"

void AttackActiveCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto casterWeapon = caster.GetEquipment().GetWeapon();
    auto cta = caster.GetTotalAttribute();
    int16_t damage = casterWeapon.GetAttackType() == 'P' ? static_cast<int16_t>(cta.GetPA()) : static_cast<int16_t>(cta.GetMA());
    UI::logEvent(caster.GetName() + " 的 Attack 理想攻擊力為 " + std::to_string(damage));
    targets[0]->SetlastDamage(damage);

    auto& casterDice = caster.GetDice();
    casterDice.resize(casterWeapon.GetDiceAmount());
    casterDice.SetSuccessRate(std::vector<uint8_t>(casterDice.GetAmount(), cta.GetACC()));
    casterDice.RollDice();
    casterDice.displayResult();
    damage = static_cast<int16_t>(damage * ((double)casterDice.GetMovementPoint() / casterDice.GetAmount()));
    std::string attackType = casterWeapon.GetAttackType() == 'P' ? "物理" : "魔法";

    UI::logEvent(caster.GetName() + " 施放了攻擊力 " + std::to_string(damage) + " 的" + attackType + "攻擊！");

    targets[0]->takeDamage(damage, casterWeapon.GetAttackType());
}

void FleeActiveCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    uint8_t successRate = static_cast<uint8_t>((double)cta.GetHP() * (cta.GetSPD()) / (cta.GetMaxHP() + cta.GetMD() + cta.GetPD()));
    successRate = successRate > 98 ? 98 : successRate;
    UI::logEvent(caster.GetName() + " 的成功逃跑機率為 " + std::to_string((unsigned)successRate) + "%");
        
    casterDice.SetSuccessRate(std::vector<uint8_t>(1, successRate));
    casterDice.RollDice();
    casterDice.displayResult();

    if (casterDice.GetMovementPoint() == 1) {
        UI::logEvent(caster.GetName() + " 逃跑成功！！");
        targets[0]->SetStatus(targets[0]->GetStatus() | RETREAT);
    } else {
        UI::logEvent(caster.GetName() + " 逃跑失敗，繼續坐牢。");
    }
}

void ProvokeActiveCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    uint8_t successRate = static_cast<uint8_t>(1, (double)cta.GetHP() / ((cta.GetMaxHP() + cta.GetMD() + cta.GetPA())) * 100);
    casterDice.SetSuccessRate(std::vector<uint8_t>(1, successRate));
    UI::logEvent(caster.GetName() + " 的 Provoke 成功機率為 " + std::to_string((unsigned)successRate) + "%");
    casterDice.RollDice();
    casterDice.displayResult();
    targets[0]->SetlastDamage(0);

    if (casterDice.GetMovementPoint() == 1) {
        UI::logEvent("挑釁成功，現在 " + targets[0]->GetName() + " 很躁。");
        targets[0]->addBuff("Angry", 3);
    } else {
        UI::logEvent("挑釁失敗，" + targets[0]->GetName() + " 只把 " + caster.GetName() + " 當小丑。");
    }
}

void ShockBlastActiveCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto casterWeapon = caster.GetEquipment().GetWeapon();
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    casterDice.SetSuccessRate(std::vector<uint8_t>(diceAmount, cta.GetACC() - 5));
    casterDice.RollDice();
    int16_t damage = static_cast<int16_t>((double)((double)cta.GetMA() / 2));
    UI::logEvent(caster.GetName() + " 的 ShockBlast 理想攻擊力為 " + std::to_string(damage));

    casterDice.displayResult();
    damage = static_cast<int16_t>((double)((double)cta.GetMA() / 2) * ((double)casterDice.GetMovementPoint() / casterDice.GetAmount()));
    std::string attackType = casterWeapon.GetAttackType() == 'P' ? "物理" : "魔法";

    UI::logEvent(caster.GetName() + " 對全體敵人施放了 " + std::to_string(damage) + " 的" + attackType + "攻擊！");
    
    bool perfect = casterDice.GetAmount() == casterDice.GetMovementPoint();
    if (perfect)
        UI::logEvent("完美擲骰，敵人全體受到內傷");
    for (auto target : targets) {
        target->takeDamage(damage, casterWeapon.GetAttackType());
        // 中毒好怪
        if (perfect)
            target->addBuff("Poisoned", 2);
    }
}

void HealActiveCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    casterDice.SetSuccessRate(std::vector<uint8_t>(diceAmount, cta.GetACC()));
    casterDice.RollDice();

    int16_t heal = static_cast<int16_t>((double)cta.GetMA() * 1.5);
    UI::logEvent(caster.GetName() + " 的 Heal 理想治療量為 " + std::to_string(heal));
    casterDice.displayResult();
    heal = static_cast<int16_t>(heal * ((double)casterDice.GetMovementPoint() / casterDice.GetAmount()));
    UI::logEvent(caster.GetName() + " 對 " + targets[0]->GetName() + " 施放了 " + std::to_string(heal) + " 的治療！");
    targets[0]->heal(heal);
}

void SpeedUpActiveCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    casterDice.SetSuccessRate(std::vector<uint8_t>(diceAmount, cta.GetACC()));
    casterDice.RollDice();

    if (casterDice.GetMovementPoint() == 2) {
        UI::logEvent(caster.GetName() + " 的 Speed Up 成功！");
        // 給予SpeedUp Buff一回合
        targets[0]->addBuff("SpeedUp", 1);
    } else {
        UI::logEvent(caster.GetName() + " 的 Speed Up 失敗！");
    }
}

void RunPassiveCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	if (targets[0]->GetDice().GetFocusCount() == 0) {
		targets[0]->GetDice().SetFocusCount(1);
		UI::logEvent(caster.GetName() + " 的被動 Run 被觸發，第一個擲骰保證成功！");
	}
}

void HammerSplashPassiveCommand::execute(Entity& caster, std::vector<Entity*> targets) {
    UI::logEvent(caster.GetName() + " 的被動 HammerSplash 被觸發！");
    targets[0]->addBuff("Dizziness", 1);
    for (int i = 1; i < targets.size(); i++) {
        if (targets[i]->GetStatus() & RETREAT || targets[i]->GetStatus() & DEAD)
            continue;

        targets[i]->takeDamage(targets[0]->GetlastDamage() * 0.5, 'P');
	}
}

void DestroyPassiveCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	UI::logEvent(caster.GetName() + " 的被動 Destroy 被觸發！");
	// 現在沒有人可以觸發 Destroy，所以這邊就先不寫，留時間給其他東西
}

void FortifyPassiveCommand::execute(Entity& caster, std::vector<Entity*> targets) {
	// Fortify 不應該在這裡被觸發，而是要在Entity::takeDamage()裡面被觸發
    UI::logEvent(caster.GetName() + " 的被動 Fortify 被觸發！所受傷害自動 * 0.9");
}

void AngryBuffCommand::execute(Entity& caster) {
	UI::logEvent(caster.GetName() + " 很氣，氣到骰子都骰不好了@@");
    caster.GetDice().SetRateAddition(std::vector<double>(caster.GetDice().GetAmount(), -30));
}

void DizzinessBuffCommand::execute(Entity& caster) {
	UI::logEvent(caster.GetName() + " 被 Dizziness 了");
}

void PoisonedBuffCommand::execute(Entity& caster) {
	UI::logEvent(caster.GetName() + " 因為 Poisoned 所以受到了持續傷害");
    int16_t damage = static_cast<int16_t>(caster.GetTotalAttribute().GetHP() * 0.1);
    damage = damage == 0 ? 1 : damage;
    caster.takeTrueDamage(damage);
}

void SpeedUpBuffCommand::execute(Entity& caster) {
    UI::logEvent(caster.GetName() + " 的速度提升了 50% !");
    caster.GetTotalAttribute().SetSPD((caster.GetTotalAttribute().GetSPD() + 0.5) * 1.5);
    UI::renewPlayerInfo();
}

void SpeedUpBuffDeConstructCommand::execute(Entity& caster) {
	// UI::logEvent(caster.GetName() + " 的 SpeedUp 沒了。");
	caster.GetTotalAttribute().SetSPD(caster.GetTotalAttribute().GetSPD() / 1.5);
    UI::renewPlayerInfo();
}

void AngryBuffDeConstructCommand::execute(Entity& caster) {
	UI::logEvent(caster.GetName() + " 不 Angry 了，體悟心靈祥和。");
	caster.GetDice().SetRateAddition(std::vector<double>(caster.GetDice().GetAmount(), 0));
}