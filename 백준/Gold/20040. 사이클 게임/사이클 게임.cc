#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<vector>
#include<utility>

int n , m;

int parent[500000];

int find(int x) {
	if (parent[x] == x) { return x; }
	parent[x] = find(parent[x]);
	return parent[x];
}

void merge(int a, int b) {
	if (find(a) == find(b)) { return; }
	parent[find(a)] = find(b);
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	vector<pair<int, int>> line;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		line.push_back({ a,b });
	}



	for (int i = 1; i <= m; i++) {
		a = line[i - 1].first;
		b = line[i - 1].second;
		if (find(a) == find(b)) {
			cout << i; return 0;
		}
		merge(a, b);
	}
	cout << 0;
	return 0;
}