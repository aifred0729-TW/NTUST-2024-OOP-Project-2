#include "../../Includes/Control/Game.h"

// Private

int Game::Move(void) {
	return 0;
}

int Game::GetKeyboard(void) {
	return 0;
}

int Game::GiveRandomAttribate(void) {
	return 0;
}

// Public

void Game::Initialize() {
	SkillTable::Initialize();
	EquipmentTable::Initialize();
	ItemTable::Initialize();
	return;
}

void Game::MainProcess(void) {
	using namespace std;

	Initialize();
	cout << "done" << endl;
	UI::checkConsoleSize(50, 180);
	UI::ShowMenu();

	system("Pause");
	system("CLS");

	bool keyState[KeyBoard::INVALID];

	while (true) {
		// Move Stage
		// - Roll Dice
		// Display Please Roll Dice (UI)
		// displayRollDice();
		KeyBoard::keyUpdate(keyState);
		if (keyState[KeyBoard::EP]) continue;
		else if (keyState[KeyBoard::EI]) {
			// backpack process
			; 
		}
		else if (keyState[KeyBoard::EDU] || keyState[KeyBoard::EDL] || keyState[KeyBoard::EDR] || keyState[KeyBoard::EDD]) {
			// ditect entity is interactiveable
			;
		}
	}

	return;
}

