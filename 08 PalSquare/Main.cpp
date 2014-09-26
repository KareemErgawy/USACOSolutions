/*
 ID: kareem_2
 PROG: palsquare
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string.h>
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

	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int base;

	fin >> base;

	for (int i = 1; i <= 300; i++) {
		int square = i * i;
		string iconverted = convert(i, base);
		string converted = convert(square, base);
		string reverse = "";
		string ireverse = "";

		for (int j = 0; j < iconverted.length(); j++) {
			ireverse += iconverted[iconverted.length() - 1 - j];
		}

		for (int j = 0; j < converted.length(); j++) {
			reverse += converted[converted.length() - 1 - j];
		}

		if (converted.compare(reverse) == 0) {
			fout << ireverse << " " << converted << endl;
		}
	}

	return 0;
}
