#pragma once
#include"Point.h"
#include"MapElement.h"
#include<vector>
#include<memory>

class Level {
	std::vector<Point> panel;
	std::vector<std::shared_ptr<MapElement>> mapElem;
	Point entry;
	Point exit;
public:
	bool doesPointExist(int x, int y) const;
	void showPanelDebug() const;
	Level(std::vector<Point>& panel, std::vector<std::shared_ptr<MapElement>>& mapElem, Point& entry, Point& exit);
	// default constructor
	Level() { }
};