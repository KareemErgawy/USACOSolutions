/*
 ID: kareem_2
 PROG: milk3
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

int __main() {
	int a, b, c;
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> a >> b >> c;
	bool discovered[21][21][21];
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				discovered[i][j][k] = false;
			}
		}
	}
	discovered[0][0][c] = true;
	bool solutions[21];
	for (int i = 0; i < 21; i++) {
		solutions[i] = false;
	}

	for (bool foundNew = true; foundNew;) {
		foundNew = false;

		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b; j++) {
				for (int k = 0; k <= c; k++) {
					if (discovered[i][j][k]) {
						if (i == 0) {
							solutions[k] = true;
						}

						if (i > 0) {
							if (b - j >= i) {
								if (!discovered[0][j + i][k]) {
									discovered[0][j + i][k] = true;
									foundNew = true;
								}
							} else {
								if (!discovered[i - (b - j)][b][k]) {
									discovered[i - (b - j)][b][k] = true;
									foundNew = true;
								}
							}

							if (c - k >= i) {
								if (!discovered[0][j][k + i]) {
									discovered[0][j][k + i] = true;
									foundNew = true;
								}
							} else {
								if (!discovered[i - (c - k)][j][c]) {
									discovered[i - (c - k)][j][c] = true;
									foundNew = true;
								}
							}
						}

						if (j > 0) {
							if (a - i >= j) {
								if (!discovered[i + j][0][k]) {
									discovered[i + j][0][k] = true;
									foundNew = true;
								}
							} else {
								if (!discovered[a][j - (a - i)][k]) {
									discovered[a][j - (a - i)][k] = true;
									foundNew = true;
								}
							}

							if (c - k >= j) {
								if (!discovered[i][0][k + j]) {
									discovered[i][0][k + j] = true;
									foundNew = true;
								}
							} else {
								if (!discovered[i][j - (c - k)][c]) {
									discovered[i][j - (c - k)][c] = true;
									foundNew = true;
								}
							}
						}

						if (k > 0) {
							if (a - i >= k) {
								if (!discovered[i + k][j][0]) {
									discovered[i + k][j][0] = true;
									foundNew = true;
								}
							} else {
								if (!discovered[a][j][k - (a - i)]) {
									discovered[a][j][k - (a - i)] = true;
									foundNew = true;
								}
							}

							if (b - j >= k) {
								if (!discovered[i][j + k][0]) {
									discovered[i][j + k][0] = true;
									foundNew = true;
								}
							} else {
								if (!discovered[i][b][k - (b - j)]) {
									discovered[i][b][k - (b - j)] = true;
									foundNew = true;
								}
							}
						}
					}
				}
			}
		}
	}

	bool first = true;

	for (int i = 0; i < 21; i++) {
		if (solutions[i]) {
			if (!first) {
				fout << " ";
			}
			first = false;
			fout << i;
		}
	}
	fout << endl;

	return 0;
}
