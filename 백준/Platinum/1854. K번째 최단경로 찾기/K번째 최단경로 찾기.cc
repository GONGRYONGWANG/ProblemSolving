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


struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> edge(n+1);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
	vector<vector<int>> route(n+1);

	pq.push({ 1,0 });

	while (!pq.empty()) {
		pair<int, int> node = pq.top();
		pq.pop();
		if (route[node.first].size() == k) {
			continue;
		}
		route[node.first].push_back(node.second);
		for (int i = 0; i < edge[node.first].size(); i++) {
			pq.push({ edge[node.first][i].first, edge[node.first][i].second + node.second });
		}
	}

	for (int i = 1; i <= n; i++) {
		if (route[i].size() == k) {
			cout << route[i][k-1] << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}

