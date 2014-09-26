#include <fstream>
using namespace std;
int Ig = 0;
int Vg = 0;
int Xg = 0;
int Lg = 0;
int Cg = 0;
int Dg = 0;
int Mg = 0;

inline void roman(int x) {
	int I = 0;
	int V = 0;
	int X = 0;
	int L = 0;
	int C = 0;
	int D = 0;
	int M = 0;
	for (; x >= 1000; ++M, x -= 1000)
		;
	for (; x >= 500; ++D, x -= 500)
		;
	for (; x >= 100; ++C, x -= 100)
		;
	for (; x >= 50; ++L, x -= 50)
		;
	for (; x >= 10; ++X, x -= 10)
		;
	for (; x >= 5; ++V, x -= 5)
		;
	for (; x >= 1; ++I, x -= 1)
		;

	while (D > 0 && (C / 4) > 0) {
		--D;
		C -= 4;
		++M;
		++C;
	}
	while (C >= 4) {
		C -= 4;
		++D;
		++C;
	}
	while (L > 0 && (X / 4) > 0) {
		--L;
		X -= 4;
		++C;
		++X;
	}
	while (X >= 4) {
		X -= 4;
		++L;
		++X;
	}
	while (V > 0 && (I / 4) > 0) {
		--V;
		I -= 4;
		++X;
		++I;
	}
	while (I >= 4) {
		I -= 4;
		++V;
		++I;
	}
	Ig += I;
	Vg += V;
	Xg += X;
	Lg += L;
	Cg += C;
	Dg += D;
	Mg += M;
	return;
}

int main() {

	int n;
	ifstream filein("preface.in");
	filein >> n;
	filein.close();

	for (int loop = 1; loop <= n; ++loop) {
		roman(loop);
	}

	ofstream fileout("preface.out");
	if (Ig != 0) {
		fileout << 'I' << ' ' << Ig << endl;
	}
	if (Vg != 0) {
		fileout << 'V' << ' ' << Vg << endl;
	}
	if (Xg != 0) {
		fileout << 'X' << ' ' << Xg << endl;
	}
	if (Lg != 0) {
		fileout << 'L' << ' ' << Lg << endl;
	}
	if (Cg != 0) {
		fileout << 'C' << ' ' << Cg << endl;
	}
	if (Dg != 0) {
		fileout << 'D' << ' ' << Dg << endl;
	}
	if (Mg != 0) {
		fileout << 'M' << ' ' << Mg << endl;
	}
	fileout.close();

	return (0);
}
