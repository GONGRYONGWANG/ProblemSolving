#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<algorithm>
int R, C;	
int map[20][20];
bool key[26];


int DFS(int x, int y) {
	if (key[map[x][y]] == 1) {
		return 0;
	}
	key[map[x][y]] = 1;
	int result = 0;
	if (x != 0) {
		result = max(result, DFS(x - 1, y));
	}
	if (x != R - 1) {
		result = max(result, DFS(x + 1, y));
	}
	if (y != 0) {
		result = max(result, DFS(x, y - 1));
	}
	if (y != C - 1) {
		result = max(result, DFS(x, y + 1));
	}
	key[map[x][y]] = 0;
	return result + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> R >> C;
	char x;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> x;
			map[i][j] = (int)x - 65;
		}
	}
	cout << DFS(0, 0);

	return 0;
}