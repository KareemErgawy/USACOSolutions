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

bool* available;
bool* availableDistances;
int* bisquares2;

int __main() {
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int progLength, maxBisquareComponent;
	fin >> progLength >> maxBisquareComponent;
	int maxBisquare = maxBisquareComponent * maxBisquareComponent * 2 + 1;
	available = (bool*) (calloc(maxBisquare, sizeof(bool)));
	availableDistances = (bool*) (calloc(maxBisquare, sizeof(bool)));
	bisquares2 = (int*) (calloc(maxBisquare, sizeof(int)));
	int bisquare;
	int bisquareCount = 0;

	for (int i = 0; i <= maxBisquareComponent; i++) {
		for (int j = 0; j <= maxBisquareComponent; j++) {
			bisquare = (i * i) + (j * j);
			if (!available[bisquare]) {
				available[bisquare] = true;
				bisquares2[bisquareCount++] = bisquare;
			}
		}
	}

	sort(bisquares2, bisquares2 + bisquareCount);

	for (int i = 0; i < bisquareCount; i++) {
		bisquare = bisquares2[i];
		for (int j = i + 1; (j < bisquareCount) && ((bisquare + (bisquares2[j]
				- bisquare) * (progLength - 1)) < maxBisquare); j++) {
			if (available[bisquare + (bisquares2[j] - bisquare) * (progLength
					- 1)] && available[bisquare + (bisquares2[j] - bisquare)
					* (progLength - 2)]) {
				availableDistances[bisquares2[j] - bisquare] = true;
			}
		}
	}

	bool foundAny = false;
	int step = 1;

	for (int i = 1; i <= maxBisquare / (progLength - 1); i += step) {
		if (availableDistances[i]) {
			for (int j = 0; (j < bisquareCount) && ((bisquares2[j] + i
					* (progLength - 1)) < maxBisquare); j++) {
				int k;
				for (k = 1; k < progLength; k++) {
					if (!available[bisquares2[j] + k * i]) {
						break;
					}
				}

				if (k == progLength) {
					fout << bisquares2[j] << " " << i << endl;
					if (!foundAny) {
						step = i;
					}
					foundAny = true;
				}
			}
		}
	}

	if (!foundAny) {
		fout << "NONE" << endl;
	}

	return 0;
}
