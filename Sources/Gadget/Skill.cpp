#include "Skill.h"

void (* const Skill::skillTable[SKILL_TOTAL_SIZE])(void) = {
    ApplyAttack, ApplyFlee, ApplyProvoke, ApplyShockBlast,
    ApplyHeal, ApplySpeedUp, ApplyRun, ApplyHammerSplash,
    ApplyDestroy, ApplyFortify, ApplySKILL111, ApplySKILL222,
    ApplySKILL333
};

Skill::Skill()
    : skillID(0), coolDownTime(0), dice(3, 30), skillUser(nullptr), skillTargets() {}

void Skill::ApplySkill(uint8_t type, Entity* user, std::vector<Entity*> targets) {
    if (type < SKILL_TOTAL_SIZE) {
        skillTable[type]();
        skillUser = user;
        skillTargets = targets;
    }
}

void Skill::ApplyAttack() {
    // 具體的攻擊技能實作
    std::cout << "ApplyAttack called" << std::endl;
}

void Skill::ApplyFlee() {
    // 具體的逃跑技能實作
    std::cout << "ApplyFlee called" << std::endl;
}

void Skill::ApplyProvoke() {
    // 具體的挑釁技能實作
    std::cout << "ApplyProvoke called" << std::endl;
}

void Skill::ApplyShockBlast() {
    // 具體的衝擊爆炸技能實作
    std::cout << "ApplyShockBlast called" << std::endl;
}

void Skill::ApplyHeal() {
    // 具體的治療技能實作
    std::cout << "ApplyHeal called" << std::endl;
}

void Skill::ApplySpeedUp() {
    // 具體的加速技能實作
    std::cout << "ApplySpeedUp called" << std::endl;
}

void Skill::ApplyRun() {
    // 具體的奔跑技能實作
    std::cout << "ApplyRun called" << std::endl;
}

void Skill::ApplyHammerSplash() {
    // 具體的錘擊技能實作
    std::cout << "ApplyHammerSplash called" << std::endl;
}

void Skill::ApplyDestroy() {
    // 具體的毀滅技能實作
    std::cout << "ApplyDestroy called" << std::endl;
}

void Skill::ApplyFortify() {
    // 具體的強化技能實作
    std::cout << "ApplyFortify called" << std::endl;
}

void Skill::ApplySKILL111() {
    // 具體的自定義技能1實作
    std::cout << "ApplySKILL111 called" << std::endl;
}

void Skill::ApplySKILL222() {
    // 具體的自定義技能2實作
    std::cout << "ApplySKILL222 called" << std::endl;
}

void Skill::ApplySKILL333() {
    // 具體的自定義技能3實作
    std::cout << "ApplySKILL333 called" << std::endl;
}


void Skill::SetID(uint8_t id) {
    skillID = id;
}

uint8_t Skill::GetID() const {
    return skillID;
}
