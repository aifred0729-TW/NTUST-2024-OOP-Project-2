#include "../../Includes/Display/Displayer.h"
#include <Role.h>
#include <Enemy.h>
#include <Entity.h>
#include <Dice.h> //待確認
#include <Attribute.h>
#include <KeyBoard.h>
#include "Color.h"

//移動光標
void Displayer::moveCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Displayer::BuildVoid(int x1, int y1, int x2, int y2) {
    int right = (x1 > x2) ? x1 : x2;
    int left = (x1 > x2) ? x2 : x1;
    int up = (y1 > y2) ? y2 : y1;
    int down = (y1 > y2) ? y1 : y2;
    for (int i = up + 1; i <= down - 1; i++) {
        moveCursor(left + 1, i);
        for (int j = left + 1; j <= right - 1; j++) {
            std::cout << " ";
        }
    }
    std::cout << RESET;
}

void Displayer::BuildHollowFrame(int x1, int y1, int x2, int y2) {
    int right = (x1 > x2) ? x1 : x2;
    int left = (x1 > x2) ? x2 : x1;
    int up = (y1 > y2) ? y2 : y1;
    int down = (y1 > y2) ? y1 : y2;
    for (int i = up; i <= down; i++) {
        moveCursor(right, i);
        std::cout << "|";
        moveCursor(left, i);
        std::cout << "|";
    }
    for (int j = left; j <= right; j++) {
        moveCursor(j, up);
        std::cout << "-";
        moveCursor(j, down);
        std::cout << "-";
    }
    moveCursor(right, up);
    std::cout << "+";
    moveCursor(right, down);
    std::cout << "+";
    moveCursor(left, up);
    std::cout << "+";
    moveCursor(left, down);
    std::cout << "+";
    std::cout << RESET;
}

void Displayer::BuildFrame(int x1, int y1, int x2, int y2) {
    BuildHollowFrame(x1, y1, x2, y2);
    BuildVoid(x1, y1, x2, y2);
    std::cout << RESET;
}

void Displayer::displayFile(std::ifstream& inputFile) {
    std::string str;
    while (!inputFile.eof()) {
        std::getline(inputFile, str);
        std::cout << str;
        std::cout << std::endl;
    }
}

void Displayer::displayFile(const std::string filename, int x, int y) {
    std::ifstream inputFile("../Sources/Display/" + filename);
    std::string output;
    int i = 0;
    if (!inputFile.is_open()) {
        moveCursor(x, y + i);
        std::cout << "Failed while reading file";
        return;
    }
    while (!inputFile.eof()) {
        moveCursor(x, y + i);
        getline(inputFile, output);
        std::cout << output;
        i++;
    }
    std::cout << RESET;
}

void Displayer::displayString(const std::string input, int x, int y) {
    std::stringstream ss;
    std::string output;
    ss << input;
    int i = 0;
    while (!ss.eof()) {
        moveCursor(x, y + i);
        getline(ss, output);
        std::cout << output;
        i++;
    }
    std::cout << RESET;
}

void Displayer::displayString(int x, int y, const std::string input) {
    displayString(input, x, y);
}

std::string Displayer::horizontalLine(const std::string str, int length, const char c) {
    std::string output("");
    int i = length - str.length();
    for (int j = 0; j < i / 2; j++) {
        output.push_back(c);
    }
    output = output + str;
    for (int j = 0; j < i - (i / 2); j++) {
        output.push_back(c);
    }
    return output;
}

std::string Displayer::HpDisplayer(int hp, int max_hp) {
    std::string hpStr("");
    double hpRatio = (double)hp / max_hp;
    for (int i = 0; i < 40; i++) {
        if (hpRatio > 0) {
            hpStr = hpStr + BG_GREEN + " " + RESET;
        }
        else {
            hpStr = hpStr + BG_RED + " " + RESET;
        }
        hpRatio -= 0.025;
    }
    return hpStr;
}

std::string Displayer::FocusDisplayer(int focus, int max_focus) {
    std::string focusStr("");
    for (int i = 0; i < max_focus; i++) {
        if (focus > 0) {
            focusStr = focusStr + BOLD + YELLOW + "*" + RESET + " ";
        }
        else {
            focusStr = focusStr + DARK + WHITE + "*" + RESET + " ";
        }
        focus--;
    }
    return focusStr;
}

std::string Displayer::DiceDisplayer(std::vector<int> diceLog) {
    int count = diceLog.size();
    std::string DiceStr("");
    for (int i = 0; i < count; i++) {
        if (diceLog[i] == 0) {
            DiceStr = DiceStr + DARK + WHITE;
        }
        else if (diceLog[i] == 1) {
            DiceStr = DiceStr + WHITE;
        }
        else if (diceLog[i] == 2) {
            DiceStr = DiceStr + YELLOW;
        }
        DiceStr = DiceStr + "*" + RESET + " ";
    }
    return  DiceStr;
}

