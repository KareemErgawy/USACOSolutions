/*
 ID: kareem_2
 PROG: ariprog
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	bool* available;
	int* bisquares;
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int progLength, maxBisquareComponent;
	fin >> progLength >> maxBisquareComponent;
	int maxBisquare = maxBisquareComponent * maxBisquareComponent * 2 + 1;
	available = (bool*) (calloc(maxBisquare, sizeof(bool)));
	bisquares = (int*) (calloc(maxBisquare, sizeof(int)));
	int bisquare;
	int bisquareCount = 0;

	for (int i = 0; i <= maxBisquareComponent; i++) {
		for (int j = 0; j <= maxBisquareComponent; j++) {
			bisquare = (i * i) + (j * j);
			if (!available[bisquare]) {
				available[bisquare] = true;
				bisquares[bisquareCount++] = bisquare;
			}
		}
	}

	sort(bisquares, bisquares + bisquareCount);
	bool foundAny = false;

	for (int i = 1; i <= maxBisquare / (progLength - 1); i++) {
		for (int j = 0; bisquares[j] + (progLength - 1) * i <= maxBisquare; j++) {
			int k;
			for (k = (progLength - 1); k >= 1; k--) {
				if (!available[bisquares[j] + k * i]) {
					break;
				}
			}
			if (k == 0) {
				foundAny = true;
				fout << bisquares[j] << " " << i << endl;
			}
		}
	}

	if (!foundAny) {
		fout << "NONE" << endl;
	}

	return 0;
}
