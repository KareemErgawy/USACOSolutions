/*
 ID: kareem_2
 PROG: checker
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned long ulong;
const ulong ONE = 1;

int mod(int m, int n) {
	if (m >= 0) {
		return m % n;
	} else {
		while (m < 0) {
			m += n;
		}
		return m % n;
	}
}

ifstream fin("checker.in");
ofstream fout("checker.out");
int n;
int* sol;
int foundSols = 0;

void generateBoards(int currentRow, ulong occupiedColumns,
		ulong occupiedRightDiags, ulong occupiedLeftDiags) {

	if (currentRow == n) {
		if (foundSols < 3) {
			for (int i = 0; i < n; i++) {
				if (i > 0) {
					fout << " ";
				}
				fout << sol[i] + 1;
			}
			fout << endl;
		}
		foundSols++;
	}

	for (int i = 0; i < n; i++) {
		ulong col = ONE << i;
		if (occupiedColumns & col) {
			continue;
		}
		ulong rightDiag = ONE << mod(i - currentRow, n * 2 - 1);
		if (occupiedRightDiags & rightDiag) {
			continue;
		}
		ulong leftDiag = ONE << (i + currentRow);
		if (occupiedLeftDiags & leftDiag) {
			continue;
		}

		sol[currentRow] = i;
		generateBoards(currentRow + 1, occupiedColumns | col,
				occupiedRightDiags | rightDiag, occupiedLeftDiags | leftDiag);
	}
}

int main() {
	fin >> n;
	sol = new int[n];
	generateBoards(0, 0, 0, 0);
	fout << foundSols << endl;
	return 0;
}
