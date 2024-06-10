#ifndef SKILL_H
#define SKILL_H

#include <cstdint>
#include <vector>
#include <functional>
#include <Dice.h>
#include <SkillBase.h>
#include <ConstData.h>

class Entity;

template<typename T>
void mergeUnique(std::vector<T>& target, const std::vector<T>& source);

class Skill {
private:
    std::vector<Active> active;
    std::vector<Passive> passive;
    std::vector<Buff> buff;

public:
    Skill();

    void SetActive(const std::vector<Active>&);
    void SetPassive(const std::vector<Passive>&);
    void SetBuff(const std::vector<Buff>&);

    std::vector<Active>& GetActive();
    std::vector<Passive>& GetPassive();
    std::vector<Buff>& GetBuff();

public:
    void display();
    void pushActive(const Active&);
    void pushPassive(const Passive&);
    void pushBuff(const Buff&);
    Skill operator+=(Skill&);
    std::function<void()> ApplySkill;
};

#endif
