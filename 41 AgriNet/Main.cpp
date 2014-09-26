/*
 ID: kareem_2
 PROG: agrinet
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

typedef unsigned int uint;

uint mst(int n, uint** connectivity) {

	uint* distance = new uint[n];
	int* source = new int[n];
	bool* inTree = new bool[n];

	for (int i = 0; i < n; i++) {
		distance[i] = UINT_MAX;
		inTree[i] = false;
		source[i] = -1;
	}

	int treeSize = 1;
	uint treeCost = 0;
	inTree[0] = true;

	for (int j = 0; j < n; j++) {
		distance[j] = connectivity[0][j];
		source[j] = 0;
	}

	while (treeSize < n) {
		uint minDistance = INT_MAX;
		int minNode;
		for (int i = 0; i < n; i++) {
			if (inTree[i]) {
				for (int j = 0; j < n; j++) {
					if (!inTree[j] && connectivity[i][j] < minDistance) {
						minDistance = connectivity[i][j];
						minNode = j;
					}
				}
			}
		}

		distance[minNode] = minDistance;
		treeSize++;
		treeCost = treeCost + distance[minNode];
		inTree[minNode] = true;

		for (int j = 0; j < n; j++) {
			if (distance[j] > connectivity[minNode][j]) {
				distance[j] = connectivity[minNode][j];
				source[j] = minNode;
			}
		}
	}

	return treeCost;
}

int main() {

	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");

	int n;
	fin >> n;
	uint** connectivity = new uint*[n];

	for (int i = 0; i < n; i++) {
		connectivity[i] = new uint[n];
		for (int j = 0; j < n; j++) {
			fin >> connectivity[i][j];
		}
	}

	fout << mst(n, connectivity) << endl;

	return 0;
}
