#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<utility>
pair<int,int> parent[100001];
int weight[100001];
pair<int,int> find(int x) {
	if (parent[x].first == x) { return parent[x]; }
	auto p = parent[x];
	return parent[x] = { find(p.first).first, find(p.first).second + p.second };
}
void merge(int a, int b , int w) {
	if (find(a) == find(b)) { return; }
	parent[parent[a].first] = { parent[b].first, parent[b].second - parent[a].second - w};
	return;
}

int N, M;

void TEST() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	for (int i = 1; i <= N; i++) {
		parent[i] = { i,0 };
	}
	char x;
	int a, b, w;
	for (int i = 0; i < M; i++) {
		cin >> x;
		if (x == '!') {
			cin >> a >> b >> w;
			merge(a, b, w);
		}
		else {
			cin >> a >> b;
			if (find(a).first == find(b).first) {
				cout << find(b).second - find(a).second << endl;
			}
			else {
				cout << "UNKNOWN" << endl;
			}
		}
	}


	return;
}


int main() {
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) { return 0; }
		TEST();
	}
	return 0;
}
