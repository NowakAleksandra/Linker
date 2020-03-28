#include<iostream>
#include<fstream>
#include<string>
#include"Level.h"
using namespace std;

void Level::setDiff(int _diff) {
	diff = _diff;
}

void Level::setName(string _name) {
	name = _name;
}

void Level::setLevelNo(int _lvlNo) {
	lvlNo = _lvlNo;
}

void Level::displayInfo() {
	cout << name << "\n";
	cout << "Level no: " << lvlNo << "\n";
	cout << "Difficulty: " << diff << "\n";
	cout << "Number of tiles: " << grid.size() << "\n";
}

void Level::addPlayer(Player p) {
	player.push_back(p);
}

Player& Level::getPlayer(int n) {
	return player[n];
}

int Level::gridSize() const {
	return grid.size();
}

bool Level::doesTileExist(int _x, int _y) const {
	for (int i = 0; i < grid.size(); i++) {
		if (grid[i].getX() == _x && grid[i].getY() == _y) {
			return true;
		}
	}
	return false;
}

Tile& Level::getTile(int _x, int _y) {
	for (int i = 0; i < grid.size(); i++) {
		if (grid[i].getX() == _x && grid[i].getY() == _y) {
			return grid[i];
		}
	}
}

Level::Level(int lvl) {
	setLevelNo(lvl);
	ifstream file;
	string path = "levels/level" + to_string(lvl) + ".txt";
	file.open(path, ifstream::in);
	string line;
	int loadingStage = 0;
	while (file.good()) {
		getline(file, line);
		if (line == "") {
			continue;
		}
		else if (line == "$GENERAL") {
			loadingStage = 0;
			getline(file, line);
			setName(line);
			getline(file, line);
			setDiff(line[0] - '0');
		}
		else if (line == "$TILES") {
			loadingStage = 1;
		}
		else if (line == "$ENTER") {
			loadingStage = 2;
		}
		else if (line == "$EXIT") {
			loadingStage = 3;
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
		else if (loadingStage == 2) {
			int _x, _y, _vertex;
			_x = line[0] - '0';
			_y = line[2] - '0';
			_vertex = line[4] - '0';
			Enter processed(_x, _y, _vertex);
			entryPoints.push_back(processed);
		}
		else if (loadingStage == 3) {
			int _x, _y, _vertex;
			_x = line[0] - '0';
			_y = line[2] - '0';
			_vertex = line[4] - '0';
			Exit processed(_x, _y, _vertex);
			exitPoints.push_back(processed);
		}
	}
}