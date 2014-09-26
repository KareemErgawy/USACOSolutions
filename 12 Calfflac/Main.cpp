/*
 ID: kareem_2
 PROG: calfflac
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

string findLongestPal(string source, int startIndex, int& palLength) {
	//	cout << "Start index " << startIndex << ", " << source[startIndex] << endl;
	palLength = 0;
	if (!isupper(source[startIndex]) && !islower(source[startIndex])) {
		return "";
	}

	int rightIndex = startIndex + 1;

	while ((rightIndex - startIndex <= 2000) && rightIndex < source.length()
			&& !isupper(source[rightIndex]) && !islower(source[rightIndex])) {
		rightIndex++;
	}

	if ((rightIndex - startIndex > 2000) || rightIndex == source.length()) {
		return "";
	}

	//	cout << "Right char: " << source[rightIndex] << endl;

	int leftIndex = startIndex;

	if (tolower(source[leftIndex]) != tolower(source[rightIndex])) {
		leftIndex--;
		while ((rightIndex - leftIndex <= 2000) && leftIndex >= 0 && !isupper(
				source[leftIndex]) && !islower(source[leftIndex])) {
			leftIndex--;
		}

		if ((rightIndex - leftIndex > 2000) || leftIndex < 0) {
			return "";
		}
	} else {
		//		cout << "Left char: " << source[leftIndex] << endl;
		palLength = 2;
	}

	if (tolower(source[leftIndex]) != tolower(source[rightIndex])) {
		return "";
	} else {
		palLength = 3;
		//		cout << "Left char: " << source[leftIndex] << endl;
	}
	while (true) {
		int nextRight = rightIndex + 1;
		while ((nextRight - leftIndex <= 2000) && nextRight < source.length()
				&& !isupper(source[nextRight]) && !islower(source[nextRight])) {
			nextRight++;
		}

		if ((nextRight - leftIndex > 2000) || nextRight == source.length()) {
			return source.substr(leftIndex, rightIndex - leftIndex + 1);
		}

		int nextLeft = leftIndex - 1;
		while ((nextRight - nextLeft <= 2000) && nextLeft >= 0 && !isupper(
				source[nextLeft]) && !islower(source[nextLeft])) {
			nextLeft--;
		}

		if ((nextRight - nextLeft > 2000) || nextLeft < 0) {
			return source.substr(leftIndex, rightIndex - leftIndex + 1);
		}

		if (tolower(source[nextLeft]) != tolower(source[nextRight])) {
			return source.substr(leftIndex, rightIndex - leftIndex + 1);
		}

		rightIndex = nextRight;
		leftIndex = nextLeft;
		palLength += 2;
	}
}

int main() {
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	string input = "";
	char line[90];
	fin.getline(line, 90);
	input.append(line);

	while (!fin.eof()) {
		fin.getline(line, 90);
		input.append("\n");
		input.append(line);
		//cout << input << endl;
	}

	//cout << input << endl;
	string longestPal = "";
	int maxLength = -1;

	for (int i = 0; i < input.length(); i++) {
		int palLength = 0;
		string pal = findLongestPal(input, i, palLength);
		if (palLength > maxLength) {
			maxLength = palLength;
			longestPal = pal;
		}
	}

	maxLength = 0;
	for (int i = 0; i < longestPal.length(); i++) {
		if (islower(longestPal[i]) || isupper(longestPal[i])) {
			maxLength++;
		}
	}
	fout << maxLength << endl;
	fout << longestPal << endl;

	return 0;
}
