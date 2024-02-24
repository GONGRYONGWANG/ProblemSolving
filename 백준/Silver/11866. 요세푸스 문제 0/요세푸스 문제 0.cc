#include<iostream>
using namespace std;
#define endl "\n"
#include<queue>

vector<int> jp;
queue<int> circle;
void JP(int n, int k) {
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < k - 1; i++) {
			auto tmp = circle.front();
			circle.pop();
			circle.push(tmp);
		}
		jp.push_back(circle.front());
		circle.pop();
	}
	return;
}



int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		circle.push(i);
	}
	JP(N, K);
	cout << "<";
	for (int i = 0; i < N-1; i++) {
		cout << jp[i] << ", ";;
	}
	cout << jp[N - 1] << ">";
	return 0;
}


