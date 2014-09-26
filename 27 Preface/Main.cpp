/*
 ID: kareem_2
 PROG: preface
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int standardSetValues[7] = { 1, 5, 10, 50, 100, 500, 1000 };
string standardSetSymbols[7] = { "A", "B", "C", "D", "E", "F", "G" };
string originalStandardSetSymbols[7] = { "I", "V", "X", "L", "C", "D", "M" };
int standardSetFreq[7] = { 0, 0, 0, 0, 0, 0, 0 };
string* numbers;

int getPreviousStandardValueIndex(int x) {
	for (int i = 6; i >= 0; i--) {
		if (standardSetValues[i] <= x) {
			return i;
		}
	}

	return -1;
}

string generateNumber(int n) {
	if (numbers[n] != "") {
		//cout << numbers[n] << endl;
		return numbers[n];
	}
	int prevSV = getPreviousStandardValueIndex(n);

	if (standardSetValues[prevSV] == n) {
		numbers[n] = standardSetSymbols[prevSV];
		return numbers[n];
	}

	if (prevSV < 6) {
		if ((((prevSV + 1) % 2) == 1) && (n == (standardSetValues[prevSV + 1]
				- standardSetValues[prevSV]))) {
			numbers[n] = standardSetSymbols[prevSV] + standardSetSymbols[prevSV
					+ 1];
			//cout << numbers[n] << endl;
			return numbers[n];
		}
		if ((((prevSV + 1) % 2) == 0) && (n == (standardSetValues[prevSV + 1]
				- standardSetValues[prevSV - 1]))) {
			numbers[n] = standardSetSymbols[prevSV - 1]
					+ standardSetSymbols[prevSV + 1];
			//cout << numbers[n] << endl;
			return numbers[n];
		}
	}

	int diff = n - standardSetValues[prevSV];
	if (diff == standardSetValues[getPreviousStandardValueIndex(diff)]) {
		numbers[n] = standardSetSymbols[prevSV]
				+ standardSetSymbols[getPreviousStandardValueIndex(diff)];
		return numbers[n];
	}

	if ((n % standardSetValues[prevSV]) == 0) {
		for (int i = 0; i < (n / standardSetValues[prevSV]); i++) {
			numbers[n] = numbers[n] + standardSetSymbols[prevSV];
		}

		//cout << numbers[n] << endl;
		return numbers[n];
	}

	//	numbers[n] = standardSetSymbols[prevSV] + generateNumber(
	//			n - standardSetValues[prevSV]);
	//	int base = 1;
	//	int tmp = n;
	//	while (tmp > 0) {
	//		int d = (tmp % 10) * base;
	//		tmp = tmp / 10;
	//		base *= 10;
	//		numbers[n] = numbers[d] + numbers[n];
	//	}

	int highPart = (n / standardSetValues[prevSV]) * standardSetValues[prevSV];
	int lowPart = n - highPart;
	if ((lowPart / standardSetValues[prevSV - 1]) < 4) {
		numbers[n] = generateNumber(highPart) + generateNumber(n - highPart);
	} else {
		int m = n;
		for (int i = 6; i >= 0; i -= 2) {
			int temp = m / standardSetValues[i];
			if (temp > 0) {
				m = m - (temp * standardSetValues[i]);
				numbers[n] = numbers[n] + generateNumber(
						temp * standardSetValues[i]);
			}
		}
	}

	//cout << numbers[n] << endl;
	return numbers[n];
}

int _main() {
	ifstream fin("preface.in");
	ofstream fout("preface.out");

	int numPages;
	fin >> numPages;
	numbers = new string[numPages + 1];
	for (int i = 1; i <= numPages; i++) {
		//		if (i == 99) {
		//			cout << "dummy";
		//		}
		generateNumber(i);
		//		cout << numbers[i] << endl;
	}

	for (int i = 1; i <= numPages; i++) {
		for (int j = 0; j < numbers[i].length(); j++) {
			standardSetFreq[numbers[i][j] - 'A']++;
		}
	}

	for (int i = 0; i < 7; i++) {
		if (standardSetFreq[i] > 0)
			fout << originalStandardSetSymbols[i] << " " << standardSetFreq[i]
					<< endl;
	}

	return 0;
}
