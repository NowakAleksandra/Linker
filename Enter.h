#pragma once

class Enter {
	bool active;
	int x, y;
	int vertex;
public:
	Enter(int _x, int _y, int v);
	void changeState(bool state);
	bool isActive();
};