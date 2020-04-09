#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

class Tile {
	int x, y;
	int edge[4];
	bool visited[4];
public:
	int getX();
	int getY();
	bool getVisited(int);
	void draw(Mat image);
	int getEdgeState(int);
	void visit(int);
	friend class Level;
	Tile(int _x, int _y, int* e);
};