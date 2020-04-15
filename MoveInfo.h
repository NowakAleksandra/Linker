#pragma once
#include"Player.h"

class MoveInfo : public Player {
	// mimic, contains information about a state of a player
	// not sure if it is neccecary atm
public:
	MoveInfo(int x = -1, int y = -1, char dir = '0') : Player(x, y, dir) { }
};