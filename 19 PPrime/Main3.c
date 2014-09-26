/*
 ID: kareem_2
 PROG: pprime
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

long reverse2(long num, int middle) {
	int temp = num;
	int numDigits = 0;
	long total = 0;

	while (temp) {
		total = (total * 10) + (temp % 10);
		temp = temp / 10;
		numDigits++;
		num = num * 10;
		middle = middle * 10;
	}

	num = num * 10;
//	cout << total << " " << middle << " " << num << endl;

	return total + middle + num;
}

bool isPrime3(long int n) {

	if (n == 121) {
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

int ___main() {

	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	int a, b;
	fin >> a >> b;
	int foundPrimes = 0;
	int primes[100000];

	if (a <= 11 && b >= 11) {
		foundPrimes = 1;
		primes[0] = 11;
	}

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 10; j++) {
			long num = reverse2(i, j);
			if (num >= a && num <= b && isPrime3(num)) {
				primes[foundPrimes++] = num;
			}
		}
	}

	sort(primes, primes + foundPrimes);

	for (int i = 0; i < foundPrimes; i++) {
		fout << primes[i] << endl;
	}

	return 0;
}
