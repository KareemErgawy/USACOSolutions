/*
 ID: kareem_2
 PROG: ariprog
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
int* bisquares;

void generateBisquares(int m) {
	bisquares = new int[m * m * 2 + 1];

	for (int i = 0; i < m * m * 2 + 1; i++) {
		bisquares[i] = false;
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			bisquares[(i * i) + (j * j)] = true;
		}
	}

	//	int numBis = 0;
	//	for (int i = 0; i < m * m * 2 + 1; i++) {
	//		if (bisquares[i]) {
	//			cout << i << endl;
	//			numBis++;
	//		}
	//	}

	//	cout << numBis << endl;
}

void printSequences(int m, int n) {

	int max = (m * m * 2);
	int* seqLength = new int[m * m * 2 + 1];

	for (int i = 0; i < m * m * 2 + 1; i++) {
		seqLength[i] = 0;
	}

	bool foundAny = false;

	for (int i = 1; i <= (max / (n - 1)) + 1; i++) {
		//		cout << "Current diff: " << i << endl;

		for (int j = 0; j <= max; j++) {
			if (bisquares[j]) {
				if (j - i >= 0 && bisquares[j - i]) {
					seqLength[j] = seqLength[j - i] + 1;

					if (seqLength[j] >= n) {
						//						cout << "Seq ends at: " << j << " with diff: " << i
						//								<< endl;
						fout << (j - (i * (n - 1))) << " " << i << endl;
						foundAny = true;
					}
				} else {
					seqLength[j] = 1;
				}

				//				cout << j << ", " << seqLength[j] << endl;
			}
		}
	}

	if (!foundAny) {
		fout << "NONE" << endl;
	}
}

int _main() {

	int m, n;
	fin >> n >> m;
	generateBisquares(m);
	printSequences(m, n);

	return 0;
}
