#ifndef FIELD_H
#define FIELD_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <windows.h>

#include <Enemy.h>
#include <Role.h>

class Field {
private:
    Dice                dice;               // Dice
    std::vector<Enemy*> enemyEngage;        // Engage Enemys
    std::vector<Role*>  roleEngage;         // Engage Roles

public:
    void MainPhase(Enemy*);
    void BattlePhase(Enemy*);
    void DamagePhase(Enemy*);
    void MainPhase(Role*);
    void BattlePhase(Role*);
    void DamagePhase(Role*);
    void ExitPhase(void);

    void Init(void);
    void ChooseSkill(Role*);
    void ChooseTarget(Role*);
    void UsingFocus(Role*);
    // Detect Status and Compute

    Entity* RefreshPriority(void);
    bool AllRoleDead(void);
    bool AllEnemyDead(void);

public:
    // Set Combat Configuation
    Field(std::vector<Role*>, std::vector<Enemy*>);
    // Start Combat
    void StartBattle(void);

};

#endif