#include<iostream>
using namespace std;
#define endl "\n"
#include<queue>




int main() {
	int N;
	cin >> N;
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		Q.push(i);
	}
	for (int i = 0; i < N-1; i++) {
		Q.pop();
		auto tmp = Q.front();
		Q.pop();
		Q.push(tmp);
	}
	cout << Q.front();
	return 0;
}