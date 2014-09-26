/*
 ID: kareem_2
 PROG: prefix
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> primitives;
string sequence;
char dp[200000];

bool search(long i) {
	if (i == -1) {
		return true;
	}

	if (dp[i] != -1) {
		return dp[i];
	}

	for (int j = 0; j < primitives.size(); j++) {
		if (primitives[j][primitives[j].size() - 1] == sequence[i] && (primitives[j].size() <= (i + 1))
				&& sequence.substr(i + 1 - primitives[j].size(), primitives[j].size()) == primitives[j]) {
			if (search(i - primitives[j].size())) {
				dp[i] = 1;
				return true;
			}
		}
	}

	dp[i] = 0;
	return false;
}

int main() {

	ifstream fin("prefix.in");
	ofstream fout("prefix.out");

	string prim;
	fin >> prim;

	while(prim != ".") {
		primitives.insert(primitives.end(), prim);
		fin >> prim;
	}

	string subSeq;
	while(fin >> subSeq) {
		sequence += subSeq;
	}
	cout << sequence.size() << endl;
	long i;
	for (i = 0; i < sequence.size(); i++) {
		dp[i] = -1;
	}

	for (i = sequence.size() - 1; i >= 0; i--) {
		search(i);
		if (dp[i] == 1) {
			fout << i + 1 << endl;
			break;
		}
	}
	if (i < 0) {
		fout << "0" << endl;
	}
	return 0;
}
