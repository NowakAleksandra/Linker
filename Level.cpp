#include<fstream>
#include<string>
#include"Level.h"
using namespace std;

void Level::setDifficulty(int _diff) {
	diff = _diff;
}

void Level::import(int lvl) {
	ifstream file;
	string path = "levels/level" + to_string(lvl) + ".txt";
	file.open(path, ifstream::in);
	string line;
	int loadingStage = 0;
	while (file.good()) {
		getline(file, line);
		if (line == "$GENERAL") {
			loadingStage = 0;
			getline(file, line);
			setDifficulty(line[0] - '0');
		}
		else if (line == "$TILES") {
			loadingStage = 1;
		}
		else if (loadingStage == 1) {
			int _x, _y, edgeStates[4];
			_x = line[0] - '0';
			_y = line[2] - '0';
			for (int i = 0; i < 4; i++) {
				edgeStates[i] = line[4 + 2 * i] - '0';
			}
			Tile processed(_x, _y, edgeStates);
			grid.push_back(processed);
		}
	}
}