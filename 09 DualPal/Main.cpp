/*
 ID: kareem_2
 PROG: dualpal
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

string convert(int square, int base) {
	string converted = "";
	while (square > 0) {
		int modResult = square % base;
		if (modResult < 10) {
			converted += ('0' + modResult);
		} else {
			converted += ('A' + (modResult - 10));
		}
		square = square / base;
	}

	return converted;
}

int main() {

	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int n, s;
	fin >> n >> s;
	int numFound = 0;
	for (int i = s + 1;; i++) {
		int numPals = 0;

		for (int j = 2; j <= 10; j++) {
			string converted = convert(i, j);
			string reverse = "";

			for (int j = 0; j < converted.length(); j++) {
				reverse += converted[converted.length() - 1 - j];
			}

			if (converted.compare(reverse) == 0) {
				numPals++;
				if (numPals >= 2) {
					break;
				}
			}
		}

		if (numPals >= 2) {
			fout << i << endl;
			numFound++;

			if (numFound == n) {
				break;
			}
		}
	}

	return 0;
}
