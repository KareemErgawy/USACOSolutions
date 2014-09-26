/*
 ID: kareem_2
 PROG: milk
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int requiredAmount, numFarmers;
	fin >> requiredAmount >> numFarmers;
	int MAX_PRICE = 1001;
	int* amountPerPrice = (int*) calloc(MAX_PRICE, sizeof(int));
	int price;
	int amount;

	for (int i = 0; i < numFarmers; i++) {
		fin >> price >> amount;
		amountPerPrice[price] += amount;
	}

	int totalCost = 0;

	for (int i = 0; i < MAX_PRICE; i++) {
		if (amountPerPrice[i] > 0) {
			if (requiredAmount > amountPerPrice[i]) {
				requiredAmount -= amountPerPrice[i];
				totalCost += (i * amountPerPrice[i]);
			} else {
				totalCost += (i * requiredAmount);
				break;
			}
		}
	}

	fout << totalCost << endl;

	return 0;
}
