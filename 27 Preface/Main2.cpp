/*
 ID: kareem_2
 PROG: preface
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

string encoding[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII",
		"IX" };

string romanDigit(int digit, string map) {

	string encodingMap = encoding[digit % 10];
	replace(encodingMap.begin(), encodingMap.end(), 'X', map.at(2));
	replace(encodingMap.begin(), encodingMap.end(), 'V', map.at(1));
	replace(encodingMap.begin(), encodingMap.end(), 'I', map.at(0));

	return encodingMap;
}

string romanNumber(int n) {
	string number = "";
	number += romanDigit(n / 1000, "M  ");
	number += romanDigit(n / 100, "CDM");
	number += romanDigit(n / 10, "XLC");
	number += romanDigit(n, "IVX");

	return number;
}

int __main() {

	ifstream fin("preface.in");
	ofstream fout("preface.out");

	int n;
	fin >> n;
	string romanN;
	string index = "IVXLCDM";
	int freq[7];
	memset(freq, 0, 7 * sizeof(int));

	for (int i = 1; i <= n; i++) {
		romanN = romanNumber(i);
		cout << i << " " << romanN << endl;
		for (int j = 0; j < romanN.length(); j++) {
			freq[index.find(romanN[j])]++;
		}
	}

	int highest;

	for (int i = 6; i >= 0; i--) {
		if (freq[i] != 0) {
			highest = i;
			break;
		}
	}

	for (int i = 0; i <= highest; i++) {
		fout << index[i] << " " << freq[i] << endl;
	}

	return 0;
}
