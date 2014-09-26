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

int main() {

	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int len;
	string necklace;
	fin >> len >> necklace;
	necklace = necklace + necklace;
	int max = 0;
	int index;

	for (int i = 0; i < len; i++) {
		int state;
		char color = necklace[i];

		if (color == 'w') {
			state = 0;
		} else {
			state = 1;
		}

		int j = i;
		int currentLen = 0;
		while (state <= 2) {
			while (j < (i + len)
					&& (necklace[j] == 'w' || necklace[j] == color)) {
				currentLen++;
				j++;
			}
			color = necklace[j];
			state++;
		}

		if (currentLen > max) {
			max = currentLen;
			index = i;
		}
	}

	cout << index << endl;
	fout << max << endl;

	return 0;
}
