#include "../../Includes/Control/WorldMap.h"
#include "ConstData.h"

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

void WorldMap::SetMap(int row, int col, MAP_ELEMENT element) {
	map[row][col] = element;
	return;
}

std::vector<std::vector<int>> WorldMap::GetMap() { return map; }