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
	for (int i = 0; i < roleEngage.size(); ++i) {
		roleEngage[i]->SetEntityID(i + 3);
		roleEngage[i]->GetObj()->SetMode(ROLE);
		roleEngage[i]->SetTurn(0);
		roleEngage[i]->SetPriority(0);
	}
	for (int i = 0; i < enemyEngage.size(); ++i) {
		enemyEngage[i]->SetEntityID(i);
		enemyEngage[i]->GetObj()->SetMode(ENEMY);
		enemyEngage[i]->SetTurn(0);
		enemyEngage[i]->SetPriority(0);
	}
}

Action* Field::RefreshEvent(void) {
	using namespace std;

	auto cmp = [](Action* x, Action* y)
	{
		if ((x->GetPriority() / x->GetObj()->GetAttribute().GetSPD() * 100) > 
			(y->GetPriority() / y->GetObj()->GetAttribute().GetSPD() * 100))
			return true;
		if (x->GetObj()->GetAttribute().GetSPD() > 
			y->GetObj()->GetAttribute().GetSPD())
			return true;
		if (x->GetObj()->GetAttribute().GetPA() + x->GetObj()->GetAttribute().GetMA() > 
			y->GetObj()->GetAttribute().GetPA() + y->GetObj()->GetAttribute().GetMA())
			return true;
		if (x->GetObj()->GetAttribute().GetPD() + x->GetObj()->GetAttribute().GetMD() > 
			y->GetObj()->GetAttribute().GetPD() + y->GetObj()->GetAttribute().GetMD())
			return true;
		if (x->GetObj()->GetAttribute().GetMaxHP() > 
			y->GetObj()->GetAttribute().GetMaxHP())
			return true;
		return false;
	};

	vector<Action*> currPriority;
	for (int i = 0; i < roleEngage.size(); ++i)
		currPriority.push_back(roleEngage[i]);
	for (int i = 0; i < enemyEngage.size(); ++i)
		currPriority.push_back(enemyEngage[i]);

	for (int i = 0; i < currPriority.size(); ++i) {
		currPriority[i]->SetPriority(double(currPriority[i]->GetTurn()) / currPriority[i]->GetObj()->GetAttribute().GetSPD() * 100);
	}

	sort(currPriority.begin(), currPriority.end(), cmp);

	return currPriority[currPriority.size() - 1];
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
	for (int i = 0; i < roleEngage.size(); ++i) {
		if (!(roleEngage[i]->GetObj()->GetStatus() & DEAD)) {
			return false;
		}
	}
	return true;
}

bool Field::AllEnemyDead(void) {
	for (int i = 0; i < enemyEngage.size(); ++i) {
		if (!(enemyEngage[i]->GetObj()->GetStatus() & DEAD)) {
			return false;
		}
	}
	return true;
}

/*
Action(Entity* val, uint8_t mode, uint8_t ID)
	:obj(val), dice(obj->GetAttribute().GetSPD()),
	priority(0), turn(0), entityID(ID), statusTurn(0) {
	;
}*/
// Set Combat Configuation
Field::Field(std::vector<Role*> players, std::vector<Enemy*> enemies) {
	for (int i = 0; i < players.size(); ++i) {
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

void Display(std::vector<Role*>& vec) {
	using namespace std;

	for (int i = 0; i < vec.size(); ++i) {
		cout << "GetAccessoryID\t" << vec[i]->GetAccessoryID() << '\n';
		cout << "GetArmorID\t" << vec[i]->GetArmorID() << '\n';
		cout << "GetEventID\t" << vec[i]->GetEventID() << '\n';
		cout << "GetHP\t\t" << vec[i]->GetHP() << '\n';
		cout << "GetMode\t" << vec[i]->GetMode() << '\n';
		cout << "GetMovementPoint\t" << vec[i]->GetMovementPoint() << '\n';

		cout << "GetAttribute GetACC\t" << vec[i]->GetAttribute().GetACC() << '\n';
		cout << "GetAttribute GetFocus\t" << vec[i]->GetAttribute().GetFocus() << '\n';
		cout << "GetAttribute GetMA\t" << vec[i]->GetAttribute().GetMA() << '\n';
		cout << "GetAttribute GetMaxHP\t" << vec[i]->GetAttribute().GetMaxHP() << '\n';
		cout << "GetAttribute GetMD\t" << vec[i]->GetAttribute().GetMD() << '\n';
		cout << "GetAttribute GetPA\t" << vec[i]->GetAttribute().GetPA() << '\n';
		cout << "GetAttribute GetPD\t" << vec[i]->GetAttribute().GetPD() << '\n';
		cout << "GetAttribute GetSPD\t" << vec[i]->GetAttribute().GetSPD() << '\n';
	}
}

// Start Combat
void Field::StartBattle(void) {
	using namespace std;
	Init();

	while (1) {
		currEvent = RefreshEvent();

		if (currEvent->GetObj()->GetStatus() & DEAD)
		{
			cout << "ALREADY DEAD\n";
			continue;
		}
		
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