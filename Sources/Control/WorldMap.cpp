#include <WorldMap.h>
#include <ConstData.h>

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

void WorldMap::loadMap(std::string mapFile) {
	using namespace std;

	ifstream fp(mapFile);
	stringstream ss("");
	string stmp = "";
	int itmp = 0;
	int row = 0;

	map.resize(50);

	while (fp >> stmp) {
		for (unsigned int i = 0; i < 140; i++) {
			ss << stmp[i];
			ss >> itmp;
			ss.clear();
			map[row].push_back(itmp);
		}
		row++;
	}

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

void WorldMap::SetMap(int row, int col, MAP_ELEMENT element) {
	map[row][col] = element;
	return;
}

void WorldMap::SetFog(int row, int col) {
	using namespace std;

	const int fogWidth = 10;

	int topLimit = row - (fogWidth / 2);
	int downLimit = row + (fogWidth / 2);
	int leftLimit = col - (fogWidth / 2);
	int rightLimit = col + (fogWidth / 2);

	for (int i = topLimit; i < row; i++) {
		if (i < 0 || i >= 50) continue;
		for (int j = col - (i - topLimit); j < col + (i - topLimit)-1; j++) {
			if (j < 0 || j >= 140) continue;
			fog[i][j] = (fog[i][j]) ? false : true;
		}
	}

	for (int i = row; i < downLimit; i++) {
		if (i < 0 || i >= 50) continue;
		for (int j = col - (downLimit - i); j < col + (downLimit - i)-1; j++) {
			if (j < 0 || j >= 140) continue;
			fog[i][j] = (fog[i][j]) ? false : true;
		}
	}

	return;
}

int WorldMap::manhattanDistance(std::pair<int, int> player, std::pair<int, int> enemy) {
	return std::abs((player.first - enemy.first) + (player.second, enemy.second));
}