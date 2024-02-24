#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#define INF 1e9+1


int N, E;
vector<pair<int, int>> line[10001];

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second < b.second) { return true; }
		else return false;
	}
};

bool visited[10001];
int dijkstra(int begin, int end, int flow) {
	visited[begin] = 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;
	for (int i = 0; i < line[begin].size(); i++) {
		Q.push({ line[begin][i].first, min(flow, line[begin][i].second) });
	}
	while (!Q.empty() && !visited[end]) {
		int node = Q.top().first;
		flow = Q.top().second;
		if (node == end) { return flow; }
		visited[node] = 1;
		Q.pop();
		for (int i = 0; i < line[node].size(); i++) {
			if (!visited[line[node][i].first]) {
				Q.push({ line[node][i].first, min(flow, line[node][i].second) });
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		line[a].push_back({ b,c });
		line[b].push_back({ a,c });
	}
	int s, e;
	cin >> s >> e;

	cout << dijkstra(s, e, INF);
	return 0;

}