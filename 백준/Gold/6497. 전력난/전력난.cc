//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

#include<vector>
#include<utility>
#include<queue>

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	while (1) {
		ll m, n;
		cin >> m >> n;
		if (m == 0 && n == 0) {
			return 0;
		}
		ll ans = 0;
		vector<vector<pair<ll, ll>>> E(m);
		ll x, y, z;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			ans += z;
			E[x].push_back({ -z,y });
			E[y].push_back({ -z,x });

		}
		vector<bool> visited(m, 0);
		priority_queue < pair<ll, ll>, vector < pair < ll, ll >>> pq;
		pq.push({ 0,0 });
		while (!pq.empty()) {
			ll node = pq.top().second;
			ll cost = pq.top().first;
			pq.pop();
			if (visited[node]) {
				continue;
			}
			visited[node] = 1;
			ans += cost;
			for (int i = 0; i < E[node].size(); i++) {
				if (!visited[E[node][i].second]) {
					pq.push(E[node][i]);
				}
			}
		}
		cout << ans<<endl;
	}
	return 0;
}
