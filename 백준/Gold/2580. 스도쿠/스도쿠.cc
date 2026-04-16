//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;


int board[9][9];
bool checkRow[9][10];
bool checkCol[9][10];
bool checkBox[9][10];

int findBox(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

void initializeBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			checkRow[i][board[i][j]] = 1;
			checkCol[j][board[i][j]] = 1;
			checkBox[findBox(i,j)][board[i][j]] = 1;
		}
	}
	return;
}

pair<int, int> findIndex(int idx) {
	return make_pair( idx / 9, idx%9 );
}

bool check(int num, pair<int, int> index) {
	int x = index.first; int y = index.second;
	if (checkRow[x][num] == 1) { return 0; }
	if (checkCol[y][num] == 1) { return 0; }
	if (checkBox[findBox(x, y)][num] == 1) { return 0; }
	return 1;
}

int putNum(int num, pair<int, int> index) {
	int x = index.first; int y = index.second;
	board[x][y] = num;
	checkRow[x][num] = 1;
	checkCol[y][num] = 1;
	checkBox[findBox(x, y)][num] = 1;

	return 1;
}

void removeNum(pair<int, int> index) {
	int x = index.first; int y = index.second;
	int num = board[x][y];
	board[x][y] = 0;
	checkRow[x][num] = 0;
	checkCol[y][num] = 0;
	checkBox[findBox(x, y)][num] = 0;
}

void printBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int fillBoard(int idx=0) {
	if (idx == 81) {
		return 1;
	}
	pair<int, int> index = findIndex(idx);
	if (board[index.first][index.second] != 0) { return fillBoard(idx + 1); }
	for (int i = 1; i <= 9; i++) {
		if (check(i, index)) {
			putNum(i, index);
			if (fillBoard(idx + 1)) {	
				return 1;
			}
			removeNum(index);
		}
		else continue;
	}
	return 0;
}



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	initializeBoard();
	fillBoard();
	printBoard();

	return 0;
}