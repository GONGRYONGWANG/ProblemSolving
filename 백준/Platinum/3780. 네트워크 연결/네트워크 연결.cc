#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<utility>
#include<cmath>

pair<int, int> parent[200001];

pair<int, int> find(int x) {
	if (parent[x].first == x) { return parent[x]; }
	int w = parent[x].second;
	return parent[x] = { find(parent[x].first).first, find(parent[x].first).second+ w};
}

void merge(int a, int b) {
	parent[a] = { find(b).first,find(b).second+abs(a-b)%1000 };
	return;
}


int N;

void TEST() {
	cin >> N;
	
	for (int i = 0; i <= N; i++) {
		parent[i] = { i,0 };
	}
	char x;
	int a, b;
	while (1) {
		cin >> x;
		if (x == 'O') { return; }
		if (x == 'I') {
			cin >> a >> b;
			merge(a, b);
		}
		else {
			cin >> a;
			cout << find(a).second << endl;
		}
	}
	



	return;
}






int T;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		TEST();
	}
	return 0;
}
