/*
 ID: kareem_2
 PROG: namenum
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream dictin("dict.txt");
	char map[256];
	map['A'] = map['B'] = map['C'] = '2';
	map['D'] = map['E'] = map['F'] = '3';
	map['G'] = map['H'] = map['I'] = '4';
	map['J'] = map['K'] = map['L'] = '5';
	map['M'] = map['N'] = map['O'] = '6';
	map['P'] = map['R'] = map['S'] = '7';
	map['T'] = map['U'] = map['U'] = '8';
	map['W'] = map['X'] = map['Y'] = '9';
	string name;
	string num;
	fin >> num;
	bool foundName = false;

	while (!dictin.eof()) {
		dictin >> name;
		if (name.length() == num.length()) {
			int i = 0;
			for (; i < name.length(); i++) {
				if (map[name[i]] != num[i]) {
					break;
				}
			}

			if (i == name.length()) {
				fout << name << endl;
				foundName = true;
			}
		}
	}

	if (!foundName) {
		fout << "NONE" << endl;
	}

	return 0;
}
