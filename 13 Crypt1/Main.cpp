/*
 ID: kareem_2
 PROG: crypt1
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

bool Test(int pp1, bool included[10]) {
	while (pp1 > 0) {
		int d = pp1 % 10;
		if (!included[d]) {
			return false;
		}
		pp1 = pp1 / 10;
	}

	return true;
}

int _main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int numDigits;
	fin >> numDigits;
	int* digits = new int[numDigits];
	bool included[10];

	for (int i = 0; i < 10; i++) {
		included[i] = false;
	}

	for (int i = 0; i < numDigits; i++) {
		fin >> digits[i];
		included[digits[i]] = true;
	}
	int numSolutions = 0;
	for (int d11 = 1; d11 < 10; d11++) {
		if (!included[d11]) {
			continue;
		}
		for (int d12 = 1; d12 < 10; d12++) {
			if (!included[d12]) {
				continue;
			}
			for (int d13 = 1; d13 < 10; d13++) {
				if (!included[d13]) {
					continue;
				}
				int num1 = d11 + (d12 * 10) + (d13 * 100);
				for (int d21 = 1; d21 < 10; d21++) {
					if (!included[d21]) {
						continue;
					}
					for (int d22 = 1; d22 < 10; d22++) {
						if (!included[d22]) {
							continue;
						}
						int pp1 = num1 * d21;
						if (pp1 > 999 || !Test(pp1, included)) {
							continue;
						}
						int pp2 = num1 * d22;
						if (pp2 > 999 || !Test(pp2, included)) {
							continue;
						}
						int num2 = d21 + (d22 * 10);
						int p = num1 * num2;
						if (p > 9999 || !Test(p, included)) {
							continue;
						}

						//						fout << d11 << d12 << d13 << endl;
						//						fout << d21 << d22 << endl;
						//						fout << pp1 << endl;
						//						fout << pp2 << endl;
						//						fout << p << endl;
						numSolutions++;
					}
				}
			}
		}
	}

	fout << numSolutions << endl;

	return 0;
}
