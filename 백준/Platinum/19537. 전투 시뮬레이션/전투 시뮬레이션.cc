#include<iostream>
using namespace std;
#define endl "\n"
#define INF 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<vector>
int N,H,W;
int M;
int map[500][500];
int rough[10];
int unitmap[500][500];
vector<int> unit[62501];
int K;
bool startmove = 1;

int visited[500][500];

bool isbattle(int y, int x, int t) {
	if (y < H-1 && unitmap[y + 1][x] != -1 && unitmap[y + 1][x] != t) {
		return 1;
	}
	if (y > 0 && unitmap[y - 1][x] != -1 && unitmap[y - 1][x] != t) {
		return 1;
	}
	if (x < W-1 && unitmap[y][x + 1] != -1 && unitmap[y][x + 1] != t) {
		return 1;
	}
	if (x > 0 && unitmap[y][x - 1] != -1 && unitmap[y][x - 1] != t) {
		return 1;
	}
	return 0;
}

bool reach(int y, int x, int a, int b, int t, int m) {
	if (visited[y][x] >= m) { return 0; }
	if (m < 0) { return 0; }
	if (y == a && x == b) { return 1; }
	if (m == 0) { return 0; }

	if (unitmap[y][x] != -1 && unitmap[y][x] != t) { return 0; }

	if (!startmove && isbattle(y, x, t)) { return 0; }
	startmove = 0;

	visited[y][x] = m;

	if (y < H - 1 && rough[map[y + 1][x]]!=-1&& reach(y + 1, x, a, b, t, m - rough[map[y + 1][x]])) {
		return 1;
	}
	if (y > 0 && rough[map[y - 1][x]] != -1 && reach(y - 1, x, a, b, t, m - rough[map[y - 1][x]])) {
		return 1;
	}
	if (x < W - 1 && rough[map[y][x + 1]] != -1 && reach(y, x + 1, a, b, t, m - rough[map[y][x + 1]])) {
		return 1;
	}
	if (x > 0 && rough[map[y][x - 1]] != -1 && reach(y, x - 1, a, b, t, m - rough[map[y][x - 1]])) {
		return 1;
	}
	return 0;
}

void rush(int u, int a, int b) {
	int m = unit[u][0];
	int t = unit[u][1];
	int y = unit[u][2];
	int x = unit[u][3];
	if (unitmap[a][b] != -1) { return; }
	if (rough[map[a][b]] == -1){ return; }
	startmove = 1;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			visited[i][j] = -1;
		}
	}

	if (reach(y, x, a, b, t, m)) {
		unit[u][2] = a;
		unit[u][3] = b;
		unitmap[y][x] = -1;
		unitmap[a][b] = t;
	}

	return;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	cin >> N >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			unitmap[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> rough[i];
	}

	cin >> M;
	int m, t, a, b;
	for (int i = 1; i <= M; i++) {
		cin >> m >> t >> a >> b;
		unit[i] = { m,t,a,b };
		unitmap[a][b] = t;
	}

	cin >> K;
	int u;
	for (int i = 0; i < K; i++) {
		cin >> u >> a >> b;
		rush(u, a, b);
	}

	for (int i = 1; i <= M; i++) {
		cout << unit[i][2] << " " << unit[i][3] << endl;
	}

	return 0;
}

