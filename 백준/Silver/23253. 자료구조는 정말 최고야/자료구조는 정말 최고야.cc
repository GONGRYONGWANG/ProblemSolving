#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int nxt[200001];
bool avail[200001];
void solve() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int k;
		cin >> k;
		int prv, cur;
		cin >> prv;
		for (int i = 0; i < k - 1; i++) {
			cin >> cur;
			nxt[cur] = prv;
			prv = cur;
		}
		avail[prv] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (!avail[i]) {
			cout << "No";
			return;
		}
		avail[nxt[i]] = true;
	}
	cout << "Yes" << endl;



}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL);
	int T = 1;
	//cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}