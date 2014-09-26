/*
 ID: kareem_2
 PROG: beads
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int ___main() {
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int len;
	string necklace;
	fin >> len >> necklace;
	necklace = necklace + necklace;
	int** left = new int*[len * 2 + 1];
	int** right = new int*[len * 2 + 1];

	for (int i = 0; i <= len * 2; i++) {
		left[i] = new int[2];
		right[i] = new int[2];
	}

	left[0][0] = left[0][1] = 0;

	for (int i = 1; i <= len * 2; i++) {
		if (necklace[i - 1] == 'r') {
			left[i][0] = left[i - 1][0] + 1;
			left[i][1] = 0;
		} else if (necklace[i - 1] == 'b') {
			left[i][1] = left[i - 1][1] + 1;
			left[i][0] = 0;
		} else {
			left[i][0] = left[i - 1][0] + 1;
			left[i][1] = left[i - 1][1] + 1;
		}
	}

	right[len * 2][0] = right[len * 2][1] = 0;

	for (int i = len * 2 - 1; i >= 0; i--) {
		if (necklace[i] == 'r') {
			right[i][0] = right[i + 1][0] + 1;
			right[i][1] = 0;
		} else if (necklace[i] == 'b') {
			right[i][1] = right[i + 1][1] + 1;
			right[i][0] = 0;
		} else {
			right[i][0] = right[i + 1][0] + 1;
			right[i][1] = right[i + 1][1] + 1;
		}
	}

	int maximum = 0;

	for (int i = 0; i <= len * 2; i++) {
//		cout << i << " " << max(left[i][0], left[i][1]) << " " << max(right[i][0], right[i][1]) << endl;
		maximum = max(maximum,
				max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
	}

	maximum = min(maximum, len);
	fout << maximum << endl;

	return 0;
}
