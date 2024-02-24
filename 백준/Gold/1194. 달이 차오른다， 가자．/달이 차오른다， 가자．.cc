#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

// #1194

#include<queue>
#include<utility>
#include<vector>

int N, M;
char map[50][50];
bool visited[50][50][(1 << 7) - 1];

void BFS(int sx, int sy) {
	queue<vector<int>> Q, P;
	Q.push({ sx,sy,0});
	int cnt = 0;
	while (1) {
		if (Q.empty()) {
			if (P.empty()) { cout << -1; return; }
			while (!P.empty()) {
				Q.push(P.front());
				P.pop();
			}
			cnt++;
		}
		int x = Q.front()[0];
		int y = Q.front()[1];
		int key = Q.front()[2];
		visited[x][y][key] = 1;
		Q.pop();


		if (map[x][y] == '1') { cout << cnt; return; } // Exit

		if ((int)map[x][y] >= 97 && (int)map[x][y] <= 102 && !(key & (1 << ((int)map[x][y] - 97)))) { // Key
			key |= (1 << ((int)map[x][y] - 97));
		}

		
		if (x + 1 >= N || x + 1 < 0 || y >= M || y < 0) {}  // Outofrange
		else if (map[x + 1][y] == '#') {} // Wall
		else if ((int)map[x + 1][y] >= 65 && (int)map[x + 1][y] <= 70 && !(key & (1 << ((int)map[x + 1][y] - 65)))) {} // Door
		else if (!visited[x + 1][y][key]) {
			P.push({ x + 1,y,key,2 });
			visited[x+1][y][key] = 1;
		}
		

		if (x - 1 >= N || x - 1 < 0 || y >= M || y < 0) {}
		else if (map[x - 1][y] == '#') {}
		else if ((int)map[x - 1][y] >= 65 && (int)map[x - 1][y] <= 70 && !(key & (1 << ((int)map[x - 1][y] - 65)))) {}
		else if (!visited[x - 1][y][key]) {
			P.push({ x - 1,y,key,0 });
			visited[x-1][y][key] = 1;
		}
		
		
		if (x >= N || x < 0 || y + 1 >= M || y + 1 < 0) {}
		else if (map[x][y + 1] == '#') {}
		else if ((int)map[x][y + 1] >= 65 && (int)map[x][y + 1] <= 70 && !(key & (1 << ((int)map[x][y + 1] - 65)))) {}
		else if (!visited[x][y + 1][key]) {
			P.push({ x,y + 1,key,3 });
			visited[x][y+1][key] = 1;
		}

		if (x >= N || x < 0 || y - 1 >= M || y - 1 < 0) {}
		else if (map[x][y - 1] == '#') {}
		else if ((int)map[x][y - 1] >= 65 && (int)map[x][y - 1] <= 70 && !(key & (1 << ((int)map[x][y - 1] - 65)))) {}
		else if (!visited[x][y - 1][key]) {
			P.push({ x,y - 1,key,1 });
			visited[x][y-1][key] = 1;
		}
	}

	return;
}




int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	int sx = 0;
	int sy = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') { sx = i; sy = j; }
		}
	}




	BFS(sx, sy);


	return 0;
}