#ifndef SKILL_H
#define SKILL_H

#include <cstdint>
#include <vector>
#include "Dice.h"
#include "ConstData.h"

class Entity;

class Skill {
private:
    uint8_t skillID;
    uint8_t coolDownTime;
    Dice dice;
    Entity* skillUser;
    std::vector<Entity*> skillTargets;

    static void (* const skillTable[SKILL_TOTAL_SIZE])(void);

private:
    static void ApplyAttack(void);
    static void ApplyFlee(void);
    static void ApplyProvoke(void);
    static void ApplyShockBlast(void);
    static void ApplyHeal(void);
    static void ApplySpeedUp(void);
    static void ApplyRun(void);
    static void ApplyHammerSplash(void);
    static void ApplyDestroy(void);
    static void ApplyFortify(void);
    static void ApplySKILL111(void);
    static void ApplySKILL222(void);
    static void ApplySKILL333(void);

public:
    Skill();

    void ApplySkill(uint8_t, Entity*, std::vector<Entity*>);

    // Setter and Getter for skillID
    void SetID(uint8_t id);
    uint8_t GetID() const;

    // Other setters and getters can be added similarly
};

#endif
