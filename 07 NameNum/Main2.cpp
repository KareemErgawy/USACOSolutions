/*
 ID: kareem_2
 PROG: namenum
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream fout2("namenum.out");
string num;
vector<string> dict2;
string currentName;
bool foundNames = false;

void search(int charLoc, int low, int high) {
	if (charLoc == num.length()) {
		for (int i = low; i < high; i++) {
			if (currentName.compare(dict2[i]) == 0) {
				fout2 << currentName << endl;
				foundNames = true;
			}
		}

		return;
	}

	if (charLoc > 0) {
		for (int i = low; i <= high; i++) {
			if (currentName[charLoc - 1] == dict2[i][charLoc - 1]) {
				low = i;
				while (i < high && currentName[charLoc - 1]
						== dict2[i][charLoc - 1]) {
					i++;
				}
				high = i;
				break;
			}
			if (i == high) {
				return;
			}
		}
	}

	if (low > high) {
		return;
	}

	switch (num[charLoc]) {
	case '2':
		currentName[charLoc] = 'A';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'B';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'C';
		search(charLoc + 1, low, high);
		break;
	case '3':
		currentName[charLoc] = 'D';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'E';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'F';
		search(charLoc + 1, low, high);
		break;
	case '4':
		currentName[charLoc] = 'G';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'H';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'I';
		search(charLoc + 1, low, high);
		break;
	case '5':
		currentName[charLoc] = 'J';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'K';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'L';
		search(charLoc + 1, low, high);
		break;
	case '6':
		currentName[charLoc] = 'M';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'N';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'O';
		search(charLoc + 1, low, high);
		break;
	case '7':
		currentName[charLoc] = 'P';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'R';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'S';
		search(charLoc + 1, low, high);
		break;
	case '8':
		currentName[charLoc] = 'T';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'U';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'V';
		search(charLoc + 1, low, high);
		break;
	case '9':
		currentName[charLoc] = 'W';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'X';
		search(charLoc + 1, low, high);
		currentName[charLoc] = 'Y';
		search(charLoc + 1, low, high);
		break;
	}
}

int __main() {

	ifstream fin("namenum.in");
	ifstream dict2in("dict.txt");
	fin >> num;
	string name;
	while (!dict2in.eof()) {
		dict2in >> name;
		dict2.insert(dict2.end(), name);
	}

	currentName.append(num.length(), ' ');
	search(0, 0, dict2.size());

	if (!foundNames) {
		fout2 << "NONE" << endl;
	}

	return 0;
}
