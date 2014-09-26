/*
 ID: kareem_2
 PROG: pprime
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void genPalindrom(int len, int current, int mulLeft, int mulRight) {
	if (len == 2) {
		for (int i = 1; i < 10; i++) {
			cout << current + (i * mulLeft) + (i * mulRight) << endl;
		}
	}else if(len == 1){
		for (int i = 1; i < 10; i++) {
			cout << current + (i * mulLeft) << endl;
		}
	}else{
		for (int i = 1; i < 10; i++) {
			genPalindrom(len - 2, current + (i * mulLeft) + (i * mulRight), mulLeft / 10, mulRight * 10);
		}
	}
}

int main() {
	genPalindrom(1, 0, 1, 1);
	genPalindrom(2, 0, 10, 1);
	genPalindrom(3, 0, 100, 1);

	return 0;
}
