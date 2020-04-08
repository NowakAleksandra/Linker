#include<iostream>
#include"Stack.h"

const char input();

int main(void) {
	Stack stack; //inicjalizacja stosu stanow
	stack.init(1);
	while (true) {
		stack.last().draw(); //szkic poziomu, tymczasowy
		if (stack.lineConnected() && stack.isSolution()) {
			std::cout << "DOBRZE!\n";
			stack.reset(1);
		}
		const char key = input(); //obsluga wejscia, tymczasowa
		if (key == '#') {
			stack.reset(1);
		}
		else {
			stack.move(key);
		}
	}
}

const char input() {
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