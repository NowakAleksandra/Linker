//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//int main()
//{
//    Mat img = imread("lena.jpg");
//    namedWindow("image", WINDOW_NORMAL);
//    imshow("image", img);
//    waitKey(0);
//    return 0;
//}

#include<iostream>
#include"Level.h"
using namespace std;

bool isVisited(const Level &lvl, int _x, int _y, int _v) {
	for (int i = 0; i < lvl.grid.size(); i++) {
		if (lvl.grid[i].getX() == _x && lvl.grid[i].getY() == _y) {
			return lvl.grid[i].getVisited(_v);
		}
	}
}

int main(int argc, char* argv[]) {
	Level level(1);
	//level.displayInfo();

}
