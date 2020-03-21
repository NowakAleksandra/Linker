#include"Tile.h"

Tile::Tile(int _x, int _y, int* e){
	x = _x;
	y = _y;
	for (int i = 0; i < 4; i++) {
		edge[i] = e[i];
	}
}