/*
 ID: kareem_2
 PROG: ttwo
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int directionsI[4] = { -1, 0, 1, 0 };
int directionsJ[4] = { 0, 1, 0, -1 };

void move(int& ni, int& nj, int& nd, char forest[10][10]) {
	int oi, oj;
	oi = ni;
	oj = nj;
	ni = ni + directionsI[nd];
	nj = nj + directionsJ[nd];

	if (ni < 0 || ni >= 10 || nj < 0 || nj >= 10 || forest[ni][nj] == '*') {
		ni = oi;
		nj = oj;
		nd = (nd + 1) % 4;
	}
}

int main() {

	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");

	char forest[10][10];
	bool farmerVisited[10][10][4];
	bool cowsVisited[10][10][4];
	int fi, fj, fd, ci, cj, cd;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fin >> forest[i][j];
			farmerVisited[i][j][0] = farmerVisited[i][j][1]
					= farmerVisited[i][j][2] = farmerVisited[i][j][3] = false;
			if (forest[i][j] == 'F') {
				farmerVisited[i][j][0] = true;
				fi = i;
				fj = j;
				fd = 0;
			}

			cowsVisited[i][j][0] = cowsVisited[i][j][1] = cowsVisited[i][j][2]
					= cowsVisited[i][j][3] = false;
			if (forest[i][j] == 'C') {
				cowsVisited[i][j][0] = true;
				ci = i;
				cj = j;
				cd = 0;
			}
		}
	}
	int minutes = 0;
	while (true) {
		move(fi, fj, fd, forest);
		move(ci, cj, cd, forest);
		minutes++;
		if (fi == ci && fj == cj) {
			fout << minutes << endl;
			break;
		}

		if (minutes > 400) {
			fout << "0" << endl;
			break;
		}

		farmerVisited[fi][fj][fd] = true;
		cowsVisited[ci][cj][cd] = true;
	}

	return 0;
}