void Displayer::displayDice(std::vector<int> diceLog) {
    int count = diceLog.size();
    int x = 61 - 6 * count;
    int x1 = x;
    int y = 36;
    //std::cout << BOLD << YELLOW;
    BuildVoid(0, 42, 121, 35);
    //BuildFrame(86 - 10 * count, 6, 93 + 10 * count, 13);

    for (int i = 0; i < count; i++) {
        std::cout << BOLD << BLACK;
        displayFile("Dice03.txt", x1, y);
        x1 += 12;
    }
    x1 = x;
    Sleep(500);
    for (int i = 0; i < count; i++) {
        if (diceLog[i] == 0) {
            std::cout << DARK << WHITE;
        }
        else if (diceLog[i] == 1) {
            std::cout << BOLD << CYAN;
        }
        else if (diceLog[i] == 2) {
            std::cout << YELLOW;
        }
        displayFile("Dice04.txt", x1, y);
        x1 += 12;
        Sleep(200);
    }
}

void Displayer::displayDice(int count, int focus) {
    int x = 61 - 6 * count;
    int x1 = x;
    int y = 36;
    BuildVoid(0, 42, 121, 35);

    for (int i = 0; i < count; i++) {
        if (focus > i) {
            std::cout << YELLOW;
        }
        else {
            std::cout << DARK << WHITE;
        }
        displayFile("Dice03.txt", x1, y);
        x1 += 12;
    }
}

void Displayer::displayPlayerInfo(int x, int y  /*, Player* player*/) {
    using namespace std;
    BuildFrame(x, y, x + 58, y + 7);
    moveCursor(x + 3, y + 2);
    cout << "Player: xxxxxx";
    moveCursor(x + 3, y + 3);
    cout << "Focus: " << "x / x " << FocusDisplayer(4, 6);
    moveCursor(x + 3, y + 4);
    cout << "HP: " << " xx / xx " << HpDisplayer(100, 100);
    moveCursor(x + 3, y + 5);
    cout << "PA: xx   PD: xx   MA: xx   MD: xx   SPD: xx   ACC: xx";
}

void Displayer::displayPlayerInfo(int x, int y, Role* role) {
    using namespace std;
    Attribute att = role->GetTotalAttribute();
    BuildVoid(x, y, x + 58, y + 7);
    moveCursor(x + 3, y + 2);
    cout << "Player: ";
    cout << role->GetName();
    moveCursor(x + 3, y + 3);
    cout << "Focus: " << std::setw(2) << std::setfill('0') << att.GetFocus() << " / " << std::setw(2) << std::setfill('0') << att.GetMaxFocus() << " ";
    cout << FocusDisplayer(att.GetFocus(), att.GetMaxFocus());
    moveCursor(x + 3, y + 4);
    cout << "HP:  " << att.GetHP() << " / " << att.GetMaxHP() << " ";
    cout << HpDisplayer(att.GetHP(), att.GetMaxHP());
    moveCursor(x + 3, y + 5);
    cout << "PA: " << std::setw(2) << std::setfill('0') << att.GetPA();
    cout << "   PD: " << std::setw(2) << std::setfill('0') << att.GetPD();
    cout << "   MA: " << std::setw(2) << std::setfill('0') << att.GetMA();
    cout << "   MD: " << std::setw(2) << std::setfill('0') << att.GetMD();
    cout << "   SPD: " << std::setw(2) << std::setfill('0') << att.GetSPD();
    cout << "   ACC: " << std::setw(2) << std::setfill('0') << att.GetACC();
}

void Displayer::displayPlayerInfo(int x, int y, Enemy* enemy) {
    using namespace std;
    Attribute att = enemy->GetTotalAttribute();
    BuildFrame(x, y, x + 58, y + 7);
    moveCursor(x + 3, y + 2);
    cout << "Name: ";
    cout << enemy->GetName();
    //moveCursor(x + 3, y + 3);
    //cout << "Focus: " << att.GetFocus() << " / " << att.GetMaxFocus() << " ";
    //cout << FocusDisplayer(att.GetFocus(), att.GetMaxFocus());
    moveCursor(x + 3, y + 4);
    cout << "HP:  " << std::setw(2) << std::setfill('0') << att.GetHP() << " / " << std::setw(2) << std::setfill('0') << att.GetMaxHP() << " ";
    cout << HpDisplayer(att.GetHP(), att.GetMaxHP());
    moveCursor(x + 3, y + 5);
    cout << "PA: " << std::setw(2) << std::setfill('0') << att.GetPA();
    cout << "   PD: " << std::setw(2) << std::setfill('0') << att.GetPD();
    cout << "   MA: " << std::setw(2) << std::setfill('0') << att.GetMA();
    cout << "   MD: " << std::setw(2) << std::setfill('0') << att.GetMD();
    cout << "   SPD: " << std::setw(2) << std::setfill('0') << att.GetSPD();
    cout << "   ACC: " << std::setw(2) << std::setfill('0') << att.GetACC();
}

