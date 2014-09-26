/*
 ID: kareem_2
 PROG: lamps
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");
int n;
int c;
vector<int> onLamps;
vector<int> offLamps;
bool solutionFound = false;
map<string, bool> solutions;
vector<map<string, bool> > dp;

void search(string lamps, int counter) {

	if (dp[counter].find(lamps) != dp[counter].end()) {
		return;
	} else {
		dp[counter][lamps] = true;
	}

	if (counter == c) {
		int i = 0;
		for (i = 0; i < onLamps.size(); i++) {
			if (lamps[onLamps[i]] == '0') {
				break;
			}
		}

		if (i == onLamps.size()) {
			for (i = 0; i < offLamps.size(); i++) {
				if (lamps[offLamps[i]] == '1') {
					break;
				}
			}

			if (i == offLamps.size()) {
				solutionFound = true;
				if (solutions.find(lamps) == solutions.end()) {
					solutions[lamps] = true;
					//					fout << lamps.substr(1, lamps.size() - 1) << endl;
				}
			}
		}

		return;
	}
	string lamps1 = lamps;
	for (int i = 1; i <= n; i++) {
		if (lamps1[i] == '0') {
			lamps1[i] = '1';
		} else {
			lamps1[i] = '0';
		}
	}
	search(lamps1, counter + 1);

	string lamps2 = lamps;
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			if (lamps2[i] == '0') {
				lamps2[i] = '1';
			} else {
				lamps2[i] = '0';
			}
		}
	}
	search(lamps2, counter + 1);

	string lamps3 = lamps;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			if (lamps3[i] == '0') {
				lamps3[i] = '1';
			} else {
				lamps3[i] = '0';
			}
		}
	}
	search(lamps3, counter + 1);

	string lamps4 = lamps;
	for (int i = 1; i <= n; i++) {
		if (((i - 1) % 3) == 0) {
			if (lamps4[i] == '0') {
				lamps4[i] = '1';
			} else {
				lamps4[i] = '0';
			}
		}
	}
	search(lamps4, counter + 1);
}

int main() {

	fin >> n;
	fin >> c;
	dp.resize(c + 1);
	int l;
	fin >> l;
	while (l != -1) {
		onLamps.insert(onLamps.end(), l);
		fin >> l;
	}
	fin >> l;
	while (l != -1) {
		offLamps.insert(offLamps.end(), l);
		fin >> l;
	}

	string lamps = "";

	for (int i = 0; i <= n; i++) {
		lamps += "1";
	}

	search(lamps, 0);

	vector<string> solutionKeys;

	for (map<string, bool>::iterator it = solutions.begin(); it
			!= solutions.end(); ++it) {
		solutionKeys.push_back(it->first.substr(1, it->first.size() - 1));
	}

	sort(solutionKeys.begin(), solutionKeys.end());

	for (int i = 0; i < solutionKeys.size(); i++) {
		fout << solutionKeys[i] << endl;
	}

	if (!solutionFound) {
		fout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
