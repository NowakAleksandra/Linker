#pragma once

class Enter {
	int x, y;
	int vertex;
	bool active;
public:
	Enter(int _x, int _y, int v);
	void changeState(bool);
	bool isActive();
};