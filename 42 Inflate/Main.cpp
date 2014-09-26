/*
 ID: kareem_2
 PROG: inflate
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct ProblemClass {
	int points;
	int minutes;
	float rate;
};

bool compareClass(ProblemClass c1, ProblemClass c2) {
	return c1.rate > c2.rate;
}

int main() {

	ifstream fin("inflate.in");
	ofstream fout("inflate.out");

	int m, n;
	fin >> m >> n;
	ProblemClass* classes = new ProblemClass[n];

	for (int i = 0; i < n; i++) {
		fin >> classes[i].points >> classes[i].minutes;
		//		classes[i].rate = (float) classes[i].points
		//				/ (float) classes[i].minutes;
	}

	//	sort(classes, classes + n, compareClass);
	//
	//	//	for (int i = 0; i < n; i++) {
	//	//		cout << classes[i].points << " " << classes[i].minutes << " "
	//	//				<< classes[i].rate << endl;
	//	//	}
	//
	//	int total = 0;
	//
	//	for (int i = 0; i < n; i++) {
	//		total += classes[i].points * (m / classes[i].minutes);
	//		m = m - (classes[i].minutes * (m / classes[i].minutes));
	//
	//		//		if((m > 0) && ((m / classes[i].minutes) == 0) && i == n - 1 && (classes[i - 1].points < classes[i].points) && (m + classes[i-1].points >= classes[i].points)) {
	//		//			total = total > total - classes[i - 1].points + classes[i].points ? total : total - classes[i - 1].points + classes[i].points;
	//		//			m = m - (classes[i].minutes - classes[i - 1].minutes);
	//		//		}
	//	}
	//
	//	fout << total << endl;

	int* dp = new int[m + 1];
	dp[0] = 0;

	for (int i = 1; i <= m; i++) {
		int max = -1;
		for (int j = 0; j < n; j++) {
			if (i >= classes[j].minutes) {
				int candidate = classes[j].points + dp[i - classes[j].minutes];
				max = (max > candidate) ? max : candidate;
				dp[i] = max;
			}
		}
	}

	fout << dp[m] << endl;

	return 0;
}
