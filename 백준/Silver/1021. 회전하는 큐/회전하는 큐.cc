#pragma warning(disable: 4996)
#include<iostream>
using namespace std;
#define endl "\n"


int deck[200];
int target[50];
int front;
int back;
int cnt;

void extract(int x) {
	if (target[x] - front <=  back - target[x]) {
		cnt += target[x] - front;
		back += target[x] - front;
		front += target[x] - front + 1;
	}
	else {
		cnt += back - target[x] + 1;
		front -= back - target[x];
		back -= back - target[x] + 1;
	}
	return;
}


int main() {
	int N, M;
	cin >> N >> M;
	front = 50;
	back = 50 + N - 1;
	cnt = 0;
	int tmp;
	
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		target[i] = front + tmp - 1;
	}
	for (int i = 0; i < M; i++) {
		extract(i);
		for (int j = i + 1; j < M; j++) {
			if (target[j] < front) {
				target[j] += back - front + 2;
			}
			else if (target[j] > back) {
				target[j] += front - back - 2;
			}
		}
	}
	cout << cnt;


	return 0;
}