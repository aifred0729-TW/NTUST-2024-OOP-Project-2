#include <SkillTable.h>
#include <ItemTable.h>
#include <Role.h>
#include <Enemy.h>
#include <Field.h>
#include <Attribute.h>
#include <KeyBoard.h>
#include <Color.h>
#include <Backpack.h>
#include "Game.h"

#include <string>

int main() {
    Game G;
    G.MainProcess();

	SkillTable::Initialize();
	EquipmentTable::Initialize();
	ItemTable::Initialize();

	UI::checkConsoleSize(50, 180);
	UI::ShowMenu();

	system("Pause");
	system("CLS");

	Role hero("hero");
	Role profPao("鮑興國");
	Role myWife("砂狼白子我婆");
	Enemy dragon("dragon");
	Enemy profDai("戴文凱");
	Enemy tonya("Tonya");

	profDai.equipForce("Hammer");

	UI::moveCursor(2, 9);

	Field battle({ &profPao }, { &profDai });
	battle.StartBattle();

	return 0;
}