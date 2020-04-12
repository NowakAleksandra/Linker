#include"Game.h"
#include<fstream>

bool checkForPointInVector(int x, int y, std::vector<Point> *v) {
	for (int i = 0; i < v->size(); i++) {
		if (x == v->at(i).getX() && y == v->at(i).getY()) {
			return true;
		}
	}
	return false;
}

void Game::loadNewLevel(int lvlNo) {
	std::ifstream file;
	file.open("levels/" + std::to_string(lvlNo) + ".txt", std::ifstream::in);
	std::string line;
	int stage = 0, x = -1, y = -1;
	std::vector<Point> panel;
	std::vector<std::shared_ptr<MapElement>> mapElem;
	Point entry, exit;
	const std::pair<int, int> shift[8] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1} };
	const int labelNo = 4;
	const std::vector<std::string> label = { "$TILE", "$POINT", "$START", "$END" };
	while (file.good()) {
		getline(file, line);
		if (line == "") {
			continue;
		}
		if (line[0] == '$') {
			for (int i = 0; i < labelNo; i++) {
				if (line == label[i]) {
					stage = i;
					continue;
				}
			}
		}
		else {
			x = line[0] - '0';
			y = line[2] - '0';
		}
		switch (stage) {
		case 1:
			for (int i = 0; i < 8; i++) {
				if (!checkForPointInVector(x, y, &panel)) {
					x += shift[i].first;
					y += shift[i].second;
					panel.push_back(Point(x + shift[i].first, y + shift[i].second));
				}
			}
			break;
		case 2:
			panel.push_back(Point(x, y));
			break;
		case 3:
			entry = Point(x, y);
			break;
		case 4:
			exit = Point(x, y);
			break;
		}
	}
	level = Level(panel, mapElem, entry, exit);
	Player player(entry.getX(), entry.getY());
	moveHandler = MoveHandler(player);
}

Game::Game(int currLvlNo) {
	this->currLvlNo = currLvlNo;
	loadNewLevel(currLvlNo);
}
