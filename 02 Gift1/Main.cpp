/*
 ID: kareem_2
 PROG: gift1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int numPeople;
	fin >> numPeople;
	string* names = new string[numPeople];

	map<string, int> initialMoney;

	for (int i = 0; i < numPeople; i++) {
		fin >> names[i];
		initialMoney[names[i]] = 0;
	}

	for (int i = 0; i < numPeople; i++) {
		string currentName;
		fin >> currentName;
		int currentMoney, numFriends;
		fin >> currentMoney >> numFriends;
		int giftAmount = 0;

		if (numFriends > 0) {
			giftAmount = currentMoney / numFriends;
			initialMoney[currentName] -= (giftAmount * numFriends);
		} else {
			initialMoney[currentName] += currentMoney;
		}

		for (int j = 0; j < numFriends; j++) {
			string currentFriend;
			fin >> currentFriend;

			initialMoney[currentFriend] += giftAmount;
		}
	}

	for (int i = 0; i < numPeople; i++) {
		fout << names[i] << " " << initialMoney[names[i]]
				<< endl;
	}

	return 0;
}
