#pragma once
#include<vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include"Level.h"
using namespace cv;

class StateStack {
	vector<Level> stack;
public:
	void addState(Level);
	bool move(const char);
	void draw(Mat);
	Level reverse();
	Level& last();
	Level& ndLast();
};