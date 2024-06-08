#include <Field.h>
#include <UI.h>
// Public

void Field::StartBattle(void) {
	using namespace std;

	UI::PreBattle(enemys, roles);

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
			continue;
		}

		MainPhase(currEvent);
		RemoveDeadEntity();

		try {
			ExitPhase();
		}
		catch (const exception& e) {
			UI::displayString(e.what(), 6, 9);
			return;
		}
	}
}

Action* Field::RefreshEvent(void) {
	using namespace std;

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

	// static int a0, a1, a2, a3, a4, a5;	static string a6;

	// update for the next refresh sort
	eventQueue[0]->SetTurn(eventQueue[0]->GetTurn() + 1);
	eventQueue[0]->SetPriority(double(eventQueue[0]->GetTurn()) / eventQueue[0]->GetObj()->GetAttribute().GetSPD() * 100);

	return eventQueue[0];
}

void Field::MainPhase(Action* currEvent) {
	using namespace std;

	if (currEvent->GetEntityID() < 3) { /* enemy entity */
		EnemyMainPhase(currEvent);
	}
	else { /* player entity */
		PlayerMainPhase(currEvent);
	}
}

void Field::RemoveDeadEntity(void) {
	for (auto it = eventQueue.begin(); it != eventQueue.end();) {
		if ((*it)->GetObj()->GetStatus() & DEAD || (*it)->GetObj()->GetStatus() & RETREAT) {
			it = eventQueue.erase(it);
		}
		else {
			++it;
		}
	}

	for (auto it = roles.begin(); it != roles.end();) {
		if ((*it)->GetStatus() & DEAD || (*it)->GetStatus() & RETREAT) {
			it = roles.erase(it);
		}
		else {
			++it;
		}
	}

	for (auto it = enemys.begin(); it != enemys.end();) {
		if ((*it)->GetStatus() & DEAD || (*it)->GetStatus() & RETREAT) {
			it = enemys.erase(it);
		}
		else {
			++it;
		}
	}
}

void Field::PlayerMainPhase(Action* currEvent) {
CHOICE:
	UI::BuildVoid(121, 7, 0, 27);
	UI::PlayerFrame({ 0,1,2,3,4,5 });
	std::cout << YELLOW;
	UI::PlayerFrame(currEvent->GetEntityID());

	auto skills = currEvent->GetObj()->GetTotalSkill().GetActive();
	auto skillToUse = UI::makeChoice(skills, 6, 9);
	UI::logDivider(currEvent->GetObj()->GetName(), skillToUse.first);

	int diceAmount = skillToUse.first == "Attack" ?
		currEvent->GetObj()->GetEquipment().GetWeapon().GetDiceAmount() : skills[skillToUse.second].GetDiceAmount();
	int focus = currEvent->GetObj()->GetAttribute().GetFocus();

	UI::displayDice(diceAmount, 0);

TARGET:
	auto target = ChooseTarget(currEvent, skills[skillToUse.second].GetTargetType());
	if (target.empty()) {
		UI::logEvent("行動已取消");
		UI::logEvent("");
		goto CHOICE;
	}

	int focusUse = ChooseFocus(focus, diceAmount);
	if (focusUse == -1) {
		UI::logEvent("行動已取消");
		UI::logEvent("");
		goto TARGET;
	}

	if (focusUse != 0) {
		UI::logEvent("使用 " + std::to_string(focusUse) + " 專注點數");
		currEvent->GetObj()->GetAttribute().SetFocus(focus - focusUse);
		currEvent->GetObj()->GetDice().SetFocusCount(focusUse);
	}
	currEvent->GetObj()->useSkill(skillToUse.first, target);
	UI::logEvent("");
}

std::pair<std::string, int> makeChoice(std::vector<Active> choices) {
	bool keyState[KeyBoard::INVALID];
	int select = rand() % choices.size();
	return { choices[select].GetName(), select };
}

void Field::EnemyMainPhase(Action* currEvent) {
	UI::BuildVoid(121, 7, 0, 27);
	UI::PlayerFrame({ 0,1,2,3,4,5 });
	std::cout << YELLOW;
	UI::PlayerFrame(currEvent->GetEntityID());

	auto skills = currEvent->GetObj()->GetTotalSkill().GetActive();
	int skillNumber;
	while ((skillNumber = rand() % skills.size()) == 1);

	auto skillToUse = skills[skillNumber];
	auto target = RandomTarget(currEvent, rand() % skills.size());
	currEvent->GetObj()->useSkill(skillToUse.GetName(), target);
	UI::logEvent("");
}

