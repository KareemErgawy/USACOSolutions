/*
 ID: kareem_2
 PROG: barn1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

int _main() {

	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int maxBoards, numStalls, numCows;
	fin >> maxBoards >> numStalls >> numCows;
	bool* occupiedStalls = new bool[numStalls + 1];
	int firstOccupied = INT_MAX;
	int lastOccupied = INT_MIN;
	int numBoards = 0;

	for (int i = 0; i < numStalls + 1; i++) {
		occupiedStalls[i] = false;
	}

	for (int i = 0; i < numCows; i++) {
		int stall;
		fin >> stall;
		occupiedStalls[stall] = true;
		//cout << "Stall #" << stall << " Occupied" << endl;
		firstOccupied = (stall < firstOccupied) ? stall : firstOccupied;
		lastOccupied = (stall > lastOccupied) ? stall : lastOccupied;
	}

	//cout << "First occupied stall: " << firstOccupied << endl;
	//cout << "Last occupied stall: " << lastOccupied << endl;

	bool* coveredStalls = new bool[numStalls + 1];

	for (int i = 0; i < numStalls + 1; i++) {
		coveredStalls[i] = false;
	}

	int numCovered = 0;

	for (int i = firstOccupied; i <= lastOccupied; i++) {
		if (!occupiedStalls[i - 1] && occupiedStalls[i]) {
			//cout << "New board starting at: " << i << endl;
			numBoards++;
		}

		if (occupiedStalls[i]) {
			coveredStalls[i] = true;
			//cout << "Stall #" << i << " now covered" << endl;
			numCovered++;
		}
	}

	//cout << "# of boards so far " << numBoards << ", # of max boards: "
	//		<< maxBoards << endl;

	while (numBoards > maxBoards) {
		int gapSize;
		int gapStart;
		int minGap = INT_MAX;
		int minGapStart;

		for (int i = firstOccupied + 1; i <= lastOccupied; i++) {
			if (!coveredStalls[i] && coveredStalls[i - 1]) {
				//cout << "New gap starting at: " << i << endl;
				gapSize = 1;
				gapStart = i;
			}

			if (!coveredStalls[i] && !coveredStalls[i - 1]) {
				gapSize++;
			}

			if (coveredStalls[i] && !coveredStalls[i - 1]) {
				//cout << "Current gap ends at: " << i << endl;
				if (gapSize < minGap) {
					//cout << "This is the new min gap" << endl;
					minGap = gapSize;
					minGapStart = gapStart;
				}
			}
		}

		for (int i = minGapStart; i < minGapStart + minGap; i++) {
			coveredStalls[i] = true;
			numCovered++;
		}

		numBoards--;
	}

	fout << numCovered << endl;

	return 0;
}
