#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<vector>
#include<utility>
#include<queue>
int N,M,X;
vector<pair<int, int>> line[1001];
vector<pair<int, int>> rline[1001];
int Distance[1001];
int rDistance[1001];
bool visit[1001];


struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second > b.second) { return true; }
		else return false;
	}
};

void dijkstra1() {
	for (int i = 0; i <= N; i++) {
		visit[i] = 0;
		Distance[i] = 0;
	}
	visit[X] = 1;

	priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> Q;
	for (int i = 0; i < line[X].size(); i++) {
		Q.push(line[X][i]);
	}
	int visited = 1;
	while (!Q.empty()&&visited!=N) {
		int node = Q.top().first;
		if (visit[node]) { Q.pop(); continue; }
		Distance[node] = Q.top().second;
		Q.pop();
		visit[node] = 1;
		visited++;
		for (int i = 0; i < line[node].size(); i++) {
			if (!visit[line[node][i]. first]) {
				Q.push({ line[node][i].first,line[node][i].second + Distance[node] });
			}
		}
	}
	return;
}
void dijkstra2() {
	for (int i = 0; i <= N; i++) {
		visit[i] = 0;
		rDistance[i] = 0;
	}
	visit[X] = 1;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;
	for (int i = 0; i < rline[X].size(); i++) {
		Q.push(rline[X][i]);
	}
	int visited = 1;
	while (!Q.empty() && visited != N) {
		int node = Q.top().first;
		if (visit[node]) { Q.pop(); continue; }
		rDistance[node] = Q.top().second;
		Q.pop();
		visit[node] = 1;
		visited++;
		for (int i = 0; i < rline[node].size(); i++) {
			if (!visit[rline[node][i].first]) {
				Q.push({ rline[node][i].first,rline[node][i].second + rDistance[node] });
			}
		}
	}
	return;

}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M >> X;
	int a, b, t;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		line[a].push_back({ b,t });
		rline[b].push_back({ a,t });
	}
	dijkstra1();
	dijkstra2();
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (Distance[i] + rDistance[i] > max) {
			max = Distance[i] + rDistance[i];
		}
	}
	cout << max;
	



	return 0;
}

