/*
 ID: kareem_2
 PROG: ride
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <functional>

using namespace std;

unsigned long weight(string word) {
	unsigned long total = 1;
	for (unsigned int i = 0; i < word.size(); i++) {
		total *= ((word[i] - 'A' + 1) % 47);
	}

	total = total % 47;

	return total;
}

string go(string w1, string w2) {
	return (weight(w1) == weight(w2)) ? "GO" : "STAY";
}

int main() {

	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string a, b;
	fin >> a >> b;
	fout << go(a, b) << endl;

	return 0;
}
