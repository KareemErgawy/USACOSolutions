/*
 ID: kareem_2
 PROG: sort3
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int n;
	fin >> n;
	int* input = new int[n];
	int* sorted = new int[n];

	for (int i = 0; i < n; i++) {
		fin >> input[i];
		sorted[i] = input[i];
	}

	sort(sorted, sorted + n);
	int numMoves = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if(input[i] != sorted[i] && input[j] != sorted[j] && input[i] == sorted[j] && input[j] == sorted[i]){
				numMoves++;
				input[i] = sorted[i];
				input[j] = sorted[j];
			}
		}
	}

	int cycles = 0;
	for (int i = 0; i < n; i++) {
		if(input[i] != sorted[i]){
			cycles++;
		}
	}

	cycles = 2 * cycles / 3;

	fout << (numMoves + cycles) << endl;

	return 0;
}
