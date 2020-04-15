#include"Game.h"
#include<fstream>

bool checkForOurPointInVector(int x, int y, std::vector<OurPoint> *v) {
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
	std::vector<OurPoint> panel;
	std::vector<std::shared_ptr<MapElement>> mapElem;
	OurPoint entry, exit;
	const std::pair<int, int> shift[8] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1} };
	const int labelNo = 4;
	const std::vector<std::string> label = { "$TILE", "$Point", "$START", "$END" };
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
		case 0:
			for (int i = 0; i < 8; i++) {
				int dx = x + shift[i].first;
				int dy = y + shift[i].second;
				if (!checkForOurPointInVector(dx, dy, &panel)) {
					panel.push_back(OurPoint(dx, dy));
				}
			}
			break;
		case 1:
			panel.push_back(OurPoint(x, y));
			break;
		case 2:
			entry = OurPoint(x, y);
			break;
		case 3:
			exit = OurPoint(x, y);
			break;
		}
	}
	level = Level(panel, mapElem, entry, exit);
	Player player(entry.getX(), entry.getY());
	moveHandler = MoveHandler(player);

}

Game::Game(int currLvlNo) : drawer(currLvlNo){
	this->currLvlNo = currLvlNo;
	loadNewLevel(currLvlNo);
}


void Game::drawPanel()
{
	drawer.draw(level);

}