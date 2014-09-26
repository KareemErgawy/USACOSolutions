/*
 ID: kareem_2
 PROG: holstein
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main() {
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");

	int numVitamines;
	fin >> numVitamines;
	int* vitamines = new int[numVitamines];

	for (int i = 0; i < numVitamines; i++) {
		fin >> vitamines[i];
	}

	int numFeeds;
	fin >> numFeeds;
	int** feeds = new int*[numFeeds];
	for (int i = 0; i < numFeeds; i++) {
		feeds[i] = new int[numVitamines];

		for (int j = 0; j < numVitamines; j++) {
			fin >> feeds[i][j];
		}
	}

	int totalCombinations = pow(2, numFeeds);
	int minFeedSize = numFeeds + 1;
	int minFeed;
	int* tempVitamines = new int[numVitamines];

	for (int i = 0; i < totalCombinations; i++) {

		for (int j = 0; j < numVitamines; j++) {
			tempVitamines[j] = vitamines[j];
		}

		int feedSize = 0;
		bool found = true;
		for (int j = 0; j < numFeeds; j++) {
			if (i & (1 << j)) {
				feedSize++;
				if (feedSize >= minFeedSize) {
					found = false;
					break;
				}

				for (int k = 0; k < numVitamines; k++) {
					tempVitamines[k] -= feeds[j][k];
				}
			}
		}

		if (!found) {
			continue;
		}

		for (int j = 0; j < numVitamines; j++) {
			if (tempVitamines[j] > 0) {
				found = false;
				break;
			}
		}

		if (!found) {
			continue;
		}

		minFeedSize = feedSize;
		minFeed = i;
	}

	fout << minFeedSize;

	for (int i = 0; i < numFeeds; i++) {
		if (minFeed & (1 << i)) {
			fout << " " << (i + 1);
		}
	}

	fout << endl;

	return 0;
}
