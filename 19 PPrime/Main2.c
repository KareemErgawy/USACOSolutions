/*
 ID: kareem_2
 PROG: pprime
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

int a2, b2;
ofstream fout2("pprime.out");

bool isPrime2(long int n) {

	if(n == 121){
		int x = 0;
		x++;
	}

	if (n == 1) {
		return false;
	}

	if (n == 2) {
		return true;
	}

	if (n % 2 == 0) {
		return false;
	}

	for (long int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

void generate(int n, bool odd) {
	char buffer[30];
	sprintf(buffer, "%d", n);
	char *p, *q;
	p = buffer + strlen(buffer);
	q = p - (odd ? 1 : 0);

	while (q >= buffer) {
		*p++ = *--q;
	}

	p = '\0';
	long int num = atol(buffer);
	if (num >= a2 && num <= b2 && isPrime2(num)) {
		fout2 << num << endl;
	}
}

void generateOddEvenPalindroms(int start, int end) {
	for (int i = start; i <= end; i++) {
		generate(i, true);
	}

	for (int i = start; i <= end; i++) {
		generate(i, false);
	}
}


int __main() {

	ifstream fin("pprime.in");
	fin >> a2 >> b2;
	generateOddEvenPalindroms(1, 9);
	generateOddEvenPalindroms(10, 99);
	generateOddEvenPalindroms(100, 999);
	generateOddEvenPalindroms(1000, 9999);

	return 0;
}
