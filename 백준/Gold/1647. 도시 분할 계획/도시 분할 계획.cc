#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<vector>
#include<utility>
#include<queue>
#include<algorithm>

vector<pair<int, int>> line[100001];



int N, M;
int result;
int MAX;
bool visited[100001];

struct cmp {
	bool operator()(pair<int,int> a,pair<int,int> b) {
		if (a.second > b.second) {
			return true;
		}
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
	while (!Q.empty() && visit != N) {
		int node = Q.top().first;
		if (visited[node]) { Q.pop(); continue; }
		result += Q.top().second;
		MAX = max(MAX, Q.top().second);
		Q.pop();
		visited[node] = 1;
		visit++;
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
	cin >> N >> M;
	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		line[A].push_back({ B,C });
		line[B].push_back({ A,C });
	}
	result = 0;
	MAX = 0;
	prim();
	cout << result-MAX;







	return 0;
}

