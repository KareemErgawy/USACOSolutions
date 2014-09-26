/*
 ID: kareem_2
 PROG: sort3
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int _main() {
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int inputSize;
	fin >> inputSize;
	int* input = new int[inputSize];
	int regionBoundaries[4];
	regionBoundaries[0] = regionBoundaries[1] = regionBoundaries[2]
			= regionBoundaries[3] = 0;
	//	region[4] = inputSize;
	for (int i = 0; i < inputSize; i++) {
		fin >> input[i];
		regionBoundaries[input[i]]++;
	}

	int graph[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			graph[i][j] = 0;
		}
	}

	for (int i = 1; i < 4; i++) {
		regionBoundaries[i] = regionBoundaries[i] + regionBoundaries[i - 1];
		for (int j = regionBoundaries[i - 1]; j < regionBoundaries[i]; j++) {
			if (i != input[j]) {
				//				cout << j << " out of range" << endl;
				graph[i][input[j]]++;
			}
		}
		//		cout << i << " " << region[i] << endl;
	}

	int minMoves = 0;

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			int min = (graph[i][j] < graph[j][i]) ? graph[i][j] : graph[j][i];
			minMoves = minMoves + min;
			graph[i][j] -= min;
			graph[j][i] -= min;
		}
	}

	//	for (int i = 1; i < 4; i++) {
	//		for (int j = 1; j < 4; j++) {
	//			cout << graph[i][j] << " ";
	//		}
	//		cout << endl;
	//	}

	if (graph[1][2] != 0) {
		minMoves += (graph[1][2] * 2);
	}

	if (graph[1][3] != 0) {
		minMoves += (graph[1][3] * 2);
	}

	fout << minMoves << endl;
	return 0;
}
