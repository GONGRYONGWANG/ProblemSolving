#include <iostream>
using namespace std;

int Recoloring(char smallBoard[8][8], char ChessBoard[8][8]);
void printBoard(char Board[8][8]);
void LargeprintBoard(char Board[50][50]);


int main() {
	char ChessBoard[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0 && j % 2 == 1) { ChessBoard[i][j] = 'B'; }
			else if (i % 2 == 1 && j % 2 == 0) { ChessBoard[i][j] = 'B'; }
			else{ ChessBoard[i][j] = 'W'; }
		}
	}

	char LargeBoard[50][50];
	int N, M;
	cin >> N>> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> LargeBoard[i][j];
		}
	}

	int MIN = 8 * 8;
	int recoloring;
	char smallBoard[8][8];
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			for (int ii = 0; ii < 8; ii++) {
				for (int jj = 0; jj <  8; jj++) {
					smallBoard[ii][jj] = LargeBoard[i+ii][j+jj];
				}
			}
			recoloring = Recoloring(smallBoard, ChessBoard);
			if (recoloring < MIN) { MIN = recoloring; }
		}
	}
	cout << MIN;
}

int Recoloring(char smallBoard[8][8], char ChessBoard[8][8]) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (smallBoard[i][j] != ChessBoard[i][j]) { result++; }
		}
	}
	if (result > 32) {
		result = 64 - result;
	}
	
	return result;
	
}

void printBoard(char Board[8][8]) {
	for (int i = 0; i < 8;i++) {
		for (int j = 0; j < 8; j++) {
			cout << Board[i][j];
		}
		cout << "\n";
	}
}

void LargeprintBoard(char Board[50][50]) {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cout << Board[i][j];
		}
		cout << "\n";
	}
}