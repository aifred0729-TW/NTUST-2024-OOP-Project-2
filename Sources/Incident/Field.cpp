#include "../../Includes/Incident/Field.h"

// Public

void Field::MainPhase(Role*) {
	;
}

void Field::BattlePhase(Role*) {
	;
}

void Field::DamagePhase(Role*) {
	;
}

void Field::MainPhase(Enemy*) {
	;
}

void Field::BattlePhase(Enemy*) {
	;
}

void Field::DamagePhase(Enemy*) {
	;
}

void Field::ExitPhase(void) {
	;
}

void Field::Init(void) {
	for (int i = 0; i < roleEngage.size(); ++i) {
		roleEngage[i]->SetEntityID(i + 3);
		roleEngage[i]->SetMode(ROLE);
		roleEngage[i]->SetTurn(0);
		roleEngage[i]->SetPriority(0);
	}
	for (int i = 0; i < enemyEngage.size(); ++i) {
		enemyEngage[i]->SetEntityID(i);
		enemyEngage[i]->SetMode(ENEMY);
		enemyEngage[i]->SetTurn(0);
		enemyEngage[i]->SetPriority(0);
	}
}

Entity* Field::RefreshPriority(void) {
	using namespace std;

	auto cmp = [](Entity* x, Entity* y)
	{
		if ((x->GetPriority() / x->GetAttribute().GetSPD() * 100) > (y->GetPriority() / y->GetAttribute().GetSPD() * 100))
			return true;
		if (x->GetAttribute().GetSPD() > y->GetAttribute().GetSPD())
			return true;
		if (x->GetAttribute().GetPA() + x->GetAttribute().GetMA() > y->GetAttribute().GetPA() + y->GetAttribute().GetMA())
			return true;
		if (x->GetAttribute().GetPD() + x->GetAttribute().GetMD() > y->GetAttribute().GetPD() + y->GetAttribute().GetMD())
			return true;
		if (x->GetAttribute().GetMaxHP() > y->GetAttribute().GetMaxHP())
			return true;
		return false;
	};

	vector<Entity*> currPriority;
	for (int i = 0; i < roleEngage.size(); ++i)
		currPriority.push_back(roleEngage[i]);
	for (int i = 0; i < enemyEngage.size(); ++i)
		currPriority.push_back(enemyEngage[i]);

	for (int i = 0; i < currPriority.size(); ++i) {
		currPriority[i]->SetPriority(double(currPriority[i]->GetTurn()) / currPriority[i]->GetAttribute().GetSPD() * 100);
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
		if (!(roleEngage[i]->GetStatus() & DEAD)) {
			return false;
		}
	}
	return true;
}

bool Field::AllEnemyDead(void) {
	for (int i = 0; i < enemyEngage.size(); ++i) {
		if (!(enemyEngage[i]->GetStatus() & DEAD)) {
			return false;
		}
	}
	return true;
}

// Set Combat Configuation
Field::Field(std::vector<Role*> players, std::vector<Enemy*> enemies)
	: roleEngage(players), enemyEngage(enemies) {
	;
}

void Display(std::vector<Role*>& vec) {
	using namespace std;

	for (int i = 0; i < vec.size(); ++i) {
		cout << "GetAccessoryID\t" << vec[i]->GetAccessoryID() << '\n';
		cout << "GetArmorID\t" << vec[i]->GetArmorID() << '\n';
		cout << "GetEntityID\t" << vec[i]->GetEntityID() << '\n';
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
		Entity* currEntity = RefreshPriority();

		if (currEntity->GetStatus() & DEAD)
		{
			cout << "DEAD\n";
			continue;
		}
		if (currEntity->GetMode() & ROLE)
		{
			MainPhase(static_cast<Role*>(currEntity));
			BattlePhase(static_cast<Role*>(currEntity));
			DamagePhase(static_cast<Role*>(currEntity));
		}
		else
		{
			MainPhase(static_cast<Enemy*>(currEntity));
			BattlePhase(static_cast<Enemy*>(currEntity));
			DamagePhase(static_cast<Enemy*>(currEntity));
		}

		if (AllRoleDead()) {
			cout << "Role Dead\n";
			return;
		}
		if (AllEnemyDead()) {
			cout << "Enemy Dead\n";
			return;
		}

		currEntity->SetTurn(currEntity->GetTurn() + 1);

		return;
	}
	ExitPhase();
}