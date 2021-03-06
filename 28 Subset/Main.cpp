/*
 ID: kareem_2
 PROG: subset
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef unsigned long long ull;

int main() {
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	int n;
	fin >> n;

	if (n % 4 == 0 || (n + 1) % 4 == 0) {
		int max = n * (n + 1) / 4;
		ull* ways = new ull[max + 1];
		vector<vector<int> >* subsets = new vector<vector<int> > [max + 1];
		ways[0] = 1;
		vector<int> temp;
		vector<vector<int> > temp2;
//		temp.insert(temp.end(), 0);
		subsets[0].insert(subsets[0].end(), temp);

		for (int i = 1; i <= max; i++) {
			ways[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			//			cout << i << endl;
			for (int j = max; j >= i; j--) {
				ways[j] += ways[j - i];
				temp2 = subsets[j - i];
				if (temp2.size() > 0) {
					cout << "j = " << j << endl;
				}
				for (size_t k = 0; k < temp2.size(); k++) {
					temp2[k].insert(temp2[k].end(), i);
					subsets[j].push_back(temp2[k]);
					for (size_t l = 0; l < temp2[k].size(); l++) {
						cout << temp2[k][l] << " ";
					}
					cout << endl;
				}
				//				cout << "j - " << j << ": " << ways[j] << endl;
			}
		}

		fout << (ways[max] / 2) << endl;
	} else {
		fout << "0" << endl;
	}

	return 0;
}
