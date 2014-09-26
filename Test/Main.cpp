#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;

int convert(double x) {
	return round((pow(x / 255, 1 / 2.2) * 255));
}

int main(int argc, char **argv) {
	bool found[256];
	memset(found, 0, 256 * sizeof(bool));
	int total = 0;
	for (int x = 0; x < 256; x++) {
		int y = convert(x);
		cout << y << endl;
		if (!found[y]) {
			found[y] = true;
			total++;
		}
	}

	char *buf;

	buf = (char*) malloc(1 << 31);

	fgets(buf, 1024, stdin);
	printf("%s\n", buf);

	return 1;
}
