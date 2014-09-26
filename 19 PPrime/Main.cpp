/*
 ID: kareem_2
 PROG: pprime
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

typedef unsigned int uint;

bool isPalindrom(uint n) {
	uint tmp1 = n;
	uint tmp2 = 0;

	while (tmp1 > 0) {
		tmp2 = (tmp2 * 10) + (tmp1 % 10);
		tmp1 = tmp1 / 10;
	}

	return (n == tmp2);
}

bool isPrime(uint n) {

	if (n == 1) {
		return false;
	}

	if (n == 2 || n == 3) {
		return true;
	}

	if ((n % 2 == 0) || (n % 3 == 0)) {
		return false;
	}

	for (uint i = 6; i <= sqrt(n) + 1; i += 6) {
		if ((n % (i - 1) == 0) || (n % (i + 1) == 0)) {
			return false;
		}
	}

	return true;
}
ifstream fin("pprime.in");
ofstream fout("pprime.out");
uint a, b;

void generatePalindroms(int length, int currentDigitIndex, int* currentDigits) {
	int tmp = ceil((float) length / 2.0);
	if (currentDigitIndex >= tmp) {
		uint n = 0;
		for (int i = 0; i < tmp; i++) {
			n = (n * 10) + currentDigits[i];
		}
		for (int i = length - 1; i >= tmp; i--) {
			n = (n * 10) + currentDigits[i - tmp];
		}

		if (n >= a && n <= b && isPrime(n)) {
			fout << n << endl;
		}
		return;
	}

	int i = (currentDigitIndex == 0) ? 1 : 0;
	for (; i < 10; i++) {
		currentDigits[currentDigitIndex] = i;
		generatePalindroms(length, currentDigitIndex + 1, currentDigits);
	}
}

int _main() {

	fin >> a >> b;

	int currentDigits[8];
	for (int i = 1; i < 9; i++) {
		generatePalindroms(i, 0, currentDigits);
	}

	//	for (uint i = a; i <= b; i++) {
	//		if (isPalindrom(i) && isPrime(i)) {
	//			fout << i << endl;
	//		}
	//	}

	return 0;
}
