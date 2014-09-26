/*
 ID: kareem_2
 PROG: numtri
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

int _main() {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	int numLines;
	unsigned int** sums;

	fin >> numLines;
	//	nums = new unsigned int*[numLines];
	sums = new unsigned int*[numLines];
	unsigned int maxSum = 0;
	unsigned int current;

	for (int i = 0; i < numLines; i++) {
		//		nums[i] = new unsigned int[i + 3];
		sums[i] = new unsigned int[i + 3];
		//		nums[i][0] = nums[i][i + 2] = 0;
		sums[i][0] = sums[i][i + 2] = 0;

		for (int j = 1; j <= i + 1; j++) {
			fin >> current;

			if (i == 0) {
				sums[i][j] = current;
			} else {
				sums[i][j] = max(sums[i - 1][j - 1], sums[i - 1][j]) + current;
			}

			maxSum = max(sums[i][j], maxSum);
		}

		if (i > 0) {
			delete[] sums[i - 1];
		}
	}

	fout << maxSum << endl;

	return 0;
}
