/*
 ID: kareem_2
 PROG: numtri
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	int numRows;
	fin >> numRows;
	int* best = (int*)calloc(numRows, sizeof(int));
	int* oldBest = (int*)calloc(numRows, sizeof(int));
	int current;

	for (int i = 1; i <= numRows; i++) {
		memmove(oldBest, best, sizeof(int) * numRows);

		for (int j = 0; j < i; j++) {
			fin >> current;

			if (j == 0) {
				best[j] = oldBest[j] + current;
			} else {
				best[j] = max(oldBest[j - 1], oldBest[j]) + current;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < numRows; i++) {
		if (max < best[i]) {
			max = best[i];
		}
	}

	fout << max << endl;

	return 0;
}
