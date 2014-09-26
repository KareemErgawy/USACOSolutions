/*
 ID: kareem_2
 PROG: friday
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

int _main() {
	ofstream fout("friday.out");
	ifstream fin("friday.in");

	int numYears;
	fin >> numYears;

	int currentWeekDay = 2;
//	int currentMonthDay = 1;
//	int currentMonth = 1;
//	int currentYear = 0;
	int freq[7] = { 0, 0, 0, 0, 0, 0, 0 };

	for (int y = 1900; y < (1900 + numYears); y++) {
		bool isLeapYear = false;

		if ((y % 400 == 0) || (!(y % 100 == 0) && (y % 4 == 0))) {
			isLeapYear = true;
			//cout << y << " is leap" << endl;
		}

		for (int m = 1; m <= 12; m++) {
			int monthLength;
			if (m == 9 || m == 4 || m == 6 || m == 11) {
				monthLength = 30;
			} else if (m == 2) {
				if (isLeapYear) {
					monthLength = 29;
				} else {
					monthLength = 28;
				}
			} else {
				monthLength = 31;
			}

			for (int d = 1; d <= monthLength; d++) {

				//cout << "Date " << y << "/" << m << "/" << d << " Week Day " << currentWeekDay;

				if(d == 13)
				{
					freq[currentWeekDay]++;
				}

				currentWeekDay = (currentWeekDay + 1) % 7;
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		fout << freq[i];

		if(i < 6){
			fout << " ";
		}
	}

	fout << endl;

	return 0;
}
