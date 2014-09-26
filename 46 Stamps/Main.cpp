/*
 ID: kareem_2
 PROG: stamps
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

	ifstream fin("stamps.in");
	ofstream fout("stamps.out");

	int k, n;
	fin >> k >> n;
	int* stamps = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> stamps[i];
	}

	vector<int> dp;
	dp.insert(dp.begin(), 0);
	while (true) {
		int min = -1;
		for (int i = 0; i < n; i++) {
			if (dp.size() >= stamps[i]) {
				if (min == -1) {
					min = dp[dp.size() - stamps[i]] + 1;
				} else {
					min = min > (dp[dp.size() - stamps[i]] + 1) ? dp[dp.size()
							- stamps[i]] + 1 : min;
				}
			}
		}

//		cout << dp.size() << " " << min << endl;
		if (min > k) {
			fout << dp.size() - 1 << endl;
			break;
		}
		dp.insert(dp.end(), min);
	}

	return 0;
}
