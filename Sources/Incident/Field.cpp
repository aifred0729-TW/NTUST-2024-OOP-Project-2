#include "../../Includes/Incident/Field.h"

// Public

void Field::MainPhase(Action*) {
	;
}

void Field::BattlePhase(Action*) {
	;
}

void Field::DamagePhase(Action*) {
	;
}

void Field::ExitPhase(void) {
	;
}

void Field::Init(void) {

}

Action* Field::RefreshEvent(void) {
	using namespace std;

	return nullptr;
}

void Field::ChooseSkill(Role*) {
	;
}

void Field::ChooseTarget(Role*) {
	;
}

void Field::UsingFocus(Role*) {
	;
}

// Detect Status and Compute
bool Field::AllRoleDead(void) {

	return true;
}

bool Field::AllEnemyDead(void) {
	return false;
}


Action::Action(Entity* val, uint8_t mode, uint8_t ID)
	:obj(val), priority(0), turn(0), entityID(ID), statusTurn(0)/*, dice(val->GetAttribute().GetSPD())*/ {
	;
}

// Set Combat Configuation
Field::Field(std::vector<Entity*> players, std::vector<Entity*> enemies) : currEvent(nullptr) {
	for (int i = 0; i < players.size(); ++i)
	{
		Action* temp = new Action(players[i], ROLE, i + 3);
		roleEngage.push_back(temp);
	}
	for (int i = 0; i < enemies.size(); ++i) {
		Action* temp = new Action(enemies[i], ENEMY, i);
		enemyEngage.push_back(temp);
	}
}

Field::~Field(void) {
	for (int i = 0; i < roleEngage.size(); ++i) {
		delete roleEngage[i];
		roleEngage.pop_back();
	}
	for (int i = 0; i < enemyEngage.size(); ++i) {
		delete enemyEngage[i];
		enemyEngage.pop_back();
	}
}

/*
void Display(Action* val) {
	using namespace std;

	
	cout << val->GetDice().GetFocus() << endl;
	cout << val->GetDice().GetFocusCount() << endl;
	//cout << val->GetDice().GetRateAddition() << endl;
	//cout << val->GetDice().GetSuccessRate() << endl;

	cout << val->GetObj()->GetAccessoryID() << endl;
	cout << val->GetObj()->GetArmorID() << endl;
}*/

// Start Combat
void Field::StartBattle(void) {
	using namespace std;
	Init();

	while (1) {
		currEvent = RefreshEvent();

		/*if (currEvent->GetObj()->GetStatus() & DEAD)
		{
			cout << "ALREADY DEAD\n";
			continue;
		}*/

		MainPhase(currEvent);
		BattlePhase(currEvent);
		DamagePhase(currEvent);

		if (AllRoleDead()) {
			cout << "Role Dead\n";
			return;
		}
		if (AllEnemyDead()) {
			cout << "Enemy Dead\n";
			return;
		}

		currEvent->SetTurn(currEvent->GetTurn() + 1);
		if (currEvent->GetStatusTurn()) {
			currEvent->SetStatusTurn(currEvent->GetStatusTurn() - 1);
		}

		return;
	}
	ExitPhase();
}