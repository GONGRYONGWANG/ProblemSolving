#include<iostream>
using namespace std;
#define endl "\n"
#define INF 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
int N;
vector<long long> tree[300001];


long long A = 0; //ㄷ
long long B = 0; //ㅈ



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	long long u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			A += (tree[i].size() - 1) * (tree[tree[i][j]].size() - 1);
		}
		B += tree[i].size() * (tree[i].size() - 1) * (tree[i].size() - 2) / 6;
	}
	A /= 2;
	if (A > 3 * B) { cout << "D"; }
	else if (A == 3 * B) { cout << "DUDUDUNGA"; }
	else { cout << "G"; }

	return 0;
}

