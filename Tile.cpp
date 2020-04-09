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

void Tile::draw(Mat image)
{
	int thickness = 2;
	int lineType = LINE_8;

	line(image,
		Point(0, 15 * 400/ 16), 
		Point(400, 15 * 400 / 16),
		Scalar(0, 0, 1),
		thickness,
		lineType);
	
	line(image,
		Point(400, 15 * 400 / 16),
		Point(400, 1 * 400 / 16),
		Scalar(0, 0, 1),
		thickness,
		lineType);

	line(image,
		Point(400, 1 * 400 / 16),
		Point(0, 1 * 400 / 16),
		Scalar(0, 0, 1),
		thickness,
		lineType);

	line(image,
		Point(0, 15 * 400 / 16),
		Point(0, 1 * 400 / 16),
		Scalar(0, 0, 1),
		thickness,
		lineType);
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