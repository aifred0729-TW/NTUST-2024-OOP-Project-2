#include "../../Includes/Display/UI.h"
#include <Role.h>
#include <Enemy.h>
#include <Entity.h>
#include <Dice.h>
#include <Field.h>

#include "ConstData.h"
#include "Displayer.h"
#include "Color.h"
#include "WorldMap.h"

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
    for (int j = 0; j < i; j++) {
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
    BuildFrame(0, 0, 179, 49); //填黑
    BuildHollowFrame(0, 0, 174, 49); //外框

    PlayerFrame({ 0,1,2,3,4,5 });

    BuildHollowFrame(0, 42, 121, 35); //Dice
    BuildHollowFrame(0, 7, 121, 11);  //eventQueue
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

void UI::printPriority(std::vector<Action*> eventQueue) {
    static std::vector<Action*> oldEventQueue = {};
    static std::string oldOutputStr = "";
    static int oldStrLengthCount = 0;
    std::string outputStr = "";
    int strLengthCount = 0;
    bool simpleChange = 1;
    //檢查順序是否改變

    if (oldEventQueue.empty()) {
        simpleChange = 0;
    }
    else if (eventQueue[eventQueue.size() - 1] == oldEventQueue[0]) {
        for (int i = 0; i < eventQueue.size() - 1; i++) {
            simpleChange == simpleChange && (eventQueue[i] == oldEventQueue[i + 1]);
        }
    }
    else {
        simpleChange = 0;
    }

    //構建字串
    for (int i = 0; i < eventQueue.size(); i++) {
        std::string enemyColor = (eventQueue[i]->GetObj()->GetStatus() & DEAD) ?
            (std::string)DARK + (std::string)RED : (std::string)BOLD + (std::string)RED;
        std::string roleColor = (eventQueue[i]->GetObj()->GetStatus() & DEAD) ?
            (std::string)DARK + (std::string)CYAN : (std::string)BOLD + (std::string)CYAN;
        std::string color = (eventQueue[i]->GetEntityID() < 3) ? enemyColor : roleColor;
        outputStr += color;
        outputStr += eventQueue[i]->GetObj()->GetName() + RESET;
        if (i != eventQueue.size() - 1) {
            outputStr += " <- ";
        }
    }

    //整理輸出區域
    for (int i = 0; i < eventQueue.size(); i++) {
        strLengthCount += eventQueue[i]->GetObj()->GetName().length();
    }
    strLengthCount += (eventQueue.size() - 1) * 4;
    /*
    BuildVoid(0, 7, 121, 11);
    moveCursor(61 - strLengthCount / 2 - (eventQueue.size() - 1) * 2, 9);
    */
    if (simpleChange) {
        std::string enemyColor = (oldEventQueue[0]->GetObj()->GetStatus() & DEAD) ?
            (std::string)DARK + (std::string)RED : (std::string)BOLD + (std::string)RED;
        std::string roleColor = (oldEventQueue[0]->GetObj()->GetStatus() & DEAD) ?
            (std::string)DARK + (std::string)CYAN : (std::string)BOLD + (std::string)CYAN;
        std::string color = (oldEventQueue[0]->GetEntityID() < 3) ? enemyColor : roleColor;
        oldOutputStr += (std::string)RESET + " <- " + color + oldEventQueue[0]->GetObj()->GetName();
        for (int i = 0; i < oldEventQueue[0]->GetObj()->GetName().length() + 4; i++) {
            moveCursor(61 - strLengthCount / 2 - i, 9);
            std::cout << oldOutputStr << " ";
            BuildVoid(61 - strLengthCount / 2, 8, 60 - strLengthCount / 2 - i, 10);
            BuildVoid(61 + strLengthCount / 2, 8, 66 + strLengthCount / 2 + oldEventQueue[0]->GetObj()->GetName().length(), 10);
            Sleep(100);
        }
        BuildVoid(0, 7, 121, 11);
        moveCursor(61 - strLengthCount / 2, 9);
        std::cout << outputStr;
        //std::cout << outputStr;
    }
    else {
        for (int i = 0; i < oldStrLengthCount; i++) {
            moveCursor(61 + (oldStrLengthCount + 1) / 2 - i, 9);
            std::cout << " ";
            Sleep(3);
        }
        moveCursor(61 - strLengthCount / 2, 9);
        std::cout << outputStr;
    }
    oldStrLengthCount = strLengthCount;
    oldOutputStr = outputStr;
    oldEventQueue = eventQueue;
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

void UI::PreWorldMap(std::vector<Role*> roles) {
    BuildFrame(0, 0, 179, 49);
    BuildHollowFrame(121, 0, 179, 49);
    BuildHollowFrame(121, 28, 179, 35); // 玩家框
    BuildHollowFrame(121, 35, 179, 42); // 玩家框
    BuildHollowFrame(121, 42, 179, 49); // 玩家框
    BuildHollowFrame(0, 0, 121, 5); // 上欄
    moveCursor(0, 46);
    BuildFrame(121, 28, 179, 35);
    BuildFrame(121, 35, 179, 42);
    BuildFrame(121, 42, 179, 49);

    std::cout << BG_WHITE;
    UI::displayMapGrid();
    //UI::BuildVoid(1, 5, 120, 49);
    for (int i = 0; i < roles.size(); i++) {
        displayPlayerInfo(121, 28 + i * 7, roles[i]);
    }

    PrintWorldMap();
}

// 這是為了效能才會寫這麼醜
void UI::PrintWorldMap() {
    using namespace WorldMap;
    std::string colorLast;
    int H = WorldMap::getHeight();
    int W = WorldMap::getWidth();
    for (int c = 4; c >= 0; c--) {
        std::cout << getColorBoard()[c];
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 15; j++) {
                int x = j + getPos().first - 7;
                int y = i + getPos().second - 5;
                if (x < 0 || x >= W || y < 0 || y >= H) {
                    if (c == 0) {
                        for (int ii = 0; ii < 3; ii++) {
                            moveCursor(2 + j * 8, 6 + i * 4 + ii);
                            std::cout << "      ";
                        }
                    }
                    continue;
                }
                if (getMap()[y][x] != c)
                    continue;
                for (int ii = 0; ii < 3; ii++) {
                    moveCursor(2 + j * 8, 6 + i * 4 + ii);
                    std::cout << "      ";
                }

            }
        }
    }
    std::cout << BG_BRIGHT_RED;
    for (auto E : WorldMap::enemys) {
        if (WorldMap::VisibleOnMap(E->GetPosition())) {
            int x = E->GetPosition().first - pos.first + 7;
            int y = E->GetPosition().second - pos.second + 5;
            for (int ii = 0; ii < 3; ii++) {
                moveCursor(2 + x * 8, 6 + y * 4 + ii);
                std::cout << "      ";
            }
        }
    }
    std::cout << BG_BRIGHT_CYAN;
    for (auto R : WorldMap::roles) {
        if (WorldMap::VisibleOnMap(R->GetPosition())) {
            int x = R->GetPosition().first - pos.first + 7;
            int y = R->GetPosition().second - pos.second + 5;
            for (int ii = 0; ii < 3; ii++) {
                moveCursor(2 + x * 8, 6 + y * 4 + ii);
                std::cout << "      ";
            }
        }
    }

    moveCursor(0, 0);
    std::cout << RESET;
}

