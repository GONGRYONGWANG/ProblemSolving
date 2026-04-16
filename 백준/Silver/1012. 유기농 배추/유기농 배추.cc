#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define endl "\n"

int T, M, N, K;

bool BC[50][50];

void SET();
int CAL();
void summarize(int i, int j);

int main() {
	vector<int> v;
	cin >> T;
	for (int i = 0; i < T; i++) {
		SET();
		v.push_back(CAL());
	}
	for (int i = 0; i < T; i++) {
		cout << v[i] << endl;
	}

	return 0;
}

void SET() {
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			BC[i][j] = 0;
		}
	}
	int tmp1, tmp2;
	for (int i = 0; i < K; i++) {
		cin >> tmp1 >> tmp2;
		BC[tmp1][tmp2] = 1;
	}
}
int CAL() {
	int result = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (BC[i][j]) {
				result++;
				summarize(i, j);
			}
		}
	}
	return result;
}
void summarize(int i, int j) {
	if (!BC[i][j]) { return; }
	BC[i][j] = 0;
	if (i != 0) {
		summarize(i - 1, j);
	}
	if (i != M - 1) {
		summarize(i + 1, j);
	}
	if (j != 0) {
		summarize(i, j - 1);
	}
	if (j != N - 1) {
		summarize(i, j + 1);
	}
	return;
}
