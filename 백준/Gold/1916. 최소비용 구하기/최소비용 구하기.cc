#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

// #1753
/*
* 문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다.
둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다.
이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다.
서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
*/
#include<vector>
#include<utility>
#include<queue>
#define INF 1e9

int V, E;
int root;
int Distance[20001];
bool visited[20001];
vector<pair<int, int>> line[20001];


struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second > b.second) { return true; }
		else return false;
	}
};




void dijkstra() {
	int visit = 0;
	Distance[root] = 0;
	visited[root] = 1;
	visit++;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;
	for (int i = 0; i < line[root].size(); i++) {
		Q.push(line[root][i]);
	}
	while (!Q.empty() && visit != V) {
		int Node = Q.top().first;
		if (visited[Node]) { Q.pop(); continue; }
		Distance[Node] = Q.top().second;
		Q.pop();
		visited[Node] = 1;
		visit++;
		for (int i = 0; i < line[Node].size(); i++) {
			if (!visited[line[Node][i].first]) {
				Q.push({ line[Node][i].first, line[Node][i].second + Distance[Node] });
			}
		}
	}
	return;
}

int f;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> V >> E;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		line[u].push_back({ v,w });
	}
	cin >> root>>f;
	dijkstra();
	cout << Distance[f];

	
	return 0;
}