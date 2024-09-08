#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int N, M, K;

vector<int> arr[1001][31];

vector<int> sf(vector<int>& v1, vector<int>& v2) {
	vector<int> ret(N);
	for (int i = 0; i < N; i++) {
		ret[i] = v2[v1[i]];
	}
	return ret;
}


void solve() {

	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			x -= 1;
			arr[i][0].push_back(x);
		}
		for (int j = 1; j <= 30; j++) {
			arr[i][j] = sf(arr[i][j - 1], arr[i][j - 1]);
		}
	}

	vector<int> ret(N);
	for (int i = 0; i < N; i++) {
		ret[i] = i;
	}

	while (K--) {
		int x, y;
		cin >> x >> y;
		int d = 0;
		while (y) {
			if (y % 2) {
				ret = sf(ret, arr[x][d]);
			}
			y /= 2;
			d += 1;
		}
	}


	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		ans[ret[i]] = i + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}




}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	while (T--) {
		solve();
	}


	return 0;
}