/*
 ID: kareem_2
 PROG: rect1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
using namespace std;

struct Rect {
	int x1;
	int y1;
	int x2;
	int y2;
	int color;
};

int main() {
	ifstream fin("rect1.in");
	ofstream fout("rect1.out");
	int a, b, n;
	fin >> a >> b >> n;
	list<Rect>* rects = new list<Rect> [n + 1];
	Rect newRect;
	newRect.x1 = 0;
	newRect.y1 = 0;
	newRect.x2 = a;
	newRect.y2 = b;
	newRect.color = 1;
	rects[0].insert(rects[0].end(), newRect);
	int colorSpace[2501];

	for (int i = 0; i <= 2500; i++) {
		colorSpace[i] = 0;
	}
	colorSpace[1] = a * b;

	for (int i = 1; i <= n; i++) {
		fin >> newRect.x1 >> newRect.y1 >> newRect.x2 >> newRect.y2
				>> newRect.color;
		int area = (newRect.x2 - newRect.x1) * (newRect.y2 - newRect.y1);
		colorSpace[newRect.color] += area;
		rects[i].insert(rects[i].end(), newRect);
	}

	list<Rect>::iterator it1;
	list<Rect>::iterator it2;
	Rect rect1;
	Rect rect2;
	Rect overlap;
	for (int i = n; i >= 0; i--) {
		it1 = rects[i].begin();
		while (it1 != rects[i].end()) {
			rect1 = *it1;
			for (int j = i - 1; j >= 0; j--) {
				it2 = rects[j].begin();
				size_t s = rects[j].size();
				size_t i = 0;
				while (it2 != rects[j].end() && i < s) {
					rect2 = *it2;
					i++;
					int xOver = max(0,
							min(rect1.x2, rect2.x2) - max(rect1.x1, rect2.x1));
					int yOver = max(0,
							min(rect1.y2, rect2.y2) - max(rect1.y1, rect2.y1));
					if (xOver > 0 && yOver > 0) {
						overlap.x1 = max(rect1.x1, rect2.x1);
						overlap.y1 = max(rect1.y1, rect2.y1);
						overlap.x2 = min(rect1.x2, rect2.x2);
						overlap.y2 = min(rect1.y2, rect2.y2);
						colorSpace[rect2.color] -= (xOver * yOver);
						newRect.color = rect2.color;
						if (rect2.y1 < overlap.y1) {
							newRect.x1 = rect2.x1;
							newRect.y1 = rect2.y1;
							newRect.x2 = rect2.x2;
							newRect.y2 = overlap.y1;
							rects[j].insert(rects[j].end(), newRect);
						}

						if (rect2.y2 > overlap.y2) {
							newRect.x1 = rect2.x1;
							newRect.y1 = overlap.y2;
							newRect.x2 = rect2.x2;
							newRect.y2 = rect2.y2;
							rects[j].insert(rects[j].end(), newRect);
						}

						if (rect2.x1 < overlap.x1) {
							newRect.x1 = rect2.x1;
							newRect.y1 = max(rect2.y1, overlap.y1);
							newRect.x2 = overlap.x1;
							newRect.y2 = min(rect2.y2, overlap.y2);
							rects[j].insert(rects[j].end(), newRect);
						}

						if (rect2.x2 > overlap.x2) {
							newRect.x1 = overlap.x2;
							newRect.y1 = max(rect2.y1, overlap.y1);
							newRect.x2 = rect2.x2;
							newRect.y2 = min(rect2.y2, overlap.y2);
							rects[j].insert(rects[j].end(), newRect);
						}
						it2 = rects[j].erase(it2);
					} else {
						it2++;
					}
				}
			}
			it1++;
		}
	}

	for (int i = 1; i <= 2500; i++) {
		if (colorSpace[i] > 0) {
			fout << i << " " << colorSpace[i] << endl;
		}
	}

	return 0;
}
