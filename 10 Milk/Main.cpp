/*
 ID: kareem_2
 PROG: milk
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

struct Farmer {
	int price;
	uint amount;
};

bool sortByPrice(const Farmer& lhs, const Farmer& rhs) {
	return lhs.price < rhs.price;
}

int _main() {

	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int numFarmers;
	uint requiredAmount;
	fin >> requiredAmount >> numFarmers;
	Farmer* farmers = new Farmer[numFarmers];

	for (int i = 0; i < numFarmers; i++) {
		fin >> farmers[i].price >> farmers[i].amount;
	}

	sort(farmers, farmers + numFarmers, sortByPrice);
	int collectedAmount = 0;
	int totalPrice = 0;

	for (int i = 0; i < numFarmers; i++) {
		if (collectedAmount + farmers[i].amount <= requiredAmount) {
			collectedAmount += farmers[i].amount;
			totalPrice += (farmers[i].amount * farmers[i].price);
		} else {
			int remainingAmount = requiredAmount - collectedAmount;
			collectedAmount += remainingAmount;
			totalPrice += (remainingAmount * farmers[i].price);
		}
	}

	fout << totalPrice << endl;

	return 0;
}
