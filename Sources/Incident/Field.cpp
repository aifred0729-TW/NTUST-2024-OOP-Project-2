#include "../../Includes/Incident/Field.h"

// Public

void Field::StartBattle(void) {
	using namespace std;

	while (1) {
		currEvent = RefreshEvent();
		uint8_t currStatus = 0;// currEvent->GetObj()->GetStatus();
		if (currStatus & DEAD) {
			continue;
		}
		if (currStatus & RETREAT) {
			continue;
		}

		StatusCount* currentCount = currEvent->GetCount();
		if (currentCount->dizziness) {
			currentCount->dizziness--;
			DamagePhase(currEvent);
			continue;
		}

		MainPhase(currEvent);
		BattlePhase(currEvent);
		DamagePhase(currEvent);

		try { ExitPhase(); }
		catch (const exception& e) {
			cout << e.what();
			return;
		}
	}
}

void Field::MainPhase(Action* Event) {
	if (Event->GetEntityID() < 3){ /* enemy entity */ 
		int opcode = 0;

		// -> randomly choose skill of equiment or normal attack
		int target = 0;
		while (eventQueue[target = rand() % 3 + 3]->GetObj());

		// -> set data of dice with equiment by its table
		// -> use skill
	}
	else { /* player entity */
		int opcode = 0;
		// -> UI returning opCode to choose skill
		int skillID = 0;
		
		// -> UI returning opCode to choose target
		int targetID = 0;
		Entity* target;
		for (int i = 0; i < eventQueue.size(); ++i) {
			if (targetID == eventQueue[i]->GetEntityID()) {
				target = eventQueue[i]->GetObj();
				break;
			}
		}

		// -> set data of dice with equiment by its table
		// -> set dice when use focus
		// -> use skill
	}
}

void Field::BattlePhase(Action* Event) {
	using namespace std;

	// --------compulate damage stage--------
	// -> set dice when angry status.
	Event->GetDice()->RollDice();
	vector<bool> diceResult = Event->GetDice()->GetResult();

	bool perfect = 1;
	bool defeat = 1;
	for (int i = 0; i < diceResult.size(); ++i) {
		if (diceResult[i]) {
			defeat = 0;
		}
		else {
			perfect = 0;
		}
	}

	if (perfect) {
		;
	}
	if (defeat) {
		;
	}



	// --------compulate atk buff--------



	// --------compulate def buff--------


}

void Field::DamagePhase(Action* Event) {
	;
}

void Field::ExitPhase(void) {
	using namespace std;

	bool AllRoleDead = 1, AllEnemyDead = 1;
	/*for (int i = 0; i < 3; ++i) {
		if (!eventQueue[i]->GetObj()) return;
		if (!(eventQueue[i]->GetObj()->GetStatus() & DEAD)) AllEnemyDead = 0;
	}
	for (int i = 3; i < 6; ++i) {
		if (!eventQueue[i]->GetObj()) return;
		if (!(eventQueue[i]->GetObj()->GetStatus() & DEAD)) AllRoleDead = 0;
	}*/

	if (AllRoleDead) {
		throw exception("Role Dead!\n");
	}
	if (AllEnemyDead) {
		throw exception("Enemy Dead!\n");
	};
}

Action* Field::RefreshEvent(void) {
	using namespace std;
	/*
	auto cmpPriority = [](Action* x, Action* y) {
		return x->GetPriority() < y->GetPriority();
	};
	auto cmpSPD = [](Action* x, Action* y) {
		return
			x->GetObj()->GetAttribute().GetSPD() <
			y->GetObj()->GetAttribute().GetSPD();
	};
	auto cmpPA = [](Action* x, Action* y) {
		return
			x->GetObj()->GetAttribute().GetPA() <
			y->GetObj()->GetAttribute().GetPA();
	};
	auto cmpPD = [](Action* x, Action* y) {
		return
			x->GetObj()->GetAttribute().GetPD() <
			y->GetObj()->GetAttribute().GetPD();
	};
	auto cmpMaxHP = [](Action* x, Action* y) {
		return
			x->GetObj()->GetAttribute().GetMaxHP() <
			y->GetObj()->GetAttribute().GetMaxHP();
	};

	stable_sort(eventQueue.begin(), eventQueue.end(), cmpMaxHP);
	stable_sort(eventQueue.begin(), eventQueue.end(), cmpPD);
	stable_sort(eventQueue.begin(), eventQueue.end(), cmpPA);
	stable_sort(eventQueue.begin(), eventQueue.end(), cmpSPD);
	stable_sort(eventQueue.begin(), eventQueue.end(), cmpPriority);
*/
	// update for the next refresh sort
	eventQueue[0]->SetTurn(eventQueue[0]->GetTurn() + 1);
	//eventQueue[0]->SetPriority(double(eventQueue[0]->GetTurn() + 1) / eventQueue[0]->GetObj()->GetAttribute().GetSPD());

	return eventQueue[0];
}



// constructor
Action::Action(Entity* val, uint8_t mode, uint8_t ID)
	:obj(val), turn(0), entityID(ID), count(new StatusCount{ 0, 0, 0, 0 }), dice(nullptr) {
	priority = 0;// 1.0 / val->GetAttribute().GetSPD() * 100;
}

Field::Field(std::vector<Entity*> players, std::vector<Entity*> enemies) : currEvent(nullptr) {
	for (int i = 0; i < players.size(); ++i) {
		eventQueue.push_back(new Action(players[i], ROLE, i + 3));
	}
	for (int i = 0; i < enemies.size(); ++i) {
		eventQueue.push_back(new Action(enemies[i], ENEMY, i));
	}
}

Field::~Field(void) {
	for (int i = 0; i < eventQueue.size(); ++i) {
		delete eventQueue[i]->GetCount();
		delete eventQueue[i];
		eventQueue.pop_back();
	}
}