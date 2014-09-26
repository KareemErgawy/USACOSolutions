/*
 ID: kareem_2
 PROG: frac1
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("frac1.in");
ofstream fout("frac1.out");

void generateFraction(int n, int n1, int d1, int n2, int d2) {
	if (n1 > d1 || n2 > d2) {
		return;
	}

	if (d1 + d2 > n) {
		return;
	}

	generateFraction(n, n1, d1, n1 + n2, d1 + d2);
	fout << (n1 + n2) << "/" << (d1 + d2) << endl;
	generateFraction(n, n1 + n2, d1 + d2, n2, d2);
}

int main() {
	int n;
	fin >> n;
	fout << "0/1" << endl;
	generateFraction(n, 0, 1, 1, 1);
	fout << "1/1" << endl;

	return 0;
}
