/*
 ID: kareem_2
 PROG: kimbits
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");
	int n, l;
	unsigned long i;
	fin >> n >> l >> i;
	int** dp = new int*[n + 1];

	for (int j = 0; j <= n; j++) {
		dp[j] = new int[j + 1];
	}

	dp[0][0] = 1;
	for (int j = 1; j <= n; j++) {
		for (int k = 0; k <= j; k++) {
			if (k == 0 || k == j) {
				dp[j][k] = 1;
			} else {
				dp[j][k] = dp[j - 1][k] + dp[j - 1][k - 1];
			}
		}
	}

	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= j; k++) {
			cout << dp[j][k] << " ";
		}
		cout << endl;
	}

	unsigned long m = i;
	int highestBitPosition;
	int j = 0;
	while (m > 0) {
		if (m & 1) {
			highestBitPosition = j;
		}
		j++;
		m = m >> 1;
	}

	for (int k = l + 1; k <= highestBitPosition; k++) {
		i += dp[highestBitPosition][k];
	}

//	cout << i - 1 << endl;

	for (int j = 0; j < n; j++) {
		fout << char('0' + (((i - 1) & (1 << (n - 1 - j))) != 0));
	}

	return 0;
}