void Displayer::displayPlayerInfo(int x, int y, Entity* entity) {
    using namespace std;
    Attribute att = entity->GetTotalAttribute();
    BuildFrame(x, y, x + 58, y + 7);
    moveCursor(x + 3, y + 2);
    cout << "Name: ";
    cout << entity->GetName();
    //moveCursor(x + 3, y + 3);
    //cout << "Focus: " << att.GetFocus() << " / " << att.GetMaxFocus() << " ";
    //cout << FocusDisplayer(att.GetFocus(), att.GetMaxFocus());
    moveCursor(x + 3, y + 4);
    cout << "HP:  " << std::setw(2) << std::setfill('0') << att.GetHP() << " / " << std::setw(2) << std::setfill('0') << att.GetMaxHP() << " ";
    cout << HpDisplayer(att.GetHP(), att.GetMaxHP());
    moveCursor(x + 3, y + 5);
    cout << "PA: " << std::setw(2) << std::setfill('0') << att.GetPA();
    cout << "   PD: " << std::setw(2) << std::setfill('0') << att.GetPD();
    cout << "   MA: " << std::setw(2) << std::setfill('0') << att.GetMA();
    cout << "   MD: " << std::setw(2) << std::setfill('0') << att.GetMD();
    cout << "   SPD: " << std::setw(2) << std::setfill('0') << att.GetSPD();
    cout << "   ACC: " << std::setw(2) << std::setfill('0') << att.GetACC();
}

void Displayer::displayMiddleRectangle() {
    std::cout << BG_YELLOW;
    BuildHollowFrame(25, 56, 29, 64);
}

void Displayer::displayMovement() {
    using namespace std;

    BuildHollowFrame(0, 0, 121, 5);
    cout << YELLOW;
    displayString(18, 2, "Player1: xxxxxx");
    displayString(53, 2, "Player2: xxxxxx");
    displayString(88, 2, "Player3: xxxxxx");
    moveCursor(18, 3);
}

void Displayer::displayPlayerBackpack() {
    using namespace std;
    BuildFrame(121, 0, 179, 28);
    displayString(124, 2, "Weapon:    ");
    displayString(124, 3, "Armor:     ");
    displayString(124, 4, "Accessory: ");

    displayString(124, 6, horizontalLine("Backpack", 53, '-'));
    for (int i = 0; i < 10; i++) {
        string str = "Item " + to_string(i + 1);
        displayString(124, 8 + i, str);
    }
}

void Displayer::displayPlayerStatusEffect() {
    using namespace std;
    BuildFrame(121, 0, 179, 28);
    displayString(124, 2, "Weapon:    ");
    displayString(124, 3, "Armor:     ");
    displayString(124, 4, "Accessory: ");

    displayString(124, 6, horizontalLine("State Effect", 53, '-'));
    for (int i = 0; i < 10; i++) {
        string str = "Status Effect " + to_string(i + 1);
        displayString(124, 8 + i, str);
    }
}

void Displayer::displayChoice(std::vector< std::string> choices, int select, int x, int y) {
    for (int i = 0; i < choices.size(); i++) {
        if (i == select) {
            std::cout << YELLOW;
            moveCursor(x - 3, y + i);
            std::cout << "->";
        }
        else {
            moveCursor(x - 3, y + i);
            std::cout << "  ";
        }
        displayString(choices[i], x, y + i);
    }
}

int Displayer::makeChoice(std::vector<std::string> choices, int x, int y) {
    bool keyState[KeyBoard::INVALID];
    int select = 0;
    while (1) {
        displayChoice(choices, select, x, y);
        KeyBoard::keyUpdate(keyState);
        if (keyState[KeyBoard::EW]) {
            if (select > 0) {
                select--;
            }
        }
        else if (keyState[KeyBoard::ES]) {
            if (select < choices.size() - 1) {
                select++;
            }
        }
        else if (keyState[KeyBoard::EESC]) {
            return -1;
        }
        else if (keyState[KeyBoard::ESPACE] || keyState[KeyBoard::EENTER]) {
            return select;
        }
    }
    return -1;
}

//for Active
void Displayer::displayChoice(std::vector<Active> choices, int select, int x, int y) {
    for (int i = 0; i < choices.size(); i++) {
        if (i == select) {
            std::cout << YELLOW;
            moveCursor(x - 3, y + i);
            std::cout << "->";
        }
        else {
            moveCursor(x - 3, y + i);
            std::cout << "  ";
        }
        displayString(choices[i].GetName(), x, y + i);
    }
}


//for Active
std::pair<std::string, int> Displayer::makeChoice(std::vector<Active> choices, int x, int y) {
    bool keyState[KeyBoard::INVALID];
    int select = 0;
    while (1) {
        displayChoice(choices, select, x, y);
        KeyBoard::keyUpdate(keyState);
        if (keyState[KeyBoard::EW]) {
            if (select > 0) {
                select--;
            }
        }
        else if (keyState[KeyBoard::ES]) {
            if (select < choices.size() - 1) {
                select++;
            }
        }
        else if (keyState[KeyBoard::EESC]) {
            //return "- 1";
        }
        else if (keyState[KeyBoard::ESPACE] || keyState[KeyBoard::EENTER]) {
            return { choices[select].GetName(), select };
        }
    }
    //return "-1";
}

void Displayer::printOnMap(int x, int y, std::string str) {
    if (!(x < 2 || x > 119 || y < 6 || y > 48)) {
        moveCursor(x, y);
        std::cout << str;
    }
}
