/*
 ID: kareem_2
 PROG: comehome
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	ifstream fin("comehome.in");
	ofstream fout("comehome.out");

	int numEdges;
	fin >> numEdges;
	int adjacency[52][52];

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			adjacency[i][j] = 1000000;
		}
	}

	for (int i = 0; i < numEdges; i++) {
		char v1, v2;
		int weight;
		fin >> v1 >> v2 >> weight;
		v1 = v1 <= 'Z' ? v1 - 'A' : v1 - 'a' + 26;
		v2 = v2 <= 'Z' ? v2 - 'A' : v2 - 'a' + 26;
		adjacency[v1][v2] = adjacency[v2][v1]
				= adjacency[v1][v2] > weight ? weight : adjacency[v1][v2];
	}

	for (int k = 0; k < 52; k++) {
		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 52; j++) {
				if (adjacency[i][k] + adjacency[k][j] < adjacency[i][j]) {
					adjacency[i][j] = adjacency[i][k] + adjacency[k][j];
				}
			}
		}
	}

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			cout << setw(10) << adjacency[i][j] << " ";
		}
		cout << endl;
	}

	char minPasture;
	int minDistance = 1000000;
	for (int i = 0; i <= 24; i++) {
		if (minDistance > adjacency[i][25]) {
			minDistance = adjacency[i][25];
			minPasture = 'A' + i;
		}
	}

	fout << minPasture << " " << minDistance << endl;

	return 0;
}
