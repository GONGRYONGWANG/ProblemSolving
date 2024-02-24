#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<stack>
#include<vector>
#include<string>

int N, Q;
int parent[200001];

int find(int x) {
	if (parent[x] == x) { return x; }
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	if (find(a) == find(b)) { return; }
	a = find(a); b = find(b);
	if (a < b) { parent[b] = a; }
	else parent[a] = b;
	return;
}

stack<vector<int>> S;
vector<bool> ans;


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> Q;
	parent[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin >> parent[i];
	}
	bool x;
	int b, c, d;
	for (int i = 0; i < N - 1 + Q; i++) {
		cin >> x;
		if (!x) {
			cin >> b;
			S.push({ x,b,parent[b] });
		}
		else {
			cin >> c >> d;
			S.push({ x,c,d });
		}
	}
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < N - 1 + Q; i++) {
		if (!S.top()[0]) {
			b = S.top()[1];
			c = S.top()[2];
			merge(b, c);
		}
		else {
			c = S.top()[1];
			d = S.top()[2]; 
			if (find(c) == find(d)) { ans.push_back(1); }
			else { ans.push_back(0); }
		}
		S.pop();
	}
	for (int i = Q-1; i >=0; i--) {
		if (ans[i] == 1) { cout << "YES"; }
		else { cout << "NO"; }
		cout << endl;
	}

	return 0;
}
