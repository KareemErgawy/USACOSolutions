/*
 ID: kareem_2
 PROG: concom
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("concom.in");
	ofstream fout("concom.out");
	const int NUM_COMS = 101;
	int conComs[NUM_COMS][NUM_COMS];
	bool newCons[NUM_COMS][NUM_COMS];

	for (int i = 1; i < NUM_COMS; i++) {
		for (int j = 1; j < NUM_COMS; j++) {
			conComs[i][j] = 0;
			newCons[i][j] = false;
		}
	}

	int numTriples;
	fin >> numTriples;
	int numNewCons = 0;

	for (int t = 0; t < numTriples; t++) {
		int i, j, p;
		fin >> i >> j >> p;
		conComs[i][j] = p;
		if (p > 50) {
			newCons[i][j] = true;
//			cout << "newCons " << i << " " << j << endl;
			numNewCons++;
		}
	}

	while (numNewCons > 0) {
		for (int i = 1; i < NUM_COMS; i++) {
			for (int j = 1; j < NUM_COMS; j++) {
				if (newCons[i][j]) {
					for (int k = 1; k < NUM_COMS; k++) {
						if (i != k && j != k && conComs[i][k] <= 50) {
							conComs[i][k] += conComs[j][k];
							if (conComs[i][k] > 50) {
								newCons[i][k] = true;
//								cout << "newCons " << i << " " << k << endl;
								numNewCons++;
							}
						}
					}

					newCons[i][j] = false;
					numNewCons--;
				}
			}
		}
	}

	for (int i = 1; i < NUM_COMS; i++) {
		for (int j = 1; j < NUM_COMS; j++) {
			if (i != j && conComs[i][j] > 50) {
				fout << i << " " << j << endl;
			}
		}
	}

	return 0;
}
