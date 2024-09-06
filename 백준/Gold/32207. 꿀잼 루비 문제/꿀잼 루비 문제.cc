#include<bits/stdc++.h>
using namespace std;


vector<int> dx = { 0,0,1,-1 };
vector<int>dy = { 1,-1,0,0 };

bool visited[1000][1000];
vector<vector<int>> arr;
int N, M, K;
int bf(int n, int k) {
	if (n == 5 * K || n == N * M) return 0;
	if (k == 0) return bf(n + 1, k);
	int ret = bf(n + 1, k);
	int x = arr[n][1];
	int y = arr[n][2];
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir]; int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (visited[nx][ny]) return ret;
	}
	visited[x][y] = true;
	ret = max(ret, arr[n][0] + bf(n + 1, k-1));
	visited[x][y] = false;
	return ret;
}

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x;
			cin >> x;
			arr.push_back({ x,i,j });
		}
	}
	sort(arr.rbegin(), arr.rend());
	
	cout << bf(0, K);

	


}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T = 1;
	//cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}