/*
 ID: kareem_2
 PROG: milk2
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Interval {
	int start;
	int end;
};

bool sortByStart(const Interval& lhs, const Interval& rhs) {
	return lhs.start < rhs.end;
}

int _main() {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	map<int, int> milkingTimes;
	int numTimes;
	fin >> numTimes;
	int* intervalStarts = new int[numTimes];
	int* intervalEnds = new int[numTimes];
	Interval* intervals = new Interval[numTimes];
	int numIntervals = 0;
	int maxInterval = 0;
	int maxEmptyInterval = 0;

	for (int i = 0; i < numTimes; i++) {
		fin >> intervals[i].start >> intervals[i].end;
	}

	for (int i = 0; i < numTimes; i++) {
		cout << intervals[i].start << ", " << intervals[i].end << endl;
	}

	//sort(intervals, intervals + numTimes, sortByStart);

	for (int i = 0; i < numTimes; i++) {
		for (int j = i + 1; j < numTimes; j++) {
			if (intervals[i].start > intervals[j].start) {
				Interval tmp = intervals[i];
				intervals[i] = intervals[j];
				intervals[j] = tmp;
			}
		}
	}

	for (int i = 0; i < numTimes; i++) {
		cout << intervals[i].start << ", " << intervals[i].end << endl;
	}

	int currentDominatingInterval = 0;

	for (int i = 1; i < numTimes; i++) {
		if ((intervals[i].start >= intervals[currentDominatingInterval].start
				&& intervals[i].start
						<= intervals[currentDominatingInterval].end)
				|| (intervals[i].end
						>= intervals[currentDominatingInterval].start
						&& intervals[i].end
								<= intervals[currentDominatingInterval].end)) {
			intervals[currentDominatingInterval].start = min(
					intervals[currentDominatingInterval].start,
					intervals[i].start);
			intervals[currentDominatingInterval].end = max(
					intervals[currentDominatingInterval].end, intervals[i].end);
		} else {
			maxInterval = max(
					maxInterval,
					intervals[currentDominatingInterval].end
							- intervals[currentDominatingInterval].start);
			maxEmptyInterval = max(
					maxEmptyInterval,
					intervals[i].start
							- intervals[currentDominatingInterval].end);
			currentDominatingInterval = i;
		}
	}

	maxInterval = max(
			maxInterval,
			intervals[currentDominatingInterval].end
					- intervals[currentDominatingInterval].start);

	fout << maxInterval << " " << maxEmptyInterval << endl;
	//
	//	for (int i = 0; i < numTimes; i++) {
	//		int start, end;
	//		fin >> start >> end;
	//		int j;
	//
	//		for (j = 0; j < numIntervals; j++) {
	//
	//			if ((start >= intervalStarts[j] && start <= intervalEnds[j])
	//					|| (end >= intervalStarts[j] && end <= intervalEnds[j])
	//					|| (intervalStarts[j] >= start && intervalStarts[j] <= end)
	//					|| (intervalEnds[j] >= start && intervalEnds[j] <= end)) {
	//				intervalStarts[j] = min(start, intervalStarts[j]);
	//				intervalEnds[j] = max(end, intervalEnds[j]);
	//				maxInterval = max(maxInterval,
	//						intervalEnds[j] - intervalStarts[j]);
	//				break;
	//			}
	//		}
	//
	//		if (j == numIntervals) {
	//			intervalStarts[numIntervals] = start;
	//			intervalEnds[numIntervals] = end;
	//			maxInterval = max(maxInterval,
	//					intervalEnds[numIntervals] - intervalStarts[numIntervals]);
	//			numIntervals++;
	//		}
	//	}
	//
	//	//	for (int i = 0; i < numIntervals - 1; i++) {
	//	//		for (int j = i + 1; j < numIntervals - 1; j++) {
	//	//			if (intervalStarts[i] > intervalStarts[j]) {
	//	//				int tmp = intervalStarts[i];
	//	//				intervalStarts[i] = intervalStarts[j];
	//	//				intervalStarts[j] = tmp;
	//	//				tmp = intervalEnds[i];
	//	//				intervalEnds[i] = intervalEnds[j];
	//	//				intervalEnds[j] = tmp;
	//	//			}
	//	//		}
	//	//	}
	//
	//	for (int i = 0; i < numIntervals - 1; i++) {
	//		cout << "Start: " << intervalStarts[i] << ", End: " << intervalEnds[i]
	//				<< ", Diff: " << (intervalEnds[i] - intervalStarts[i]) << endl;
	//	}
	//
	//	sort(intervalStarts, intervalStarts + numIntervals);
	//	sort(intervalEnds, intervalEnds + numIntervals);
	//	int maxEmptyInterval = 0;
	//
	//	for (int i = 0; i < numIntervals - 1; i++) {
	//		maxEmptyInterval = max(maxEmptyInterval,
	//				intervalStarts[i + 1] - intervalEnds[i]);
	//	}
	//
	//	fout << maxInterval << " " << maxEmptyInterval << endl;

	return 0;
}
