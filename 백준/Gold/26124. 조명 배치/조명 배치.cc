#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<cmath>



int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> bm(H+2);
	for (int i = 0; i < W + 2; i++) {
		bm[0].push_back(-1);
		bm[H + 1].push_back(-1);
	}
	int x;
	for (int i = 1; i < H+1; i++) {
		bm[i].push_back(-1);
		for (int j = 1; j < W+1; j++) {
			cin >> x;
			bm[i].push_back(x);
		}
		bm[i].push_back(-1);
	}

	int ans = 0;

	for (int i = 1; i < H + 1; i++) {
		for (int j = 1; j < W + 1; j++) {

			int cen, adjn, adjw, adje, adjs;
			cen = bm[i][j];
			adjn = bm[i - 1][j];
			adjs = bm[i + 1][j];
			adjw = bm[i][j - 1];
			adje = bm[i][j + 1];

			if (cen == -1) {
				continue;
			}

			if (adjn != -1) {
				adjn -= cen;
				if (adjn == 1) {
					continue;
				}
				else if (adjn != -1 && adjn !=0) {
					cout << -1;
					return 0;
				}
			}

			if (adjs != -1) {
				adjs -= cen;
				if (adjs == 1) {
					continue;
				}
				else if (adjs != -1 && adjs != 0) {
					cout << -1;
					return 0;
				}
			}

			if (adjw != -1) {
				adjw -= cen;
				if (adjw == 1) {
					continue;
				}
				else if (adjw != -1 && adjw != 0) {
					cout << -1;
					return 0;
				}
			}

			if (adje != -1) {
				adje -= cen;
				if (adje == 1) {
					continue;
				}
				else if (adje != -1 && adje != 0) {
					cout << -1;
					return 0;
				}
			}
			if (cen != 0) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}