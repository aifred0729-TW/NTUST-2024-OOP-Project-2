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

/*
Action(Entity* val, uint8_t mode, uint8_t ID)
	:obj(val), dice(obj->GetAttribute().GetSPD()),
	priority(0), turn(0), entityID(ID), statusTurn(0) {
	;
}*/
// Set Combat Configuation
Field::Field(std::vector<Role*> players, std::vector<Enemy*> enemies) {
	
}

Field::~Field(void) {
	
}

void Display(std::vector<Role*>& vec) {
	using namespace std;

	
}

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