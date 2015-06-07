#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

float* calculateGuassianPyramidLevel(float* currentLevel, int currentLevelSize) {
	float* nextLevel = new float[currentLevelSize / 2];

	for (int i = 0; i < currentLevelSize / 2; i++) {
		nextLevel[i] = (currentLevel[2 * i] + currentLevel[2 * i + 1]) * 0.5f;
	}

	return nextLevel;
}

void printCosineCoeffients(int M) {
	for (int p = 0; p < M; p++) {
		float scale = (p == 0) ? (1 / sqrtf(M)) : (sqrtf(2.0f) / sqrtf(M));
		for (int m = 0; m < M; m++) {
			cout << scale * cosf((M_PI * p * (2 * m + 1)) / (2 * M)) << ", ";
			//			if(p == 0)
			//			{
			//				cout << "(sqrtf(1/" << M << "))";
			//			}
			//			else
			//			{
			//				cout << "(sqrtf(2/" << M << "))";
			//			}
			//			cout << "cos(Pi*"<<p<<"*"<<(2*m+1)<<")/"<<(2*M)<<"), ";
		}
		cout << endl;
	}
}

void printForuierCoeffients(int M) {
	for (int p = 0; p < M; p++) {
		for (int m = 0; m < M; m++) {
			if (abs(cosf((2 * M_PI * p * m) / M)) > 0.001) {
				cout << cosf(-(2 * M_PI * p * m) / M) << " + ";
			}
			if (abs(sinf((2 * M_PI * p * m) / M)) > 0.001) {
				cout << "i(" << sinf(-(2 * M_PI * p * m) / M) << ")";
			}
			cout << ", ";
		}
		cout << endl;
	}
}

int main() {

	float* f = new float[3];
	f[0] = 1;
	f[1] = -1;
	f[2] = 4;
	cout << std::max_element(&f, &f + 8) << endl;
	//	int size = 8;
	//
	//	while (size > 1) {
	//		f = calculateGuassianPyramidLevel(f, size);
	//		size = size / 2;
	//
	//		for (int i = 0; i < size; i++) {
	//			cout << f[i] << " ";
	//		}
	//
	//		cout << endl;
	//	}

	printForuierCoeffients(8);

	return 0;
}
