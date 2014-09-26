/*
 ID: kareem_2
 PROG: castle
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int m, n;
int** castle;
int** castleRooms;

int exploreCastle(int currentRoom, int startRow, int startColumn) {

	castleRooms[startRow][startColumn] = -1;
	int foundModules = 1;
	int roomSize = 0;

	do {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (castleRooms[i][j] == -1) {
					castleRooms[i][j] = currentRoom;
					roomSize++;
					foundModules--;
					if ((castle[i][j] & 1) == 0 && castleRooms[i][j - 1] == -2) {
						castleRooms[i][j - 1] = -1;
						foundModules++;
					}

					if ((castle[i][j] & 2) == 0 && castleRooms[i - 1][j] == -2) {
						castleRooms[i - 1][j] = -1;
						foundModules++;
					}

					if ((castle[i][j] & 4) == 0 && castleRooms[i][j + 1] == -2) {
						castleRooms[i][j + 1] = -1;
						foundModules++;
					}

					if ((castle[i][j] & 8) == 0 && castleRooms[i + 1][j] == -2) {
						castleRooms[i + 1][j] = -1;
						foundModules++;
					}
				}
			}
		}
	} while (foundModules > 0);

	return roomSize;
}

int main() {
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	fin >> m >> n;
	castle = new int*[n];
	castleRooms = new int*[n];

	for (int i = 0; i < n; i++) {
		castle[i] = new int[m];
		castleRooms[i] = new int[m];
		for (int j = 0; j < m; j++) {
			fin >> castle[i][j];
			castleRooms[i][j] = -2;
		}
	}

	int currentRoom = 0;
	int maxRoom = 0;
	vector<int> roomSizes;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (castleRooms[i][j] == -2) {
				currentRoom++;
				int roomSize = exploreCastle(currentRoom, i, j);
				maxRoom = (maxRoom > roomSize) ? maxRoom : roomSize;
				roomSizes.insert(roomSizes.end(), roomSize);
			}
		}
	}

	fout << currentRoom << endl;
	fout << maxRoom << endl;
	//	for (int i = 0; i < n; i++) {
	//		for (int j = 0; j < m; j++) {
	//			fout << castleRooms[i][j] << " ";
	//		}
	//		fout << endl;
	//	}

	int maxCombined = 0;
	int wallRow;
	int wallColumn;
	char wallPosition;
	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if ((i > 0) && (castleRooms[i][j] != castleRooms[i - 1][j])
					&& (roomSizes[castleRooms[i][j] - 1]
							+ roomSizes[castleRooms[i - 1][j] - 1]
							> maxCombined)) {
				maxCombined = roomSizes[castleRooms[i][j] - 1]
						+ roomSizes[castleRooms[i - 1][j] - 1];
				wallRow = i;
				wallColumn = j;
				wallPosition = 'N';
			}

			if ((j < (m - 1)) && (castleRooms[i][j] != castleRooms[i][j + 1])
					&& (roomSizes[castleRooms[i][j] - 1]
							+ roomSizes[castleRooms[i][j + 1] - 1]
							> maxCombined)) {
				maxCombined = roomSizes[castleRooms[i][j] - 1]
						+ roomSizes[castleRooms[i][j + 1] - 1];
				wallRow = i;
				wallColumn = j;
				wallPosition = 'E';
			}
		}
	}

	fout << maxCombined << endl << wallRow + 1 << " " << wallColumn + 1 << " "
			<< wallPosition << endl;
	return 0;
}
