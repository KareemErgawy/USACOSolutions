/*
 ID: kareem_2
 PROG: namenum
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("namenum.in");
ofstream fout("namenum.out");
ifstream dictin("dict.txt");
vector<string> dict;
bool found;

bool searchInDict(int low, int hi, string target) {
	if (low > hi) {
		return false;
	}

	int mid = (hi + low) / 2;
	if (target.compare(dict[mid]) == 0) {
		return true;
	} else if (target > dict[mid]) {
		return searchInDict(mid + 1, hi, target);
	} else {
		return searchInDict(low, mid - 1, target);
	}
}

void printAllCombinations(string n, char charNumMapping[10][3],
		string prefix = "", int level = 0) {
	if (level == n.length()) {

		if (searchInDict(0, dict.size(), prefix)) {
			fout << prefix << endl;
			found = true;
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		printAllCombinations(n, charNumMapping,
				prefix + charNumMapping[n[level] - '0'][i], level + 1);
	}
}

int _main() {

	while (dictin.good()) {
		string word;
		dictin >> word;
		dict.push_back(word);
	}

	char charNumMapping[][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { 'A',
			'B', 'C' }, { 'D', 'E', 'F' }, { 'G', 'H', 'I' },
			{ 'J', 'K', 'L' }, { 'M', 'N', 'O' }, { 'P', 'R', 'S' }, { 'T',
					'U', 'V' }, { 'W', 'X', 'Y' } };

	string num;
	fin >> num;

	found = false;

	printAllCombinations(num, charNumMapping);

	if (!found) {
		fout << "NONE" << endl;
	}

	return 0;
}
