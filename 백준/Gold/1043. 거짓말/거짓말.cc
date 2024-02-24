#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>

int parent[51];

int find(int x) {
	if (parent[x] == x) { return x; }
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	if (find(a) == find(b)) { return; }
	a = find(a);
	b = find(b);
	parent[a] = b;
	return;
}



int N,M;
vector<int> meeting[50];
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	int k;
	cin >> k;
	int p;
	for (int i = 0; i < k; i++) {
		cin >> p;
		merge(p, 0);
	}
	
	int p0;
	for (int i = 0; i < M; i++) {
		cin >> k;
		if (k != 0) { cin >> p0; meeting[i].push_back(p0); }
		for (int j = 1; j < k; j++) {
			cin >> p;
			merge(p, p0);
			meeting[i].push_back(p);
		}
	}

	int ans = M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < meeting[i].size(); j++) {
			if (find(0) == find(meeting[i][j])) {
				ans--;
				break;
			}
		}
	}

	cout << ans;




	return 0;

}
