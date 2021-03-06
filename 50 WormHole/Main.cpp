/*
 ID: kareem_2
 PROG: wormhole
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n;
int* pairings;
int** holePositions;
int loops = 0;
void testLoops() {

	for (int i = 0; i < n; i++) {
		int current = i;
		while (true) {
			int nearstDist = 1000000001;
			int nearestNeighbor = -1;
			for (int j = 0; j < n; j++) {
				if (holePositions[current][0] < holePositions[j][0]
						&& holePositions[current][1] == holePositions[j][1]) {
					if (holePositions[j][0] - holePositions[current][0]
							< nearstDist) {
						nearstDist = holePositions[j][0]
								- holePositions[current][0];
						nearestNeighbor = j;
					}
				}
			}

			if (nearestNeighbor == -1) {
				break;
			} else {
				current = pairings[nearestNeighbor];
				if (current == i) {
					loops++;
					return;
				}
			}
		}
	}
}

void discoverPairings(int level) {
	if (level == n) {
		for (int i = 0; i < n; i++) {
			cout << pairings[i] + 1 << " ";
		}

		cout << endl;
		testLoops();
		return;
	}

	int h1 = -1;
	for (int i = 0; i < n; i++) {
		if (pairings[i] == -1) {
			if (h1 == -1) {
				h1 = i;
			} else {
				pairings[h1] = i;
				pairings[i] = h1;
				discoverPairings(level + 2);
				pairings[h1] = -1;
				pairings[i] = -1;
			}
		}
	}
}

int _main() {

	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");

	fin >> n;
	holePositions = new int*[n];

	for (int i = 0; i < n; i++) {
		holePositions[i] = new int[2];
		fin >> holePositions[i][0] >> holePositions[i][1];
	}

	pairings = new int[n];
	memset(pairings, -1, sizeof(int) * n);

	discoverPairings(0);

	fout << loops << endl;

	return 0;
}
