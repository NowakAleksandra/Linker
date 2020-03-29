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
#include"StateStack.h"
using namespace std;

char checkForMoveKeyPress(); // debug

int main(void) {
	StateStack stateStack;
	stateStack.addState(Level(1));
	stateStack.last().addPlayer(Player(0, 0, 3));
	stateStack.last().getTile(0, 0).visit(3);
	while (true) {
		cout << stateStack.last().getPlayer(0).getX() << ", " << stateStack.last().getPlayer(0).getY() << ", " << stateStack.last().getPlayer(0).getV() << "\n";
		if (stateStack.move(checkForMoveKeyPress()))
			cout << "Moved!\n";
		else
			cout << "Coudn't move!\n";
	}
}

char checkForMoveKeyPress() {
	//debug mode
	char k;
	while (true) {
		cin >> k;
		switch (k) {
		case 'w':
			return 'u';
		case 'a':
			return 'l';
		case 's':
			return 'd';
		case 'd':
			return 'r';
		}
	}
}
