/*
 ID: kareem_2
 PROG: crypt1
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

bool goodDigits[10];

bool isGood(int num, int digits) {

	if (num == 0) {
		return false;
	}

	while (num > 0) {
		if (!goodDigits[num % 10]) {
			return false;
		}

		num /= 10;
		digits--;
	}

	if (digits != 0) {
		return false;
	}

	return true;
}

bool isGoodCombination(int n, int m) {
	if (!isGood(n, 3) || !isGood(m, 2) || !isGood(n * m, 4)) {
		return false;
	}

	while (m > 0) {
		if (!isGood(n * (m % 10), 3)) {
			return false;
		}

		m /= 10;
	}

	return true;
}

int main() {

	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int numDigits;
	fin >> numDigits;
	int digit;

	for (int i = 0; i < 10; i++) {
		goodDigits[i] = false;
	}

	for (int i = 0; i < numDigits; i++) {
		fin >> digit;
		goodDigits[digit] = true;
	}

	int numSolutions = 0;

	for (int i = 100; i < 1000; i++) {
		for (int j = 10; j < 100; j++) {
			if(isGoodCombination(i, j)){
				numSolutions++;
			}
		}
	}

	fout << numSolutions << endl;

	return 0;
}
