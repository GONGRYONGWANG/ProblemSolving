#include<iostream>
using namespace std;
#define endl "\n"
#include<queue>

int P[10];

void solve() {
	for (int i = 0; i < 10; i++) {
		P[i] = 0;
	}
	int N, M;
	cin >> N >> M;
	queue<int> Q;
	int priority;
	for (int i = 0; i < N; i++) {
		cin >> priority;
		P[priority]++;
		Q.push(priority);
	}
	int count = 0;
	while (1) {
		bool state = 0;
		int fp = Q.front();
		for (int i = fp+1; i < 10; i++) {
			if (P[i] > 0) {
				if (M == 0) {
					M = Q.size() - 1;
				}
				else { M--; }
				Q.pop();
				Q.push(fp);
				state = 1;
				break;
			}
		}
		if (state == 0) {
			count++;
			if (M == 0) {
				cout << count << endl;
				return;
			}
			P[Q.front()]--;
			Q.pop();
			M--;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
	return 0;
}