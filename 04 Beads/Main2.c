/*
 ID: kareem_2
 PROG: beads
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int len;
string necklace;

int mod(int n, int len) {
	if (n < 0) {
		n += len;
	}

	return n % len;
}

int countBeads(int p, int d) {

	int currentPos = 0;
	if (d > 0) {
		currentPos = p;
	} else {
		currentPos = mod(p - 1, len);
	}

	char currentColor = 'w';
	int n = 0;

	for (int i = 0; i < len; i++, currentPos = mod(currentPos + d, len)) {
		if (currentColor == 'w' && necklace[currentPos] != 'w') {
			currentColor = necklace[currentPos];
		}

		if (currentColor != 'w' && necklace[currentPos] != 'w'
				&& necklace[currentPos] != currentColor) {
			break;
		}
		n++;
	}

	return n;
}

int __main() {
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	fin >> len >> necklace;
	int max = 0;

	for (int i = 0; i < len; i++) {
		int temp = countBeads(i, 1) + countBeads(i, -1);
		if (temp > max) {
			max = temp;
		}
	}

	if (max > len) {
		max = len;
	}

	fout << max << endl;

	return 0;
}
