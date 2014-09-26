/*
 ID: kareem_2
 PROG: hamming
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int calculateDistance(int x, int y) {
	int xOr = x ^ y;
	int distance = 0;
	while (xOr != 0) {
		xOr = (xOr ^ (xOr & -xOr));
		distance++;
	}
	return distance;
}

int _main() {

	ifstream fin("hamming.in");
	ofstream fout("hamming.out");

	int n, b, d;
	fin >> n >> b >> d;
	int pow2 = 1 << b;
	bool* excluded = new bool[pow2];

	for (int i = 0; i < pow2; i++) {
		excluded[i] = false;
	}

	int numDiscovered = 1;
	int lastDiscovered = 0;
	fout << lastDiscovered;
	while (numDiscovered < n) {
		if ((numDiscovered % 10) == 0) {
			fout << endl;
		} else {
			fout << " ";
		}
		bool found = false;
		int nextDiscovered;
		for (int i = lastDiscovered + 1; i < pow2; i++) {
			if (excluded[i]) {
				continue;
			}

			if (calculateDistance(lastDiscovered, i) < d) {
				excluded[i] = true;
				continue;
			}

			if (!found) {
				nextDiscovered = i;
				fout << nextDiscovered;
				numDiscovered++;
				found = true;
			}

		}
		lastDiscovered = nextDiscovered;
	}

	fout << endl;

	return 0;
}
