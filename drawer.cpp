#include "drawer.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;



Drawer::Drawer(int levelno)
{
	Linker_window = "Linker: Level number";

	Linker = Mat::zeros(500, 500, CV_8UC3);
}

void Drawer::draw(Level CurrentLevel)
{

	int thickness = 2;
	int lineType = 8;
	ellipse(Linker,
		cv::Point(500 / 2, 500 / 2),
		Size(500 / 4, 500 / 16),
		90,						//angle
		0,
		360,
		Scalar(255, 0, 0),
		thickness,
		lineType);



	imshow(Linker_window, Linker);
	moveWindow(Linker_window, 0, 200);

	waitKey(0);
}
