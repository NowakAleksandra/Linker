#include"Player.h"

void Player::setPlayerCoords(int _x, int _y, int _v) {
	x = _x;
	y = _y;
	v = _v;
}

int Player::getX() {
	return x;
}

int Player::getY() {
	return y;
}

int Player::getV() {
	return v;
}

Player::Player(int _x = 0, int _y = 0, int _v = 3) {
	setPlayerCoords(_x, _y, _v);
}