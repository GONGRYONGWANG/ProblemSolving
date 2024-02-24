#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<utility>
#include<queue>

int V, E;
int total;

vector<pair<int, int>> line[10001];
bool visited[10001];
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second > b.second) { return true; }
		else return false;
	}
};

void prim() {
	visited[1] = 1;
	int visit = 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;
	for (int i = 0; i < line[1].size(); i++) {
		Q.push(line[1][i]);
	}
	while (!Q.empty()) {
		int node = Q.top().first;
		if (visited[node]) { Q.pop(); continue; }
		visited[node] = 1;
		total += Q.top().second;
		visit++;
		if (visit == V) { return; }
		for (int i = 0; i < line[node].size(); i++) {
			if (!visited[line[node][i].first]) {
				Q.push(line[node][i]);
			}
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> V >> E;
	int A, B, C;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		line[A].push_back({ B,C });
		line[B].push_back({ A,C });
	}
	total = 0;
	prim();
	cout << total;

	return 0;
}

