/*
 ID: kareem_2
 PROG: contact
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <bitset>
using namespace std;

typedef unsigned long ulong;
ifstream fin("contact.in");
ofstream fout("contact.out");

string printInBinary(ulong num, ulong l) {
	int i = 0;
	char* strRep = new char[l];
	while (i < l) {
		strRep[i] = (num & 1) + '0';
		num = num >> 1;
		i++;
	}

	i = l - 1;
	string s = "";
	while (i >= 0) {
		s = s + strRep[i];
		i--;
	}

	return s;
}

int main() {

	ulong a, b, n;
	fin >> a >> b >> n;
	int** freq = new int*[b - a + 1];
	for (ulong i = 0; i <= b - a; i++) {
		freq[i] = new int[1 << (i + a)];
		for (int j = 0; j < (1 << (i + a)); j++) {
			freq[i][j] = 0;
		}
	}

	char c;
	list<ulong> pattern;
	ulong counter = 0;
	ulong current = 0;
	while (fin >> c) {
		current = current << 1;
		current = current | (c - '0');
		counter++;
		if (counter % 32 == 0) {
			pattern.insert(pattern.end(), current);
			current = 0;
		}
	}

	if (counter % 32 != 0) {
		pattern.insert(pattern.end(), current << (32 - (counter % 32)));
	}

	list<ulong>::iterator it = pattern.begin();
	list<ulong>::iterator it2;
	current = *it;
	ulong temp;
	for (ulong i = 0; i < counter; i++) {
		if (i != 0 && (i % 32 == 0)) {
			it++;
			current = *it;
		}

		temp = current;
		ulong j = i;
		ulong value = 0;

		for (ulong l = 1; l <= b && j < counter; l++, j++) {
			if (j != i && j != 0 && (j % 32 == 0)) {
				it2 = it;
				it2++;
				temp = *it2;
			}
			value = value << 1;
			value = value
					| ((temp & (1 << (31 - (j % 32)))) >> (31 - (j % 32)));
			if (l >= a) {
				freq[l - a][value]++;
			}
		}
	}

	string line = "";
	for (ulong k = 0; k < n; k++) {
		int max = 0;
		for (ulong i = 0; i <= b - a; i++) {
			for (int j = 0; j < (1 << (i + a)); j++) {
				if (max < freq[i][j]) {
					max = freq[i][j];
				}
			}
		}

		if (max == 0) {
			break;
		}

		fout << max << endl;
		line = "";
		int printed = 0;
		for (ulong i = 0; i <= b - a; i++) {
			for (int j = 0; j < (1 << (i + a)); j++) {
				if (freq[i][j] == max) {
					line = line + printInBinary(j, i + a);
					printed++;
					if(printed % 6 == 0) {
						line = line + "\n";
					} else {
						line = line + " ";
					}
					freq[i][j] = 0;
				}
			}
		}
		line = line.substr(0, line.size() - 1);
		fout << line << endl;
	}

	return 0;
}
