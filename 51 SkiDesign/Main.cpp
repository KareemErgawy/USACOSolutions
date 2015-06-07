/*
 ID: kareem_2
 PROG: skidesign
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int* hills;
int* hillsCopy;

int solve() {
	int cost = 0;
	while (hills[n - 1] - hills[0] > 17) {
		int mod = hills[n - 1] - hills[0] - 17;
		int tmp1, tmp2;
		//		int outOfOrder = 0;
		//		int minOutOfOrder = 1001;
		//		int minCost = 100000;
		int minSplit = mod / 2;
		int j;

		//		for (int i = 0; i <= mod; i++) {
		//			tmp1 = hills[0] + i;
		//			tmp2 = hills[n - 1] - (mod - i);
		//			//			j = 1;
		//			//
		//			//			while (j < n && hills[j] < tmp1) {
		//			//				j++;
		//			//				outOfOrder++;
		//			//			}
		//			//
		//			//			j = n - 2;
		//			//
		//			//			while (j > -1 && hills[j] > tmp2) {
		//			//				j--;
		//			//				outOfOrder++;
		//			//			}
		//
		//			if (minCost > (i * i + (mod - i) * (mod - i))) {
		//				minCost = (i * i + (mod - i) * (mod - i));
		//				//				minOutOfOrder = outOfOrder;
		//				minSplit = i;
		//			}
		//		}

		//		cost += ((minSplit * minSplit) + ((mod - minSplit) * (mod - minSplit)));
		//		cout << cost << endl;
		//		cout << mod << " " << minSplit << endl;
		tmp1 = hills[0] + minSplit;
		tmp2 = hills[n - 1] - (mod - minSplit);
		j = 1;

		while (j < n && hills[j] < tmp1) {
			hills[j - 1] = hills[j];
			j++;
		}

		hills[j - 1] = tmp1;
		j = n - 2;

		while (j > -1 && hills[j] > tmp2) {
			hills[j + 1] = hills[j];
			j--;
		}

		hills[j + 1] = tmp2;

		//		for (int i = 0; i < n; i++) {
		//			cout << hills[i] << " ";
		//		}
		//		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		cout << hills[i] << " " << hillsCopy[i] << endl;
		cost += pow(hills[i] - hillsCopy[i], 2);
	}

	return cost;
}

int main() {
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	fin >> n;
	hills = new int[n];
	hillsCopy = new int[n];

	for (int i = 0; i < n; i++) {
		fin >> hills[i];
		hillsCopy[i] = hills[i];
	}

	sort(hills, hills + n);
	sort(hillsCopy, hillsCopy + n);

	//	for (int i = 0; i < n; i++) {
	//		cout << hills[i] << " ";
	//	}
	//	cout << endl;

	fout << solve() << endl;

	return 0;
}
