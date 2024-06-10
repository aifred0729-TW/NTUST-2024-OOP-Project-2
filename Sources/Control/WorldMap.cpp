#include "../../Includes/Control/WorldMap.h"
#include "ConstData.h"
#include <Color.h>
#include <UI.h>

int WorldMap::HEIGHT = 50;
int WorldMap::WIDTH = 140;

std::pair<int, int> WorldMap::pos = { 0, 0 };
std::vector<std::vector<int>>  WorldMap::map; // Map Storge
std::vector<std::vector<bool>> WorldMap::fog; // War Fog (Make some lamp?)
std::vector<std::vector<std::string>>  WorldMap::renderMap; // 每個單元為可輸出色塊
std::vector<Enemy*> WorldMap::enemys;
std::vector<Role*> WorldMap::roles;

const std::vector<std::string> colorBoard = { BG_BRIGHT_BLACK, BG_WHITE, BG_BRIGHT_BLACK, BG_GREEN, BG_BRIGHT_BLUE, BG_BRIGHT_RED ,BG_BRIGHT_RED };

void WorldMap::loadMap(std::string mapFile) {
    using namespace std;
    //loadMap("../Resources/" + mapFile);
    //

    ifstream fp("../Resources/" + mapFile);
    if (!fp.is_open()) {
        fp.open("../Resources/" + mapFile + ".txt");
    }
    if (!fp.is_open()) {
        cout << "WORLD FAIL READING";
    }
    stringstream ss("");
    string stmp = "";
    int itmp = 0;
    int columns = 0;
    int rows = 0;

    //map.resize(50);

    while (!fp.eof()) {
        std::vector<int> mapRow;
        std::getline(fp, stmp);
        if (columns == 0)
            columns = stmp.length();
        for (unsigned int i = 0; i < columns; i++) {
            ss << stmp[i];
            ss >> itmp;
            ss.clear();
            mapRow.push_back(itmp);

        }
        map.push_back(mapRow);
        rows++;
    }

    HEIGHT = rows;
    WIDTH = columns;
    loadFog();
    renderColor();
    return;
}

void WorldMap::loadFog() {
    using namespace std;

    fog.resize(HEIGHT);

    for (unsigned int i = 0; i < HEIGHT; i++) {
        fog[i].resize(WIDTH, true);
    }

    return;
}

std::vector<std::vector<int>> WorldMap::getMap() { return map; }
std::vector<std::vector<std::string>> WorldMap::getRenderMap() { return renderMap; }
std::vector<std::vector<bool>> WorldMap::getFog() { return fog; }
std::vector<std::string> WorldMap::getColorBoard() { return colorBoard; }
std::pair<int, int> WorldMap::getPos() { return pos; }
int WorldMap::getHeight() { return HEIGHT; }
int WorldMap::getWidth() { return WIDTH; }

void WorldMap::SetEnemys(std::vector<Enemy*> enemys) {
    WorldMap::enemys = enemys;
}

void WorldMap::SetRoles(std::vector<Role*> roles) {
    WorldMap::roles = roles;
}

void WorldMap::SetMap(int row, int col, int element) {
    map[row][col] = element;
    renderColor();
    return;
}

void WorldMap::SetFog(int row, int col) {
    using namespace std;
    const int fogWidth = 5;
    int topLimit = row - (fogWidth);
    int downLimit = row + (fogWidth);
    int leftLimit = col - (fogWidth);
    int rightLimit = col + (fogWidth);
    for (int i = topLimit; i < row; i++) {
        if (i < 0 || i >= HEIGHT) continue;
        for (int j = col - (i - topLimit); j < col + (i - topLimit) - 1; j++) {
            if (j < 0 || j >= WIDTH) continue;
            fog[i][j] = (fog[i][j]) ? false : true;
        }
    }
    for (int i = row; i < downLimit; i++) {
        if (i < 0 || i >= HEIGHT) continue;
        for (int j = col - (downLimit - i); j < col + (downLimit - i) - 1; j++) {
            if (j < 0 || j >= WIDTH) continue;
            fog[i][j] = (fog[i][j]) ? false : true;
        }
    }
    return;
}

bool WorldMap::posValid(std::pair<int, int> pos) {
    return !(pos.first < 0 || pos.first >= WIDTH || pos.second < 0 || pos.second >= HEIGHT);
}


int WorldMap::setPos(std::pair<int, int> pos) {
    if (posValid(pos)) {
        WorldMap::pos = pos;
        return 0;
    }
    // 位置無效
    return 1;
}

int WorldMap::movePos(std::pair<int, int> change) {
    std::pair<int, int> dPos = { change.first + pos.first , change.second + pos.second };
    if (posValid(dPos)) {
        WorldMap::pos = dPos;
        return 0;
    }
    // 位置無效
    return 1;
}

int WorldMap::movePos(int x, int y) {
    return movePos({ x,y });
}

void WorldMap::renderColor() {
    renderMap.resize(HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        renderMap[i].resize(WIDTH);
        for (int j = 0; j < WIDTH; j++) {
            renderMap[i][j] = map[i][j] <= 4 ? colorBoard[map[i][j]] : BG_BRIGHT_RED;
        }
    }
}


bool WorldMap::VisibleOnMap(std::pair<int, int > pos) {
    int dx = pos.first - WorldMap::pos.first;
    int dy = pos.second - WorldMap::pos.second;
    return (!(dx < -7 || dx > 7 || dy < -5 || dy > 5));
}

// Map Structure
   // 0 = Player (不他不該出現在這裡)
   // 1 = Ground (Allow to Pass)
   // 2 = Wall   (Not Allow to Pass)
   // 3 = Tree   (Not Allow to Pass)
   // 4 = Water  (Not Allow to Pass)
   // 5 = Shop   (Allow to Pass) (修改至可互動物件)
   // 6 = Enemy  (Allow to Pass) (修改至可互動物件)