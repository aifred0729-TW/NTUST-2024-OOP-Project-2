#include "../../Includes/Display/UI.h"
#include <Role.h>
#include <Enemy.h>
#include <Entity.h>
#include <Dice.h>

// Public

using namespace Displayer;

std::vector<Enemy*> EnemysVector;
std::vector<Role*> RolesVector;
std::vector<std::string> battleLog = {};

void UI::checkConsoleSize(int requiredRows, int requiredCols) {
    static int preRequiredRows = 0;
    static int preRequiredCols = 0;
    while (1) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int consoleRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        int consoleCols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        if (preRequiredRows != consoleRows || preRequiredCols != consoleCols) {
            moveCursor(0, 0);
            preRequiredRows = consoleRows;
            preRequiredCols = consoleCols;
            std::cout << GREEN;
            std::cout << "The display area is too small, please resize the window(use ctrl + scroll wheel)\n";
            std::cout << "Require: " << requiredRows << " * " << requiredCols << "                     \n";
            std::cout << "Current: " << consoleRows << " * " << consoleCols << "                     \n";
            std::cout << "                     " << std::endl;
            std::cout << RESET;
        }
        if ((consoleRows >= requiredRows) && (consoleCols >= requiredCols)) {
            system("CLS");
            return;
        }
    }
}

void UI::logInitialization() {
    battleLog.clear();
}

void UI::logEvent(const std::string& event) {
    const int MAX_ROWS = 30;
    battleLog.push_back(event);
    if (battleLog.size() > MAX_ROWS) {
        battleLog.erase(battleLog.begin());
    }
    int ROWS = battleLog.size();

    for (int i = battleLog.size() - 1; i >= 0; i--) {
        std::cout << BLACK;
        BuildHollowFrame(124, 41 - i, 176, 41 - i);
        displayString(124, 41 - i, battleLog[battleLog.size() - i - 1]);
    }
    //Sleep(150);
}


void UI::logDivider(const std::string& str) {
    logEvent(horizontalLine(str, 53, '-'));
}

void UI::logDivider(const std::string& str1, const std::string& str2) {
    std::string output("");
    int i = 26 - str1.length();
    for (int j = 0; j < i ; j++) {
        output.push_back('-');
    }
    output = output + str1 + " " + str2;
    i = 26 - str2.length();
    for (int j = 0; j < i; j++) {
        output.push_back('-');
    }
    logEvent(output);
}

int UI::PreBattle(std::vector<Enemy*> enemys, std::vector<Role*> roles) {
    using namespace std;
    logInitialization();
    cout << BLACK;
    BuildFrame(0, 0, 179, 49); //¶ñ¶Â
    BuildHollowFrame(0, 0, 174, 49); //¥~®Ø

    PlayerFrame({ 0,1,2,3,4,5 });

    BuildHollowFrame(0, 42, 121, 35); //Dice
    BuildFrame(121, 7, 179, 42);      //BattleLog
    displayString(124, 9, horizontalLine("Battle Log", 53, '-'));

    EnemysVector = enemys;
    RolesVector = roles;

    for (int i = 0; i < enemys.size(); i++) {
        displayPlayerInfo(58 * i, 0, enemys[i]);
    }
    for (int i = 0; i < roles.size(); i++) {
        displayPlayerInfo(58 * i, 42, roles[i]);
    }

    return 0;
}

int UI::ShowMenu(void) {
    using namespace std;
    system("CLS");
    std::string bannerStr = BANNER;
    BuildFrame(0, 0, 179, 49);
    displayString(bannerStr, 3, 1);
    std::cout << BOLD << YELLOW;
    BuildHollowFrame(60, 26, 119, 30);
    std::cout << BOLD << YELLOW;
    displayString("PLAY", 87, 28);
    moveCursor(80, 28);
    return 0;
}

int UI::Display(std::vector<std::pair<int, int>>*) {
    return 0;
}

int UI::Display(Dice* dice) {
    std::vector<int> diceLog;
    int diceAmount = dice->GetAmount();
    int diceFocusCount = dice->GetFocusCount();
    std::vector<bool> diceResult = dice->GetResult();

    for (int i = 0; i < diceAmount; i++) {
        if (i < diceFocusCount) {
            diceLog.push_back(2);
        }
        else {
            diceLog.push_back(diceResult[i]);
        }
    }
    return 0;
}

void UI::renewPlayerInfo() {
    for (int i = 0; i < EnemysVector.size(); i++) {
        displayPlayerInfo(58 * i, 0, EnemysVector[i]);
    }
    for (int i = 0; i < RolesVector.size(); i++) {
        displayPlayerInfo(58 * i, 42, RolesVector[i]);
    }
}

int UI::Display(Entity*) {
    return 0;
}

int UI::Display(Field*) {
    return 0;
}

int UI::Display(Store*) {
    return 0;
}

int UI::Display(Interactive*) {
    return 0;
}

int UI::ReLocation(Role*) {
    return 0;
}

void UI::PlayerFrame(int index) {
    const std::vector<std::pair<int, int>> table = { {0, 0}, {58, 0}, {116, 0}, {0, 42}, {58, 42}, {116, 42} };
    BuildHollowFrame(table[index].first, table[index].second, table[index].first + 58, table[index].second + 7);
}

void UI::PlayerFrame(std::vector<int> vec) {
    const std::vector<std::pair<int, int>> table = { {0, 0}, {58, 0}, {116, 0}, {0, 42}, {58, 42}, {116, 42} };
    for (auto index : vec) {
        BuildHollowFrame(table[index].first, table[index].second, table[index].first + 58, table[index].second + 7);
    }
}