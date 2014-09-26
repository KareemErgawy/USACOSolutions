/*
 ID: kareem_2
 PROG: milk2
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Milking {
	int start;
	int end;
};

int milkingCompare(Milking m1, Milking m2) {
	return m1.start < m2.start;
}

int __main() {

	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int numMilking;
	fin >> numMilking;
	Milking* milkings = new Milking[numMilking];

	for (int i = 0; i < numMilking; i++) {
		fin >> milkings[i].start >> milkings[i].end;
	}

	sort(milkings, milkings + numMilking, milkingCompare);

	Milking current = milkings[0];
	int maxNoMilk = 0;
	int maxMilk = 0;

	for (int i = 1; i < numMilking; i++) {
		if (milkings[i].start > current.end) {
			int tNoMilk = milkings[i].start - current.end;
			if (tNoMilk > maxNoMilk) {
				maxNoMilk = tNoMilk;
			}

			int tMilk = current.end - current.start;
			if (tMilk > maxMilk) {
				maxMilk = tMilk;
			}

			current = milkings[i];
		} else {
			if (milkings[i].end > current.end) {
				current.end = milkings[i].end;
			}
		}
	}

	int tMilk = current.end - current.start;

	if (tMilk > maxMilk) {
		maxMilk = tMilk;
	}

	fout << maxMilk << " " << maxNoMilk << endl;

	return 0;
}
