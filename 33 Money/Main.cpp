/*
 ID: kareem_2
 PROG: money
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

typedef long long ll;

int v;
int n;
int* coins;

typedef unsigned long long ull;

ull countWays() {
//	  initialize array ways[0..Max] to all zeros
//	  ways[0] = 1
//	  for each i from 1 upto K do
//	    for each sum s from max downto element i do
//	      ways[s] += ways[s - element i]
	ull* ways = new ull[n + 1];
	for (int i = 0; i <= n; i++) {
		ways[i] = 0;
	}

	ways[0] = 1;

	for(int i=0 ; i<v ; i++){
		for(int j=coins[i] ; j<=n ; j++){
			ways[j] += ways[j - coins[i]];
//			cout << j << " " << ways[j] << endl;
		}
	}

	return ways[n];
}

int main() {
	ifstream fin("money.in");
	ofstream fout("money.out");

	fin >> v >> n;

	coins = new int[v];

	for (int i = 0; i < v; i++) {
		fin >> coins[i];
	}

	fout << countWays() << endl;

	return 0;
}
