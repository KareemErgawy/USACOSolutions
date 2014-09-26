/*
 ID: kareem_2
 PROG: friday
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

bool isLeap(int y) {
	return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

int monthLenght[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int getMonthLength(int m, int y) {
	if (m == 1) {
		return monthLenght[m] + isLeap(y);
	}

	return monthLenght[m];
}

int main() {
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int n;
	fin >> n;

	int freq[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int dayOfWeek = 0;

	for (int y = 1900; y < 1900 + n; y++) {
		for (int m = 0; m < 12; m++) {
			freq[dayOfWeek]++;
			dayOfWeek = (dayOfWeek + getMonthLength(m, y)) % 7;
		}
	}

	for (int i = 0; i < 7; i++) {
		fout << freq[i];
		if (i == 6) {
			fout << endl;
		} else {
			fout << " ";
		}
	}

	return 0;
}
