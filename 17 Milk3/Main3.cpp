/*
 ID: kareem_2
 PROG: milk3
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

bool discovered[21][21];
bool solutions2[21];
int A, B, C;

void search(int c, int b) {
	if (discovered[b][c]) {
		return;
	}

	discovered[b][c] = true;
	int a = C - b - c;

	if (a == 0) {
		if (c == 0) {
			int x = 0;
			x++;
		}
		solutions2[c] = true;
	}

	if (C < b + c) {
		search(C, b - (C - c));
	} else {
		search(c + b, 0);
	}

	if (C < a + c) {
		search(C, b);
	} else {
		search(c + a, b);
	}

	if (B < b + c) {
		search(c - (B - b), B);
	} else {
		search(0, b + c);
	}

	if (B < b + a) {
		search(c, B);
	} else {
		search(c, b + a);
	}

	if (A < a + c) {
		search(c - (A - a), b);
	} else {
		search(0, b);
	}

	if (A < a + b) {
		search(c, b - (A - a));
	} else {
		search(c, 0);
	}
}

int main() {

	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> A >> B >> C;

	for (int i = 0; i < 21; i++) {
		solutions2[i] = false;
		for (int j = 0; j < 21; j++) {
			discovered[i][j] = false;
		}
	}

	search(C, 0);
	bool first = true;

	for (int i = 0; i < 21; i++) {
		if (solutions2[i]) {
			if (!first) {
				fout << " ";
			}
			first = false;
			fout << i;
		}
	}

	fout << endl;

	return 0;
}
