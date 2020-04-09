#include<iostream>
#include"Stack.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include"StateStack.h"

using namespace std;
using namespace cv;



char inputaa();

int main(void) {
	Stack stack; //inicjalizacja stosu stanow
	stack.init(1);
	while (true) {
		stack.last().draw(); //szkic poziomu, tymczasowy
		if (stack.lineConnected() && stack.isSolution()) {
			std::cout << "DOBRZE!\n";
			stack.reset(1);
		}
		const char key = inputaa(); //obsluga wejscia, tymczasowa
		if (key == '#') {
			stack.reset(1);
		}
		else {
			stack.move(key);
		}

	}
}

char inputaa()
{
	char choice;
	std::cin >> choice;
	switch (choice) {
	case 'w': // up
		return 'U';
	case 'a': // left
		return 'L';
	case 's': // down
		return 'D';
	case 'd': // right
		return 'R';
	default: // reset
		return '#';
	}
}