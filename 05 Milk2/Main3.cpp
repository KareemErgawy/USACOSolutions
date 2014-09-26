/*
 ID: kareem_2
 PROG: milk2
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Event {
	int time;
	int type;
};

bool compareEvents(Event e1, Event e2) {
	if (e1.time != e2.time) {
		return e1.time < e2.time;
	}

	return e1.type > e2.type;
}

int main() {

	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int numMilking;
	fin >> numMilking;
	Event* events = new Event[numMilking * 2];

	for (int i = 0; i < numMilking; i++) {
		fin >> events[i * 2].time >> events[i * 2 + 1].time;
		events[i * 2].type = 1;
		events[i * 2 + 1].type = -1;
	}

	sort(events, events + (numMilking * 2), compareEvents);
	bool wasIdle = true;
	int currentStart;
	int numFarmers = 0;
	int maxMilking = 0;
	int maxNoMilking = 0;

	for (int i = 0; i < numMilking * 2; i++) {
		numFarmers += events[i].type;

		if (numFarmers == 0 && !wasIdle) {
			int tMilking = events[i].time - currentStart;

			if (tMilking > maxMilking) {
				maxMilking = tMilking;
			}

			currentStart = events[i].time;
		} else if (numFarmers > 0 && wasIdle) {
			if (i > 0) {
				int tNoMilking = events[i].time - currentStart;
				if (tNoMilking > maxNoMilking) {
					maxNoMilking = tNoMilking;
				}
			}

			currentStart = events[i].time;
		}

		wasIdle = (numFarmers == 0);
	}

	fout << maxMilking << " " << maxNoMilking << endl;

	return 0;
}
