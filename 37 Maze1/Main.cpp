/*
 ID: kareem_2
 PROG: maze1
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int deltaI[4] = { -1, 0, 1, 0 };
int deltaJ[4] = { 0, 1, 0, -1 };
ifstream fin("maze1.in");
ofstream fout("maze1.out");
void dijkstra(int exitI, int exitJ, int width, int height, bool*** adjacancy,
		int** distance) {
	bool** visited = new bool*[height];
	for (int i = 0; i < height; i++) {
		visited[i] = new bool[width];
		for (int j = 0; j < width; j++) {
			distance[i][j] = width * height + 1;
			visited[i][j] = false;
		}
	}

	distance[exitI][exitJ] = 0;
	int nodesVisited = 0;
	while (nodesVisited < (width * height)) {
		int min = width * height + 2, minI, minJ;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (!visited[i][j] && distance[i][j] < min) {
					min = distance[i][j];
					minI = i;
					minJ = j;
				}
			}
		}

		if (min == (width * height + 1)) {
			break;
		}

		visited[minI][minJ] = true;
		nodesVisited++;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				for (int k = 0; k < 4; k++) {
					if (adjacancy[i][j][k]) {
						int ni, nj;
						ni = i + deltaI[k];
						nj = j + deltaJ[k];
						if (distance[ni][nj] > distance[i][j] + 1) {
							distance[ni][nj] = distance[i][j] + 1;
						}
					}
				}
			}
		}
	}
}

int main() {

	int width, height;
	char** maze;
	fin >> width >> height;
	maze = new char*[height * 2 + 1];
	char dummy;
	fin.get(dummy);
	for (int i = 0; i < height * 2 + 1; i++) {
		maze[i] = new char[width * 2 + 1];
		for (int j = 0; j < width * 2 + 1; j++) {
			fin.get(maze[i][j]);
			//			fout << maze[i][j];
		}
		fin.get(dummy);
		//		fout << endl;
	}

	bool*** adjacency = new bool**[height];
	int exit1I = -1, exit1J, exit2I, exit2J;
	for (int i = 0; i < height * 2 + 1; i++) {
		if (i % 2) {
			adjacency[i / 2] = new bool*[width];
			for (int j = 0; j < width * 2 + 1; j++) {
				if (j % 2) {
					adjacency[i / 2][j / 2] = new bool[4];
					for (int k = 0; k < 4; k++) {
						adjacency[i / 2][j / 2][k] = false;
						int ni = i + deltaI[k];
						int nj = j + deltaJ[k];
						if (maze[ni][nj] == ' ') {
							ni = ni + deltaI[k];
							nj = nj + deltaJ[k];
							if (ni < 0 || ni >= (height * 2 + 1) || nj < 0
									|| nj >= (width * 2 + 1)) {
								if (exit1I == -1) {
									exit1I = i / 2;
									exit1J = j / 2;
								} else {
									exit2I = i / 2;
									exit2J = j / 2;
								}
							} else {
								adjacency[i / 2][j / 2][k] = true;
							}
						}
					}
				}
			}
		}
	}

	//	for (int i = 0; i < height; i++) {
	//		for (int j = 0; j < width; j++) {
	//			for (int k = 0; k < 4; k++) {
	//				fout << adjacency[i][j][k];
	//			}
	//			fout << endl;
	//		}
	//	}
	int** distance1 = new int*[height];
	int** distance2 = new int*[height];

	for (int i = 0; i < height; i++) {
		distance1[i] = new int[width];
		distance2[i] = new int[width];
	}

	dijkstra(exit1I, exit1J, width, height, adjacency, distance1);
	dijkstra(exit2I, exit2J, width, height, adjacency, distance2);

	int max = -1;

//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			fout << distance1[i][j] << " ";
//		}
//		fout << endl;
//	}
//	fout << endl;
//
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			fout << distance2[i][j] << " ";
//		}
//		fout << endl;
//	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int min = (distance1[i][j] < distance2[i][j]) ? distance1[i][j]
					: distance2[i][j];
			if (min < width * height + 1)
				max = (max < min) ? min : max;
		}
	}

	fout << (max + 1) << endl;
	return 0;
}
