/*
 ID: kareem_2
 PROG: fracdec
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");

	bool remaindersEncountered[100001];
	int remainderPositions[100001];

	for (int i = 0; i < 100001; i++) {
		remaindersEncountered[i] = false;
	}

	int n, d;
	fin >> n >> d;

	string fraction = "";
	int a = (n / d);

	do {
		fraction = char('0' + (a % 10)) + fraction;
		a = a / 10;
	} while (a > 0);

	fraction = fraction + ".";

	if (n % d == 0) {
		fout << fraction << "0" << endl;
		return 0;
	}

	n = n % d;

	while (true) {
		if (n == 0) {
			break;
		}

		if (remaindersEncountered[n] == true) {
			fraction = fraction.substr(0, remainderPositions[n]) + "("
					+ fraction.substr(remainderPositions[n],
							fraction.length() - remainderPositions[n]) + ")";
			break;
		}

		remaindersEncountered[n] = true;
		remainderPositions[n] = fraction.length();
		n = n * 10;
		fraction = fraction + char('0' + (n / d));

		n = n % d;
	}

	int i = 0;

	do {
		if (i + 76 > fraction.length()) {
			fout << fraction.substr(i, fraction.length() - i) << endl;
			break;
		}

		fout << fraction.substr(i, 76) << endl;
		i += 76;
	} while (true);
	return 0;
}
