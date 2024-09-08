#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const int inf = 1e9 + 7;
typedef pair<long long, long long> pll;

vector<pll> d;
ll arr[500000];

void solve() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	d.resize(N);
	d[0] = { 0, arr[0] };

	for (ll i = 1; i < N; i++) {
		if (d[i-1].second == arr[i] + i) {
			d[i] = d[i - 1];
			continue;
		}
		if (d[i - 1].second < arr[i] + i) {
			d[i].first = d[i - 1].first + (arr[i] + i - d[i - 1].second) * i;
			d[i].second = arr[i] + i;
		}
		else {
			d[i] = d[i - 1];
			ll j = i;
			while (j != N && d[i - 1].second > arr[j] + j) {
				d[i].first += d[i - 1].second - j - arr[j];
				j += 1;
			}
			while (i != j-1) {
				i += 1;
				d[i] = d[i - 1];
			}
		}
	}

	ll total = 0;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 1) {
			ll x;
			cin >> x;
			total += x;
		}
		else {
			ll l = 0;
			ll r = N - 1;
			while (l < r) {
				ll m = (l + r + 1) / 2;
				if (d[m].first <= total) l = m;
				else r = m - 1;
			}
			if (l != N - 1 && d[l].second == d[l + 1].second) {
				cout << d[l].second << endl;
			}
			else cout << d[l].second + (total - d[l].first) / (l + 1) << endl;
		}
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