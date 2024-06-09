#include "../../Includes/Control/WorldMap.h"
#include "ConstData.h"

int WorldMap::HEIGHT = 50;
int WorldMap::WIDTH = 140;
std::vector<std::vector<int>>   WorldMap::map;
std::vector<std::vector<bool>>  WorldMap::fog;
std::pair<int, int> WorldMap::pos;
void WorldMap::loadMap(std::string mapFile) {
    using namespace std;

    ifstream fp(mapFile);
    stringstream ss("");
    string stmp = "";
    int itmp = 0;
    int columns = 0;
    int rows = 0;

    map.resize(50);

    while (!fp.eof()) {
        std::getline(fp, stmp);
        if (columns == 0)
            columns = stmp.length();
        for (unsigned int i = 0; i < columns; i++) {
            ss << stmp[i];
            ss >> itmp;
            ss.clear();
            map[rows].push_back(itmp);
        }
        rows++;
    }

    HEIGHT = rows;
    WIDTH = columns;
    return;
}

void WorldMap::loadFog() {
    using namespace std;

    fog.resize(50);

    for (unsigned int i = 0; i < 50; i++) {
        fog[i].resize(140, true);
    }

    return;
}

std::vector<std::vector<int>> WorldMap::GetMap() { return map; }
std::vector<std::vector<bool>> WorldMap::GetFog() { return fog; }

void WorldMap::SetMap(int row, int col, int element) {
    map[row][col] = element;
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

void  WorldMap::setPos(std::pair<int, int> pos) {
    WorldMap::pos = pos;
}

std::pair<int, int> WorldMap::getPos() { return pos; }