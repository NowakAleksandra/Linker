#include"Tile.h"

int Tile::getX() {
	return x;
}

int Tile::getY() {
	return y;
}

bool Tile::getVisited(int v) {
	return visited[v];
}

int Tile::getEdgeState(int v) {
	return edge[v];
}

void Tile::visit(int v) {
	visited[v] = true;
}

Tile::Tile(int _x, int _y, int* e){
	x = _x;
	y = _y;
	for (int i = 0; i < 4; i++) {
		edge[i] = e[i];
		visited[i] = false;
	}
}