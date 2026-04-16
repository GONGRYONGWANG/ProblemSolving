#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<queue>

priority_queue<int>	box;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	int c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		box.push(c);
	}
	int tmpD;
	for (int i = 0; i < M; i++) {
		cin >> c;
		tmpD = box.top();
		if (tmpD < c) {
			cout << 0; return 0;
		}
		box.pop();
		box.push(tmpD - c);
	}
	cout << 1;



	return 0;
}


