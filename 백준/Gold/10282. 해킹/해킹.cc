#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	

	int T;
	cin >> T;
	while (T--) {
		int n, d, c;
		cin >> n >> d >> c;
		vector<vector<pair<int, int>>> dc(n+1);
		int a, b, s;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			dc[b].push_back({ a,s });
		}

		vector<bool> vst(n+1, 0);
		


		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

		pq.push({ c,0 });

	
		int time;
		while (!pq.empty()) {
			int node, cost;
			node = pq.top().first;
			cost = pq.top().second;
			pq.pop();
			if (vst[node]) { continue; }
			vst[node] = true;
			time = cost;
			for (int i = 0; i < dc[node].size(); i++) {
				if (!vst[dc[node][i].first]) {
					pq.push({ dc[node][i].first, dc[node][i].second + cost });
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n+1; i++) {
			if (vst[i]) { cnt++; }
		}
		cout << cnt << " " << time << endl;
	}
	return 0;
}

