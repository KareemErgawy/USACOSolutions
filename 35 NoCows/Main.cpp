/*
 ID: kareem_2
 PROG: nocows
 LANG: C++
 */

#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
typedef vector<int> VI;
typedef vector<string> VS;
#define debug 0

long long dp[201][101];
int N, K;

void solve() {
	FOR(k,1,K) { // loop on heights
		dp[1][k] = 1;
		FOR(n,2,N) { // loop on nodes
			dp[n][k] = 0;
			FOR(p,1,n-2) { // loop on previous nodes
				dp[n][k] += dp[p][k - 1] * dp[n - 1 - p][k - 1];
				dp[n][k] %= 9901;
			}
		}
	}
}

/********************************************************************************************/
int main() {
	ofstream fout("nocows.out");
	ifstream fin("nocows.in");

	fin >> N >> K;
	N = 11;
	K = 4;
	if (N % 2 == 0) {
		cout << 0 << endl;
		fout << 0 << endl;
		return 0;
	}
	solve();

	int ans = ((dp[N][K] - dp[N][K - 1] + 9901) % 9901);

	cout << dp[N][K] << " " << ans << endl;
	fout << ans << endl;
	return 0;
}
