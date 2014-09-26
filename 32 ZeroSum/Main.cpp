/*
 ID: kareem_2
 PROG: zerosum
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector<string> zeroSums;

inline int sumString(int level, char* ops) {
	char prevOp = '+';
	int sum = 0;
	int current = 0;
	for (int i = 0; i <= level; i++) {
		current = (current * 10) + (i + 1);
		if (ops[i] == ' ') {
		} else if (ops[i] == '+') {
			if (prevOp == '+') {
				sum += current;
			} else {
				sum -= current;
			}
			current = 0;
			prevOp = '+';
		} else {
			if (prevOp == '+') {
				sum += current;
			} else {
				sum -= current;
			}
			current = 0;
			prevOp = '-';
		}
	}
	current = (current * 10) + (level + 2);
	if (prevOp == '+') {
		sum += current;
	} else {
		sum -= current;
	}
	return sum;
}

void search(int level, char* ops) {
	if (level == (n - 1)) {
		//		for (int i = 0; i < level; i++) {
		//			cout << ops[i] << endl;
		//		}
		//		cout << endl;
		int sum = sumString(level - 1, ops);
		if (sum == 0) {
			string str = "1";
			for (int i = 0; i < level; i++) {
				str += ops[i];
				str += ('0' + (i + 2));
			}
			zeroSums.insert(zeroSums.end(), str);
		}
		return;
	}

	ops[level] = '+';
	search(level + 1, ops);

	ops[level] = '-';
	search(level + 1, ops);

	ops[level] = ' ';
	search(level + 1, ops);
}

int main() {
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
	fin >> n;
	char* ops = new char[n];
	ops[n - 1] = '\0';
	search(0, ops);

	sort(zeroSums.begin(), zeroSums.end());

	for (int i = 0; i < zeroSums.size(); i++) {
		fout << zeroSums[i] << endl;
	}

	return 0;
}
