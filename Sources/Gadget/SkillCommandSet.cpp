#include "../../Includes/Gadget/SkillCommandSet.h"

void AttackCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto casterWeapon = caster.GetEquipment().GetWeapon();
    auto cta = caster.GetTotalAttribute();

    int16_t damage = static_cast<int16_t>(cta.GetPA());
    UI::logEvent(caster.GetName() + " 的 Attack 理想攻擊力為 " + std::to_string(damage));

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

void FleeCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    uint8_t successRate = static_cast<uint8_t>((double)cta.GetHP() * (cta.GetSPD()) * 100 / (cta.GetMaxHP() + cta.GetMD() + cta.GetPD()));
    successRate = successRate > 98 ? 98 : successRate;
    UI::logEvent(caster.GetName() + " 的成功逃跑機率為 " + std::to_string((unsigned)successRate) + "%");

    casterDice.SetSuccessRate(std::vector<uint8_t>(1, successRate));
    casterDice.RollDice();
    casterDice.displayResult();

    if (casterDice.GetMovementPoint() == 1) {
        UI::logEvent(caster.GetName() + " 逃跑成功！！");
        // ctargets[0]->SetStatus(逃跑狀態);
    } else {
        UI::logEvent(caster.GetName() + " 逃跑失敗，繼續坐牢。");
    }
}

void ProvokeCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    uint8_t successRate = static_cast<uint8_t>(1, (double)cta.GetHP() / ((cta.GetMaxHP() + cta.GetMD() + cta.GetPA())) * 100);
    casterDice.SetSuccessRate(std::vector<uint8_t>(1, successRate));
    UI::logEvent(caster.GetName() + " 的 Provoke 成功機率為 " + std::to_string((unsigned)successRate) + "%");
    casterDice.RollDice();
    casterDice.displayResult();

    if (casterDice.GetMovementPoint() == 1) {
        UI::logEvent("挑釁成功，現在 " + targets[0]->GetName() + " 很想把 " + caster.GetName() + " 爆幹一頓。");
        // targets[0]->SetStatus(挑釁狀態);
    } else {
        UI::logEvent("挑釁失敗，" + targets[0]->GetName() + "只把" + caster.GetName() + " 當小丑。");
    }
}

void ShockBlastCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto casterWeapon = caster.GetEquipment().GetWeapon();
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    casterDice.SetSuccessRate(std::vector<uint8_t>(3, cta.GetACC() - 5));
    casterDice.RollDice();

    int16_t damage = static_cast<int16_t>((double)((double)cta.GetMA() / 2));
    UI::logEvent(caster.GetName() + " 的 ShockBlast 理想攻擊力為 " + std::to_string(damage));

    casterDice.displayResult();
    damage = static_cast<int16_t>((double)((double)cta.GetMA() / 2) * ((double)casterDice.GetMovementPoint() / casterDice.GetAmount()));
    std::string attackType = casterWeapon.GetAttackType() == 'P' ? "物理" : "魔法";

    UI::logEvent(caster.GetName() + " 對全體敵人施放了 " + std::to_string(damage) + " 的" + attackType + "攻擊！");
    for (auto target : targets) {
        target->takeDamage(damage, casterWeapon.GetAttackType());
    }
}

void HealCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    casterDice.SetSuccessRate(std::vector<uint8_t>(3, cta.GetACC()));
    casterDice.RollDice();

    int16_t heal = static_cast<int16_t>((double)cta.GetMA() * 1.5);
    UI::logEvent(caster.GetName() + " 的 Heal 理想治療量為 " + std::to_string(heal));
    casterDice.displayResult();
    heal = static_cast<int16_t>(heal * ((double)casterDice.GetMovementPoint() / casterDice.GetAmount()));
    UI::logEvent(caster.GetName() + " 對 " + targets[0]->GetName() + " 施放了 " + std::to_string(heal) + " 的治療！");
    targets[0]->heal(heal);
}

void SpeedUpCommand::execute(Entity& caster, std::vector<Entity*> targets, uint8_t coolDown, uint8_t tick, uint8_t diceAmount) {
    auto cta = caster.GetTotalAttribute();

    auto& casterDice = caster.GetDice();
    casterDice.resize(diceAmount);
    casterDice.SetSuccessRate(std::vector<uint8_t>(2, cta.GetACC()));
    UI::logEvent(caster.GetName() + " 的 Speed Up 成功機率為 " + std::to_string((unsigned)cta.GetACC()) + "%");
    casterDice.RollDice();

    if (casterDice.GetMovementPoint() == 2) {
        UI::logEvent(caster.GetName() + " 的 Speed Up 成功！");
        UI::logEvent("給予 " + targets[0]->GetName() + " 1回合的 SpeedUp Buff。");
        // 給予SpeedUp Buff一回合
        Buff SpeedUp = SkillTable::buffMap.find("SpeedUp")->second;
        targets[0]->GetSkill().pushBuff(SpeedUp);
    }
    else {
        UI::logEvent(caster.GetName() + " 的 Speed Up 失敗！");
    }
}