void UI::distanceDisplay(int x, int y, int distance) {
    if (distance < 0) {
        return;
    }
    using namespace std;
    // static int dlog = 0;
    // static int xlog = 0;
    // static int ylog = 0;
    int x1 = (x + 7) * 8;
    int y1 = (y + 5) * 4 + 5;
    int d1 = distance;
    int x2, y2;
    for (int i = 0; i <= d1; i++) {
        x2 = x1 - 8 * (d1 - i);
        y2 = y1 - i * 4;
        printOnMap(x2 + 2, y2, "      ");
        printOnMap(x2, y2, "  ");
        printOnMap(x2 + 8, y2, "  ");
        for (int k = 1; k <= 3; k++) {
            printOnMap(x2, y2 + k, "  ");
        }

        x2 = x1 + 8 * (d1 - i);
        y2 = y1 - i * 4;
        printOnMap(x2 + 2, y2, "      ");
        printOnMap(x2, y2, "  ");
        printOnMap(x2 + 8, y2, "  ");
        for (int k = 1; k <= 3; k++) {
            printOnMap(x2 + 8, y2 + k, "  ");
        }

        x2 = x1 - 8 * (d1 - i);
        y2 = y1 + 4 + i * 4;
        printOnMap(x2 + 2, y2, "      ");
        printOnMap(x2, y2, "  ");
        printOnMap(x2 + 8, y2, "  ");
        for (int k = 1; k <= 3; k++) {
            printOnMap(x2, y2 - k, "  ");
        }

        x2 = x1 + 8 * (d1 - i);
        y2 = y1 + 4 + i * 4;
        printOnMap(x2 + 2, y2, "      ");
        printOnMap(x2, y2, "  ");
        printOnMap(x2 + 8, y2, "  ");
        for (int k = 1; k <= 3; k++) {
            printOnMap(x2 + 8, y2 + k - 4, "  ");
        }
    }
    //distanceDisplay(x, y, distance - 1);
    cout << RESET;
}