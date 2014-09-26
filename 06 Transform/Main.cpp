/*
 ID: kareem_2
 PROG: transform
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

char** rotate90(char** pattern, int size) {
	char** result = new char*[size];

	for (int i = 0; i < size; i++) {
		result[i] = new char[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[j][size - 1 - i] = pattern[i][j];
		}
	}

	return result;
}

char** reflect(char** pattern, int size) {
	char** result = new char*[size];

	for (int i = 0; i < size; i++) {
		result[i] = new char[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[i][size - 1 - j] = pattern[i][j];
		}
	}

	return result;
}

bool comparePatterns(char** pattern1, char** pattern2, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (pattern1[i][j] != pattern2[i][j]) {
				return false;
			}
		}
	}

	return true;
}

int main() {

	ifstream fin("transform.in");
	ofstream fout("transform.out");
	int size;
	fin >> size;
	char** originalPattern = new char*[size];

	for (int i = 0; i < size; i++) {
		originalPattern[i] = new char[size];
		for (int j = 0; j < size; j++) {
			fin >> originalPattern[i][j];
		}
	}

	char** targetPattern = new char*[size];

	for (int i = 0; i < size; i++) {
		targetPattern[i] = new char[size];
		for (int j = 0; j < size; j++) {
			fin >> targetPattern[i][j];
		}
	}

	char** res90 = rotate90(originalPattern, size);

	if (comparePatterns(res90, targetPattern, size)) {
		fout << "1" << endl;
		return 0;
	}

	char** res180 = rotate90(res90, size);

	if (comparePatterns(res180, targetPattern, size)) {
		fout << "2" << endl;
		return 0;
	}

	char** res270 = rotate90(res180, size);

	if (comparePatterns(res270, targetPattern, size)) {
		fout << "3" << endl;
		return 0;
	}

	char** resRef = reflect(originalPattern, size);

	if (comparePatterns(resRef, targetPattern, size)) {
		fout << "4" << endl;
		return 0;
	}

	if (comparePatterns(rotate90(resRef, size), targetPattern, size)
			|| comparePatterns(rotate90(rotate90(resRef, size), size),
					targetPattern, size) || comparePatterns(
			rotate90(rotate90(rotate90(resRef, size), size), size),
			targetPattern, size)) {
		fout << "5" << endl;
		return 0;
	}

	if (comparePatterns(originalPattern, targetPattern, size)) {
		fout << "6" << endl;
		return 0;
	}

	fout << "7" << endl;
	return 0;
}
