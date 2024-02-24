#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>

int N, M,k;
int cost[10001];
vector<int> network[10001];
int parent[10001];
bool visited[10001];

int find(int x) {
	if (parent[x] == x) { return x; }
	parent[x] = find(parent[x]);
	return parent[x];
}

void merge(int a, int b) {
	if (parent[a] == parent[b]) {
		return;
	}
	if (cost[find(a)] < cost[find(b)]) {
		parent[find(b)] = find(a);
	}
	else {
		parent[find(a)] = find(b);
	}
	return;
}



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		parent[i] = i;
	}
	int f1, f2;
	for (int i = 0; i < M; i++) {
		cin >> f1 >> f2;
		merge(f1, f2);
	}
	int total = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[find(i)]) {
			total += cost[find(i)];
			visited[find(i)] = 1;
		}
	}
	if (total > k) {
		cout << "Oh no";
	}
	else {
		cout << total;
	}

	return 0;
}