/*
 ID: kareem_2
 PROG: clocks
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <queue>
#include <bitset>
//#include <windows.h>
//#include <psapi.h>
#include <cstring>
#include <math.h>
using namespace std;

struct SolutionStep {
	unsigned long clocks;
	char sequence[50];
};

unsigned long pow10Table[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
unsigned long pow4Table[9] = {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536};

inline unsigned long convertToDecimal(unsigned long n) {
	unsigned long decimal = 0;
	int i = 0;
	while (n > 0) {
		int digit = n % 10;
		n = n / 10;
		decimal += ((digit - 1) * pow4Table[i]);
		i++;
	}

	return decimal;
}

int main() {

	bool
			moves[9][9] = { { true, true, false, true, true, false, false,
					false, false }, { true, true, true, false, false, false,
					false, false, false }, { false, true, true, false, true,
					true, false, false, false }, { true, false, false, true,
					false, false, true, false, false }, { false, true, false,
					true, true, true, false, true, false }, { false, false,
					true, false, false, true, false, false, true }, { false,
					false, false, true, true, false, true, true, false },
					{ false, false, false, false, false, false, true, true,
							true }, { false, false, false, false, true, true,
							false, true, true } };

	bool visited[262144];

	for (int i = 0; i < 262144; i++) {
		visited[i] = false;
	}

	ifstream fin("clocks.in");
	ofstream fout("clocks.out");
	queue<SolutionStep*> expansionQueue;

	SolutionStep* initStep = new SolutionStep();
	//	initStep->sequence = new char[1];
	initStep->clocks = 0;
	initStep->sequence[0] = '\0';
	int clock;
	for (int i = 0; i < 9; i++) {
		fin >> clock;
		clock = clock / 3;
		initStep->clocks += (clock * pow(10, i));
	}

	visited[convertToDecimal(initStep->clocks)] = true;
	expansionQueue.push(initStep);
	unsigned int i, j, k;
	char newChar[2];

	while (!expansionQueue.empty()) {
		SolutionStep* currentStep = expansionQueue.front();
		expansionQueue.pop();

		for (i = 0; i < 9; i++) {
			SolutionStep* newStep = new SolutionStep();
			strcpy(newStep->sequence, currentStep->sequence);
			newChar[0] = (char) ('1' + i);
			newChar[1] = '\0';
			strcat(newStep->sequence, newChar);
			newStep->clocks = 0;

			for (j = 0; j < 9; j++) {
				unsigned long pow10 = pow10Table[j];
				clock = (currentStep->clocks / pow10) % 10;

				if (moves[i][j]) {
					clock = (clock + 1);
					if (clock > 4) {
						clock = 1;
					}
				}

				newStep->clocks += (clock * pow10);
			}

			if (newStep->clocks == 444444444) {
				fout << newStep->sequence[0];
				unsigned int len = strlen(newStep->sequence);
				for (k = 1; k < len; k++) {
					fout << " " << newStep->sequence[k];
				}
				fout << endl;
				return 0;
			}

			unsigned long decimal = convertToDecimal(newStep->clocks);
			if (!visited[decimal]) {
				visited[decimal] = true;
				expansionQueue.push(newStep);
			} else {
				delete newStep;
			}
		}

		delete currentStep;

		//		PROCESS_MEMORY_COUNTERS pmc;
		//		GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
		//		DWORD virtualMemUsedByMe = pmc.PagefileUsage;
		//
		//		cout << "Used memory: " << (virtualMemUsedByMe / 1024) << endl;
	}

	return 0;
}
