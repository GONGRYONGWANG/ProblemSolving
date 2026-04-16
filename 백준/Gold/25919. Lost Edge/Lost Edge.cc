#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


int map[102][102];
bool area[102][102];

int N, M;
int L, E, K;
void level(int x) {
	E += x;
	if (E >= L) {
		E -= L;
		L++;
	}
}

bool explore() {
	bool updated = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!area[i][j]) { continue; }
			if (!area[i + 1][j]) {
				int x = map[i + 1][j];
				if (x==0) {
					area[i + 1][j] = 1;
					updated = true;
				}
				else if(x>0) {
					if (L > x) {
						level(x);
						area[i + 1][j] = 1;
						updated = 1;
						map[i + 1][j] = 0;
					}
				}
			}

			if (!area[i - 1][j]) {
				int x = map[i - 1][j];
				if (x == 0) {
					area[i - 1][j] = 1;
					updated = true;
				}
				else if(x>0){
					if (L > x) {
						level(x);
						area[i - 1][j] = 1;
						updated = 1;
						map[i - 1][j] = 0;
					}
				}
			}
			if (!area[i][j+1]) {
				int x = map[i][j+1];
				if (x == 0) {
					area[i][j+1] = 1;
					updated = true;
				}
				else if(x>0){
					if (L > x) {
						level(x);
						area[i][j+1] = 1;
						updated = 1;
						map[i][j+1] = 0;
					}
				}
			}
			if (!area[i][j-1]) {
				int x = map[i][j-1];
				if (x == 0) {
					area[i][j-1] = 1;
					updated = true;
				}
				else if(x>0){
					if (L > x) {
						level(x);
						area[i][j-1] = 1;
						updated = 1;
						map[i][j-1] = 0;
					}
				}
			}
		}
	}
	if (updated) { return 1; }
	else return 0;
}

#include<utility>
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	cin >> L >> E >> K;

	for (int i = 0; i <= N + 1; i++) {
		map[i][0] = -1;
		map[i][M + 1] = -1;
	}
	for (int i = 0; i <= M + 1;i++) {
		map[0][i] = -1;
		map[N + 1][i] = -1;
	}
	pair<int, int> start;
	pair<int, int> raid;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == -3) {
				start = { i,j };
			}
			if (map[i][j] == -2) {
				raid = { i,j };
			}
		}
	}
	area[start.first][start.second] = 1;

	bool ex = 1;
	while (ex) {
		ex = explore();
	}

	if (L < K) {
		cout << "X";
		return 0;
	}

	if (!area[raid.first + 1][raid.second] 
		&& !area[raid.first - 1][raid.second] 
		&& !area[raid.first][raid.second + 1] 
		&& !area[raid.first][raid.second - 1]) {
		cout << "X";
		return 0;
	}
	
	cout << "O";

	
	


	return 0;
}

