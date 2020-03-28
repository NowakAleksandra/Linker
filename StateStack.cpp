#include"StateStack.h"

void StateStack::addState(Level state) {
	stack.push_back(state);
}

Level& StateStack::last() {
	return stack.back();
}

Level StateStack::reverse() {
	stack.pop_back();
	return last();
}

Level& StateStack::ndLast() {
	return stack[stack.size() - 2];
	//risk of executing when stack is of size 1
}