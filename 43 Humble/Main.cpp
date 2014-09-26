/*
 ID: kareem_2
 PROG: humble
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <climits>
#include <queue>
#include <vector>
#include <set>
using namespace std;

//bool canBeFactorized(int x, int* s, int k) {
//
//	while (x > 1) {
//		int i = 0;
//		for (i = 0; i < k; i++) {
//			if (x % s[i] == 0) {
//				x = x / s[i];
//				break;
//			}
//		}
//
//		if (i == k) {
//			return false;
//		}
//	}
//
//	return true;
//}

//struct IntAsc {
//	bool operator()(const int& lhs, const int& rhs) const {
//		return lhs > rhs;
//	}
//};

int main() {

	ifstream fin("humble.in");
	ofstream fout("humble.out");
	int numPrimes, n;
	fin >> numPrimes >> n;
	int* primes = new int[numPrimes];
	set<long> humbleNumbersSet;

	int i, j;
	for (i = 0; i < numPrimes; ++i) {
		fin >> primes[i];
		humbleNumbersSet.insert(primes[i]);
	}
	long current;
	long result;
	for (i = 0; i < n; ++i) {
		current = *humbleNumbersSet.begin();
		if (i == n - 1) {
			fout << current << endl;
			break;
		}
		humbleNumbersSet.erase(humbleNumbersSet.begin());

		for (j = 0; j < numPrimes; j++) {
			result = current * primes[j];
			if (result / primes[j] == current) {
				if (humbleNumbersSet.size() > n) {
					if (*humbleNumbersSet.rbegin() > result) {
						humbleNumbersSet.erase(--humbleNumbersSet.end());
						humbleNumbersSet.insert(result);
					}
				} else {
					humbleNumbersSet.insert(result);
				}
			}
		}
	}

	//	for (int i = 0; i < n; i++) {
	//		int current = humbleNumbers.top();
	//		cout << current << endl;
	//		humbleNumbers.pop();
	//
	//		for (int j = 0; j < numPrimes; j++) {
	//			humbleNumbers.push(current * primes[j]);
	//		}
	//	}

	//	int x = 2;
	//	int i = 0;
	//	while (true) {
	//		if (canBeFactorized(x, s, sSize)) {
	//			i++;
	//			cout << x << endl;
	//			if (i == n) {
	//				break;
	//			}
	//		}
	//		x++;
	//	}
	//
	//	fout << x << endl;

	//	bool* usedS = new bool[sSize];
	//	int* dp = new int[n + 1];
	//	dp[0] = 1;
	//	int lastS = -1;
	//
	//	for (int i = 1; i <= n; i++) {
	//		dp[i] = INT_MAX;
	//		bool foundAny = false;
	//		for (int k = 0; k < sSize; k++) {
	//			for (int j = i - 1; j >= (i >= sSize ? i - sSize : 0); j--) {
	//				if (dp[j] * s[k] > dp[i - 1] && dp[j] * s[k] < dp[i]) {
	//					dp[i] = dp[j] * s[k];
	//					if (dp[j] == 1) {
	//						usedS[k] = true;
	//						lastS = (lastS < k) ? k : lastS;
	//					}
	//					foundAny = true;
	//				}
	//			}
	//			if (!foundAny) {
	//				break;
	//			}
	//		}
	//
	//		if (!foundAny || (lastS < sSize - 1 && !usedS[lastS + 1])) {
	//			for (int k = 0; k < sSize; k++) {
	//				if (s[k] > dp[i - 1] && s[k] < dp[i]) {
	//					dp[i] = s[k];
	//					usedS[k] = true;
	//				}
	//			}
	//		}
	//	}
	//
	//	fout << dp[n] << endl;
	return 0;
}
