#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>

int T;

int N, K;
int D[1001];
int C[1001];

int construct(int x, vector<int> precon[1001]) {
	if (C[x] != -1) { return C[x]; }
	if (precon[x].size() == 0) { 
		C[x] = D[x];
		return D[x]; 
	}
	int result = 0;
	int tmp;
	for (int i = 0; i < precon[x].size(); i++) {
		tmp = construct(precon[x][i],precon);
		if (tmp > result) {
			result = tmp;
		}
	}
	return C[x] = result + D[x];
}


void Test() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		C[i] = -1;
	}
	vector<int> precon[1001];
	int a, b;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		precon[b].push_back(a);
	}
	int W;
	cin >> W;
	cout << construct(W , precon) << endl;

	return;

}











int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		Test();
	}
	return 0;
}



