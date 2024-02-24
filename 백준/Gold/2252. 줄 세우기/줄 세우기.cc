#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>

int N, M;
bool isinline[32001];
vector<int> precon[32001];

void setinline(int x) {
	for (int i = 0; i < precon[x].size(); i++) {
		if (!isinline[precon[x][i]]) {
			setinline(precon[x][i]);
		}
	}
	isinline[x] = 1;
	cout << x << " ";
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		precon[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (!isinline[i]) {
			setinline(i);
		}
	}


	return 0;
}


