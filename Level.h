#pragma once
#include"Point.h"
#include"MapElement.h"
#include<vector>
#include<memory>

class Level {
	std::vector<OurPoint> panel;
	std::vector<std::shared_ptr<MapElement>> mapElem;
	OurPoint entry;
	OurPoint exit;
public:
	bool doesPointExist(int x, int y) const;
	void showPanelDebug() const;
	Level(std::vector<OurPoint>& panel, std::vector<std::shared_ptr<MapElement>>& mapElem, OurPoint& entry, OurPoint& exit);
	// default constructor
	Level() { }
};