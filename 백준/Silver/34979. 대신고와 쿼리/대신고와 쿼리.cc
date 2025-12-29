#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int dx[5] = { -1,0,1,0,0 };
int dy[5] = { 0,1,0,-1,0 };

int board[1001][100001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			for (int dir = 0; dir < 5; dir++) {
				int nx = x + dx[dir]; int ny = y + dy[dir];
				if (nx <= 0 || nx > 4 || ny <= 0 || ny > N) continue;
				board[nx][ny] += 1;
			}
		}
		else {
			int x; cin >> x;
			int ret = N;
			for (int i = N; i >= 1; i--) {
				if (board[x][i] >= board[x][ret]) ret = i;
			}
			cout << ret << endl;
		}
	}

	int x = 4; int y = N;
	for (int i = 4; i >= 1; i--) {
		for (int j = N; j >= 1; j--) {
			if (board[i][j] >= board[x][y]) {
				x = i; y = j;
			}
		}
	}

	cout << x << " " << y;


	return 0;
}
