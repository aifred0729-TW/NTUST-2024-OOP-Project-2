#include "../../Includes/Control/Game.h"

#include <WorldMap.h>
#include <Role.h>
#include <KeyBoard.h>
#include <EquipmentTable.h>

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
	Role price("price");
	Role soap("soap");
	Role yuri("yuri");

	Enemy fat_tonya("胖子 - Tonya");
	Enemy troll_tonya("巨魔 - Tonya");
	Enemy boomer_tonya("胖子炸彈 - Tonya");



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
		KeyBoard::keyUpdate(keyState);
		if (keyState[KeyBoard::EP]) {
		}
		else if (keyState[KeyBoard::EI]) {
			// backpack process
			; 
		}
		else if (keyState[KeyBoard::EDU] || keyState[KeyBoard::EDL] || keyState[KeyBoard::EDR] || keyState[KeyBoard::EDD]) {
			// - Roll Dice
			// Display Please Roll Dice (UI)
			// displayRollDice();
			// ditect entity is interactiveable

			;
		}
		// check is on interactiveable object
		// if checkIsOnShop
		// enterShop
		
		// if checkIsOnEnemy
		// enterCombat
	}

	return;
}

bool Game::checkIsOnShop() {
	using namespace std;

	// if 

	return 0;
}