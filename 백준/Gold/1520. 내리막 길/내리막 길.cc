#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"

int M, N;
int MAP[500][500];
long long DP[500][500];

long long dp(int y, int x) {
	if (DP[y][x] != -1) { return DP[y][x]; }

	int result = 0;

	if (y != 0 && MAP[y][x] > MAP[y - 1][x]) {
		result += dp(y - 1, x);
	}
	if (y != M - 1 && MAP[y][x] > MAP[y + 1][x]) {
		result += dp(y + 1, x);
	}
	if (x != 0 && MAP[y][x] > MAP[y][x - 1]) {
		result += dp(y, x - 1);
	}
	if (x != N - 1 && MAP[y][x] > MAP[y][x + 1]) {
		result += dp(y, x + 1);
	}
	DP[y][x] = result;

	return result;
}
int main(){
	
	cin >> M >> N;


	int tmp;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			DP[i][j] = -1;
			cin >> tmp;
			MAP[i][j] = tmp;
		}
	}
	DP[M - 1][N - 1] = 1;

	cout << dp(0, 0);


	return 0;
}