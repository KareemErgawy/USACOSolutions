/*
 ID: kareem_2
 PROG: cowtour
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <cfloat>
using namespace std;

int numPastures;
int** locations;
double** adjacency;
double** distances;
int* components;

int main() {

	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");

	fin >> numPastures;
	components = new int[numPastures];
	locations = new int*[numPastures];
	adjacency = new double*[numPastures];
	distances = new double*[numPastures];

	for (int i = 0; i < numPastures; i++) {
		components[i] = -1;
		locations[i] = new int[2];
		fin >> locations[i][0] >> locations[i][1];
	}

	for (int i = 0; i < numPastures; i++) {
		adjacency[i] = new double[numPastures];
		distances[i] = new double[numPastures];
		string line;
		fin >> line;
		cout << line << endl;
		for (int j = 0; j < numPastures; j++) {
			if (line[j] == '1') {
				adjacency[i][j] = sqrt(
						pow(locations[i][0] - locations[j][0], 2) + pow(
								locations[i][1] - locations[j][1], 2));
				distances[i][j] = adjacency[i][j];
			} else {
				adjacency[i][j] = 0;
				distances[i][j] = (i == j) ? 0 : FLT_MAX;
			}
		}
	}

	double globalDiameter = FLT_MAX;
	for (int k = 0; k < numPastures; k++) {
		for (int i = 0; i < numPastures; i++) {
			for (int j = 0; j < numPastures; j++) {
				if (distances[i][k] + distances[k][j] < distances[i][j]) {
					distances[i][j] = distances[i][k] + distances[k][j];
				}
			}
		}
	}
	for (int i = 0; i < numPastures; i++) {
		for (int j = 0; j < numPastures; j++) {
			cout << fixed << setw(14) << setprecision(6) << ((distances[i][j]
					== FLT_MAX) ? -1 : distances[i][j]) << " ";
		}

		cout << endl;
	}

	for (int i = 0; i < numPastures; i++) {
		for (int j = 0; j < numPastures; j++) {
			if (distances[i][j] == FLT_MAX) {
				double diameter = 0;
				double newDistance = sqrt(
						pow(locations[i][0] - locations[j][0], 2) + pow(
								locations[i][1] - locations[j][1], 2));
				for (int k = 0; k < numPastures; k++) {
					if (distances[i][k] != FLT_MAX) {
						for (int l = 0; l < numPastures; l++) {
							if (distances[j][l] != FLT_MAX) {
								if (diameter < distances[i][k]
										+ distances[j][l] + newDistance) {
									diameter = distances[i][k]
											+ distances[j][l] + newDistance;
								}
							}
						}
					}
				}

				if (globalDiameter > diameter) {
					globalDiameter = diameter;
				}
			}
		}
	}

	for (int i = 0; i < numPastures; i++) {
		for (int j = 0; j < numPastures; j++) {
			if(distances[i][j] < FLT_MAX && distances[i][j] > globalDiameter) {
				globalDiameter = distances[i][j];
			}
		}
	}

	fout << fixed << setprecision(6) << globalDiameter << endl;

	//	for (int i = 0; i < numPastures; i++) {
	//		for (int j = 0; j < numPastures; j++) {
	//			cout << fixed << setw(11) << setprecision(6) << adjacency[i][j]
	//					<< " ";
	//		}
	//		cout << endl;
	//	}


	int numComponents = 0;
	bool* explore = new bool[numPastures];

	for (int i = 0; i < numPastures; i++) {
		explore[i] = false;
	}
	for (int i = 0; i < numPastures; i++) {
		bool shouldExplore = false;

		if (components[i] == -1) {
			numComponents++;
			components[i] = numComponents;
			shouldExplore = true;
		}

		if (explore[i]) {
			explore[i] = false;
			shouldExplore = true;
		}

		if (shouldExplore) {
			for (int j = i + 1; j < numPastures; j++) {
				if (adjacency[i][j] > 0 && components[j] == -1) {
					components[j] = numComponents;
					explore[j] = true;
				}
			}
		}
	}

	for (int i = 0; i < numPastures; i++) {
		cout << components[i] << endl;
	}

	return 0;
}
