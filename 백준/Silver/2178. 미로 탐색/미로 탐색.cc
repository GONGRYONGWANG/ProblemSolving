#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"


int N, M;
int Maze[100][100];
void DFS(int y, int x);
int main() {
	cin >> N >> M;
	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			if (tmp == '0') { Maze[i][j] = 0; }
			else Maze[i][j] = 10001;
		}
	}
	Maze[0][0] = 1;
	DFS(0,0);
	cout << Maze[N - 1][M - 1];
	return 0;
}

void DFS(int y, int x) {
	if (y != 0) {
		if (Maze[y - 1][x] > Maze[y][x] + 1) {
			Maze[y - 1][x] = Maze[y][x] + 1;
			DFS(y - 1, x);
		}
	}
	if (y != N - 1) {
		if (Maze[y + 1][x] > Maze[y][x] + 1) {
			Maze[y + 1][x] = Maze[y][x] + 1;
			DFS(y + 1, x);
		}
	}
	if (x != 0) {
		if (Maze[y][x-1] > Maze[y][x] + 1) {
			Maze[y][x-1] = Maze[y][x] + 1;
			DFS(y, x-1);
		}
	}
	if (x != M - 1) {
		if (Maze[y][x+1] > Maze[y][x] + 1) {
			Maze[y][x+1] = Maze[y][x] + 1;
			DFS(y, x+1);
		}
	}
	return;
}