std::vector<Entity*> Field::RandomTarget(Action* currEvent, int TargetType) {
	std::vector<std::string> targetName;
	std::vector<std::vector<Entity*>> targetPtr;
	std::vector<Entity*> enemysToEntity;
	std::vector<Entity*> rolesToEntity;
	switch (TargetType) {
	case 0:
		targetName.push_back("《 Self 》");
		targetPtr.push_back({ currEvent->GetObj() });
		break;
	case 1:
		for (Enemy* E : enemys) {
			targetName.push_back(E->GetName());
			targetPtr.push_back({ E });
		}
		break;
	case 2:
		targetName.push_back("《 All enemies 》");
		for (Enemy* E : enemys) {
			enemysToEntity.push_back(E);
		}
		targetPtr.push_back(enemysToEntity);
		break;
	case 3:
		for (Role* R : roles) {
			targetName.push_back(R->GetName());
			targetPtr.push_back({ R });
		}
		break;
	case 4:
		targetName.push_back("《 All teammates 》");
		for (Role* R : roles) {
			rolesToEntity.push_back(R);
		}
		targetPtr.push_back(rolesToEntity);
		break;
	default:
		for (Enemy* E : enemys) {
			targetName.push_back(E->GetName());
			targetPtr.push_back({ E });
		}
		for (Role* R : roles) {
			targetName.push_back(R->GetName());
			targetPtr.push_back({ R });
		}
		break;
	}

	return targetPtr[TargetType];
}

std::vector<Entity*> Field::ChooseTarget(Action* currEvent, int TargetType) {
	std::vector<std::string> targetName;
	std::vector<std::vector<Entity*>> targetPtr;
	std::vector<Entity*> enemysToEntity;
	std::vector<Entity*> rolesToEntity;
	switch (TargetType) {
	case 0:
		targetName.push_back("《 Self 》");
		targetPtr.push_back({ currEvent->GetObj() });
		break;
	case 1:
		for (Enemy* E : enemys) {
			targetName.push_back(E->GetName());
			targetPtr.push_back({ E });
		}
		break;
	case 2:
		targetName.push_back("《 All enemies 》");
		for (Enemy* E : enemys) {
			enemysToEntity.push_back(E);
		}
		targetPtr.push_back(enemysToEntity);
		break;
	case 3:
		for (Role* R : roles) {
			targetName.push_back(R->GetName());
			targetPtr.push_back({ R });
		}
		break;
	case 4:
		targetName.push_back("《 All teammates 》");
		for (Role* R : roles) {
			rolesToEntity.push_back(R);
		}
		targetPtr.push_back(rolesToEntity);
		break;
	default:
		for (Enemy* E : enemys) {
			targetName.push_back(E->GetName());
			targetPtr.push_back({ E });
		}
		for (Role* R : roles) {
			targetName.push_back(R->GetName());
			targetPtr.push_back({ R });
		}
		break;
	}
	int targetNumber = UI::makeChoice(targetName, 26, 9);
	if (targetNumber == -1) {
		return {};
	}
	return targetPtr[targetNumber];
}

int Field::ChooseFocus(int focusPoint, int diceAmount) {
	int focusUse = 0;
	bool keyState[KeyBoard::INVALID];
	UI::displayDice(diceAmount, focusUse);
	//UI::renewPlayerInfo();
	while (1) {
		KeyBoard::keyUpdate(keyState);
		if (keyState[KeyBoard::EA]) {
			if (focusUse > 0) {
				focusUse--;
			}
		}
		else if (keyState[KeyBoard::ED]) {
			if (focusUse < focusPoint && focusUse < diceAmount) {
				focusUse++;
			}
		}
		else if (keyState[KeyBoard::ESPACE] || keyState[KeyBoard::EENTER]) {
			return focusUse;
		}
		else if (keyState[KeyBoard::EESC]) {
			return -1;
		}
		else {
			continue;
		}
		UI::displayDice(diceAmount, focusUse);
		//UI::renewPlayerInfo();
	}
}

void Field::ExitPhase(void) {
	using namespace std;

	bool AllRoleDead = 1, AllEnemyDead = 1;
	for (auto it : enemys) {
		if (!(it->GetStatus() & DEAD)) AllEnemyDead = 0;
	}
	for (auto it : roles) {
		if (!(it->GetStatus() & DEAD)) AllRoleDead = 0;
	}

	if (AllRoleDead) {
		throw exception("Role Dead!\n");
	}
	if (AllEnemyDead) {
		throw exception("Enemy Dead!\n");
	};
}



// constructor
Action::Action(Entity* val, uint8_t mode, uint8_t ID)
	:obj(val), turn(0), entityID(ID), count(new StatusCount{ 0, 0, 0, 0 }), dice(nullptr) {
	priority = 1.0 / val->GetAttribute().GetSPD() * 100;
}

Field::Field(std::vector<Role*> players, std::vector<Enemy*> enemies) : currEvent(nullptr) {
	roles = players;
	enemys = enemies;

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