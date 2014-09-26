/*
 ID: kareem_2
 PROG: barn1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int __main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int maxBoards, numStalls, numCows;
	fin >> maxBoards >> numStalls >> numCows;
	bool* occupied = (bool*) calloc(numStalls, sizeof(bool));
	int cowStall;

	for (int i = 0; i < numCows; i++) {
		fin >> cowStall;
		occupied[cowStall - 1] = true;
	}

	int low, high;
	int i, j;
	for (i = 0; i < numStalls && !occupied[i]; i++)
		;
	low = i;
	for (i = numStalls - 1; i >= 0 && !occupied[i]; i--)
		;
	high = i;

	i = low;
	int* emptyRuns = (int*) calloc(numStalls / 2, sizeof(int));
	int currentRun = 0;

	while (i < high) {
		while (occupied[i] && i < high) {
			i++;
		}

		j = i;
		while (!occupied[j] && j < high) {
			j++;
		}

		emptyRuns[currentRun++] = j - i;
		i = j;
	}

	sort(emptyRuns, emptyRuns + currentRun);
	int toBeUncovered = 0;

	for(i=currentRun - 1,j=0 ; i>=0 && j<maxBoards-1 ; i--,j++){
		toBeUncovered += emptyRuns[i];
	}

	fout << high - low + 1 - toBeUncovered << endl;

	return 0;
}
