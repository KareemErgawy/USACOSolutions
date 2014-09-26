/*
 ID: kareem_2
 PROG: fact4
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {

	ifstream fin("fact4.in");
	ofstream fout("fact4.out");

	int n;

	fin >> n;

	unsigned long long lowerPart = 1;
	int zeros;
	for(int i=2 ; i<=n ; i++) {
		lowerPart *= i;
//		cout << i << " => " << lowerPart << endl;
		zeros = 0;
		while(lowerPart % 10 == 0){
			lowerPart = lowerPart / 10;
			zeros++;
		}

		lowerPart = (lowerPart % 10000);
	}

	while(lowerPart % 10 == 0) {
		lowerPart = lowerPart / 10;
	}
	fout << (lowerPart % 10) << endl;

	return 0;
}
