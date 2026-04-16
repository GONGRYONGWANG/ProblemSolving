#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#define INF 1e8


int N, E;
int v1, v2;
vector<pair<int, int>> line[801];

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second > b.second) { return true; }
		else return false;
	}
};

int dijkstra(int begin, int end) {
	if (begin == end) { return 0; }
	int Distance[801];
	for (int i = 1; i <= N; i++) {
		Distance[i] = INF;
	}
	Distance[begin] = 0;
	bool visited[801];
	for (int i = 1; i <= N; i++) { visited[i] = 0; } 
	visited[begin] = 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;	

	for (int i = 0; i < line[begin].size(); i++) {
		Q.push(line[begin][i]);
	}

	while (!Q.empty() && !visited[end]) {
		int Node = Q.top().first;
		if (visited[Node]) { Q.pop(); continue; }
		Distance[Node] = Q.top().second;
		Q.pop();
		
		if (Node == end) { break; }

		visited[Node] = 1;


		for (int i = 0; i < line[Node].size(); i++) {
			if (!visited[line[Node][i].first]) {
				Q.push({ line[Node][i].first, line[Node][i].second + Distance[Node] });
			}
		}
	}
	return Distance[end];

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
	cin >> v1 >> v2;

	int result = min(dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N), dijkstra(1,v2)+dijkstra(v2,v1)+dijkstra(v1,N));
	if (result >= INF) { cout << -1; }
	else { cout << result; }
	return 0;

}