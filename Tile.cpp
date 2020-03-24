#include"Tile.h"

int Tile::getX() const {
	return x;
}

int Tile::getY() const {
	return y;
}

bool Tile::getVisited(int v) const {
	return visited[v];
}

Tile::Tile(int _x, int _y, int* e){
	x = _x;
	y = _y;
	for (int i = 0; i < 4; i++) {
		edge[i] = e[i];
		visited[i] = false;
	}
}