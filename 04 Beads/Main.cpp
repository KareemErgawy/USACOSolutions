/*
 ID: kareem_2
 PROG: beads
 LANG: C++
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int calcSequenceLength(string necklace, int start, int direction, int max = -1) {
	int colorStatus = 0;
	int length = 0;
	int currentIndex = start;

	while (true) {

		if((max != -1) && (max == currentIndex)){
			return length;
		}

		if (necklace[currentIndex] == 'w') {
			length++;
		} else {
			if (colorStatus == 0) {
				colorStatus = (necklace[currentIndex] == 'b') ? 'b' : 'r';
				length++;
			} else {
				if (necklace[currentIndex] == colorStatus) {
					length++;
				} else {
					break;
				}
			}
		}

		currentIndex += direction;

		if (currentIndex < 0) {
			currentIndex = necklace.size() - 1;
		} else if (currentIndex >= necklace.size()) {
			currentIndex = 0;
		}

		if (currentIndex == start) {
			break;
		}
	}

	return length;
}

int _main() {
	ofstream fout("beads.out");
	ifstream fin("beads.in");

	int numBeads;
	string necklace;

	fin >> numBeads;
	fin >> necklace;
	int maxTotal = 0;

	for (int i = 0; i < necklace.size(); i++) {
		int leftSeq = calcSequenceLength(necklace, i, -1);
		int max = i + 1 - leftSeq;
		if (max < 0) {
			max = necklace.size() + max;
		}
		int rightSeq = calcSequenceLength(necklace, (i + 1) % necklace.size(),
				1, max);

		if (maxTotal < (leftSeq + rightSeq)) {
			maxTotal = leftSeq + rightSeq;
		}
	}

	fout << maxTotal << endl;
	return 0;
}
