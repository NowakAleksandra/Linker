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

void Drawer::draw(Level currentLevel)
{

	int thickness = 2;
	int lineType = 8;

	for (int i = 0; i < currentLevel.panel.size(); i++)
	{
		OurPoint point=currentLevel.panel[i];
		
		if (point.getType() == 0) continue;
		if (point.getType() == 1) {
			int x = point.getX();
			int y = point.getY();

			line(Linker,
				cv::Point(25*x+25, 25*y+50),
				cv::Point(25*x+75,25*y+ 50),
				Scalar(255, 0, 0),
				thickness = 1,
				lineType = 8);
		}
		if (point.getType() == 2) {
			int x = point.getX();
			int y = point.getY();

			line(Linker,
				cv::Point(25 * x + 50, 25 * y + 25),
				cv::Point(25 * x + 50, 25 * y + 75),
				Scalar(255, 0, 0),
				thickness = 1,
				lineType = 8);
		}

	}

	imshow(Linker_window, Linker);
	moveWindow(Linker_window, 0, 200);

	waitKey(0);
}
