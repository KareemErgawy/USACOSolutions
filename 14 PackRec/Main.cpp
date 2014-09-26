/*
 ID: kareem_2
 PROG: packrec
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <utility>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

struct EnclosingRect {
	int height;
	int width;
};

ifstream fin("packrec.in");
ofstream fout("packrec.out");
int rects[4][2];
int visitOrder[4];
int numVisited;
int minArea = INT_MAX;
vector<EnclosingRect> minRects;

void CheckDims(int & h, int & w) {
//	fout << w << ", " << h << endl;

	if ((h * w) < minArea) {
		minArea = h * w;
		minRects.clear();
		EnclosingRect newRect;
		newRect.width = min(h, w);
		newRect.height = max(h, w);
		minRects.push_back(newRect);
//		fout << "new min found: " << minArea << " - " << w << ", " << h << endl;

	} else if ((h * w) == minArea) {
		int i;
		for (i = 0; i < minRects.size(); i++) {
			if (minRects[i].width == min(h, w)) {
				break;
			}
		}

		if (i == minRects.size()) {
			EnclosingRect newRect;
			newRect.width = min(h, w);
			newRect.height = max(h, w);
			minRects.push_back(newRect);
//						fout << "matching min found: " << minArea << " - " << w << ", "
//								<< h << endl;
		}
	}
}

void traverse() {
	if (numVisited == 4) {
//		for (int i = 0; i < 4; i++) {
//			fout << "(" << rects[visitOrder[i]][0] << ", "
//					<< rects[visitOrder[i]][1] << ")  ";
//		}

//		fout << endl;

		int w = 0;
		int h = 0;
		for (int i = 0; i < 4; i++) {
			w += rects[i][0];
			if (h < rects[i][1]) {
				h = rects[i][1];
			}
		}

		CheckDims(h, w);
		int tmpW = 0;
		int tmpH = 0;
		for (int i = 1; i < 4; i++) {
			tmpW += rects[visitOrder[i]][0];
			if (tmpH < rects[visitOrder[i]][1]) {
				tmpH = rects[visitOrder[i]][1];
			}
		}
		w = (rects[visitOrder[0]][1] < tmpW) ? tmpW : rects[visitOrder[0]][1];
		h = rects[visitOrder[0]][0] + tmpH;

		CheckDims(h, w);

		tmpW = rects[visitOrder[1]][0] + rects[visitOrder[2]][0];
		w = ((tmpW < rects[visitOrder[0]][1]) ? rects[visitOrder[0]][1] : tmpW)
				+ rects[visitOrder[3]][0];

		tmpH
				= (rects[visitOrder[1]][1] < rects[visitOrder[2]][1]) ? rects[visitOrder[2]][1]
						: rects[visitOrder[1]][1];
		h
				= (tmpH + rects[visitOrder[0]][0] < rects[visitOrder[3]][1]) ? rects[visitOrder[3]][1]
						: tmpH + rects[visitOrder[0]][0];

		CheckDims(h, w);

		w = rects[visitOrder[0]][0] + (rects[visitOrder[1]][0]
				< rects[visitOrder[2]][0] ? rects[visitOrder[2]][0]
				: rects[visitOrder[1]][0]) + rects[visitOrder[3]][0];
		h = (rects[visitOrder[0]][1] < (rects[visitOrder[1]][1]
				+ rects[visitOrder[2]][1])) ? rects[visitOrder[1]][1]
				+ rects[visitOrder[2]][1] : rects[visitOrder[1]][1]
				+ rects[visitOrder[0]][1];
		h = (h < rects[visitOrder[3]][1]) ? rects[visitOrder[3]][1] : h;

		CheckDims(h, w);

		w
				= ((rects[visitOrder[0]][0] < rects[visitOrder[1]][0]) ? rects[visitOrder[1]][0]
						: rects[visitOrder[0]][0]) + rects[visitOrder[2]][0]
						+ rects[visitOrder[3]][0];
		h = ((rects[visitOrder[0]][1] + rects[visitOrder[1]][1])
				< rects[visitOrder[2]][1]) ? rects[visitOrder[2]][1]
				: rects[visitOrder[0]][1] + rects[visitOrder[1]][1];
		h = (h < rects[visitOrder[3]][1]) ? rects[visitOrder[3]][1] : h;
		CheckDims(h, w);

		w = rects[visitOrder[0]][0] + rects[visitOrder[3]][0];
		if (rects[visitOrder[1]][0] + rects[visitOrder[3]][0] > w) {
			w = rects[visitOrder[1]][0] + rects[visitOrder[3]][0];
		}
		if ((rects[visitOrder[0]][1] + rects[visitOrder[1]][1]
				> rects[visitOrder[3]][1]) && (rects[visitOrder[1]][0]
				+ rects[visitOrder[2]][1] > w)) {
			w = rects[visitOrder[1]][0] + rects[visitOrder[2]][1];
		}
		if ((rects[visitOrder[0]][1] > rects[visitOrder[3]][1])
				&& (rects[visitOrder[0]][0] + rects[visitOrder[2]][1] > w)) {
			w = rects[visitOrder[0]][0] + rects[visitOrder[2]][1];
		}
		if(rects[visitOrder[2]][1] > w){
			w = rects[visitOrder[2]][1];
		}

		//		w
		//				= (rects[visitOrder[0]][0] + rects[visitOrder[3]][0]
		//						< rects[visitOrder[1]][0] + rects[visitOrder[2]][1]) ? rects[visitOrder[1]][0]
		//						+ rects[visitOrder[2]][1]
		//						: rects[visitOrder[0]][0] + rects[visitOrder[3]][0];
		h = rects[visitOrder[0]][1] + rects[visitOrder[1]][1];
		if (rects[visitOrder[2]][0] + rects[visitOrder[3]][1] > h) {
			h = rects[visitOrder[2]][0] + rects[visitOrder[3]][1];
		}

		//		h
		//				= (rects[visitOrder[0]][1] + rects[visitOrder[1]][1]
		//						< rects[visitOrder[2]][0] + rects[visitOrder[3]][1]) ? rects[visitOrder[2]][0]
		//						+ rects[visitOrder[3]][1]
		//						: rects[visitOrder[0]][1] + rects[visitOrder[1]][1];

		CheckDims(h, w);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (visitOrder[i] == -1) {
			visitOrder[i] = numVisited;
			numVisited++;
			traverse();
			visitOrder[i] = -1;
			numVisited--;

			visitOrder[i] = numVisited;
			numVisited++;
			swap(rects[visitOrder[i]][0], rects[visitOrder[i]][1]);
			traverse();
			visitOrder[i] = -1;
			numVisited--;
		}
	}
}

int sortRect(const EnclosingRect& lhs, const EnclosingRect& rhs) {
	return lhs.width < rhs.width;
}

int main() {

	numVisited = 0;

	for (int i = 0; i < 4; i++) {
		visitOrder[i] = -1;
		fin >> rects[i][0] >> rects[i][1];

		if (rects[i][1] < rects[i][0]) {
			swap(rects[i][0], rects[i][1]);
		}
	}

	traverse();

		sort(minRects.begin(), minRects.end(), sortRect);
	//	fout << "Num: " << minRects.size() << endl;
		fout << (minRects[0].width * minRects[0].height) << endl;
	//
		for (int i = 0; i < minRects.size(); i++) {
			fout << minRects[i].width << " " << minRects[i].height << endl;
		}

	return 0;
}
