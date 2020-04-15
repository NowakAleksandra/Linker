#pragma once
#include "Level.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;

class Drawer {
	std::string Linker_window;

	Mat Linker;
public:
	Drawer(int levelno);
	void draw(Level CurrentLevel);


};