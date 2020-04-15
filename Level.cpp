#include"Level.h"
#include<iostream>

bool Level::doesPointExist(int x, int y) const {
	for (int i = 0; i < panel.size(); i++) {
		if (x == panel[i].getX() && y == panel[i].getY()) {
			return true;
		}
	}
	return false;
}

void Level::showPanelDebug() const {
	for (int i = 0; i < panel.size(); i++) {
		std::cout << panel[i].getX() << " " << panel[i].getY() << "\n";
	}
}

Level::Level(std::vector<OurPoint>& panel, std::vector<std::shared_ptr<MapElement>>& mapElem, OurPoint& entry, OurPoint& exit) {
	this->panel = panel;
	this->mapElem = mapElem;
	this->entry = entry;
	this->exit = exit;
}