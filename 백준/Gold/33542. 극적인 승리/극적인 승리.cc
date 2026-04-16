#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int inf = 1e9 + 7;

void solve(int tc) {

	int A, B;
	cin >> A >> B;

	int N;
	cin >> N;
	vector<pii> arr(N + 1);
	pii ans = { -1,-1 };
	int ret = 1e9+7;
	map<int,int> L, R;
	L[0] = -1; R[0] = -1;
	for (int i = 1; i <= N; i++) {
		int l, r;
		cin >> l >> r;
		auto it = R.upper_bound(A - B - l);
		if (it != R.end() && B + l + it->first < ret) {
			ret = B + l + it->first;
			ans = { i,it->second };
		}
		it = L.upper_bound(A - B - r);
		if (it != L.end() && B + r + it->first < ret) {
			ret = B + r + it->first;
			ans = { it->second,i };
		}

		L[l] = i; R[r] = i;
	}

	if (B > A) {
		cout << "-1 -1";
		return;
	}

	if (ret == inf) cout << "No";
	else cout << ans.first << " " << ans.second;



}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	//cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		solve(tc);
	}
	return 0;
}