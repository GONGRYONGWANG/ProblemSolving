#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int Board[15];
bool CheckDiagonal1[30];
bool CheckDiagonal2[60];

int NQueen(int N, int idx) {
	if (idx == N) { return 1; }
	int result=0;
	for (int i = 0; i < N; i++) {
		if (Board[i] == N && CheckDiagonal1[i + idx] == 0 && CheckDiagonal2[30 + i - idx] == 0) {
			Board[i] = idx;
			CheckDiagonal1[i + idx] = 1;
			CheckDiagonal2[30 + i - idx] = 1;
			result += NQueen(N, idx + 1);
			Board[i] = N;
			CheckDiagonal1[i + idx] = 0;
			CheckDiagonal2[30 + i - idx] = 0;
		}
	}
	return result;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 15; i++) {
		Board[i] = N;
		CheckDiagonal1[i] = 0;
		CheckDiagonal1[i + 15] = 0;
		CheckDiagonal2[i] = 0;
		CheckDiagonal2[i + 15] = 0;
		CheckDiagonal2[i + 30] = 0;
		CheckDiagonal2[i + 45] = 0;
	}
	
	cout << NQueen(N,0);
	return 0;
}