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

class Action {
private:
	Dice dice;
	Entity* obj;
	uint8_t priority;
	uint8_t turn;
	uint8_t entityID;
	uint8_t statusTurn;

public:
	Action(Entity* val, uint8_t mode, uint8_t ID)
		:obj(val), dice(obj->GetAttribute().GetSPD()),
		priority(0), turn(0), entityID(ID), statusTurn(0) {
		;
	}

	void SetObj(Entity* val) { obj = val; }
	void SetPriority(uint8_t val) { priority = val; }
	void SetTurn(uint8_t val) { turn = val; }
	void SetEntityID(uint8_t val) { entityID = val; }
	void SetStatusTurn(uint8_t val) { statusTurn = val; }

	Dice    GetDice(void) { return dice; }
	Entity* GetObj(void) { return obj; }
	uint8_t GetPriority(void) { return priority; }
	uint8_t GetTurn(void) { return turn; }
	uint8_t GetEntityID(void) { return entityID; }
	uint8_t GetStatusTurn(void) { return statusTurn; }
};

class Field {
private:
	Action* currEvent;                      // Current Event
	std::vector<Action*> enemyEngage;       // Engage Enemys
	std::vector<Action*> roleEngage;        // Engage Roles

public:
	void MainPhase(Action*);
	void BattlePhase(Action*);
	void DamagePhase(Action*);
	void ExitPhase(void);

	void Init(void);
	void ChooseSkill(Role*);
	void ChooseTarget(Role*);
	void UsingFocus(Role*);
	// Detect Status and Compute

	Action* RefreshEvent(void);
	bool AllRoleDead(void);
	bool AllEnemyDead(void);

public:
	// Set Combat Configuation
	Field(std::vector<Role*>, std::vector<Enemy*>);
	// Set Combat Configuation
	~Field(void);
	// Start Combat
	void StartBattle(void);
};

#endif