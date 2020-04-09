#include"Grid.h"
#include"Dot.h"
#include<fstream>
#include<string>
#include<iostream>

Point& Grid::getPoint(int _x, int _y) {
	for (int i = 0; i < vertex.size(); i++) {
		if (vertex[i].x == _x && vertex[i].y == _y) {
			return vertex[i];
		}
	}
	for (int i = 0; i < edge.size(); i++) {
		if (edge[i].x == _x && edge[i].y == _y) {
			return edge[i];
		}
	}
}

bool Grid::doesPointExist(int _x, int _y) {
	for (int i = 0; i < vertex.size(); i++) {
		if (vertex[i].x == _x && vertex[i].y == _y) {
			return true;
		}
	}
	for (int i = 0; i < edge.size(); i++) {
		if (edge[i].x == _x && edge[i].y == _y) {
			return true;
		}
	}
	return false;
}

void Grid::draw() {
	const int xGridSize = 9;
	const int yGridSize = 9;
	for (int i = 0; i < yGridSize; i++) {
		for (int j = 0; j < xGridSize; j++) {
			char symbol = ' ';
			// do optymalizacji z funckja getPoint
			if (j % 2 == 0 && i % 2 == 0) {
				for (int m = 0; m < vertex.size(); m++) {
					if (j == vertex[m].x && i == vertex[m].y) {
						symbol = '+';
					}
				}
			}
			else {
				for (int m = 0; m < edge.size(); m++) {
					if (j == edge[m].x && i == edge[m].y) {
						if (i % 2 == 0) {
							symbol = '-';
						}
						else {
							symbol = '|';
						}
					}
				}
			}
			if (doesPointExist(j, i)) {
				if (getPoint(j, i).visited) {
					symbol = '#';
				}
			}
			std::cout << symbol;
		}
		std::cout << "\n";
	}
}

Grid::Grid(int n) {
	std::ifstream file;
	file.open("levels/" + std::to_string(n) + ".txt", std::ifstream::in);
	std::string line;
	int stage = 0;
	while (file.good()) {
		getline(file, line);
		if (line == "") {
			continue;
		}
		else if (line == "$VERTEX") {
			stage = 1;
		}
		else if (line == "$EDGE") {
			stage = 2;
		}
		else if (line == "$START") {
			stage = 3;
		}
		else if (line == "$END") {
			stage = 4;
		}
		else if (line == "$DOT") {
			stage = 5;
		}
		else if (stage == 1) {
			vertex.push_back(Point(line[0] - '0', line[2] - '0'));
		}
		else if (stage == 2) {
			edge.push_back(Point(line[0] - '0', line[2] - '0'));
		}
		else if (stage == 3) {
			start.push_back(Coords(line[0] - '0', line[2] - '0'));
		}
		else if (stage == 4) {
			end.push_back(Coords(line[0] - '0', line[2] - '0'));
		}
		else if (stage == 5) {
			logElem.emplace_back(new Dot(line[0] - '0', line[2] - '0'));
		}
	}
}