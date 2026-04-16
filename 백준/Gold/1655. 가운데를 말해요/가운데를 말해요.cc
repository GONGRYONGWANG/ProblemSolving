#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

// #1655 maxheap 하나 minheap 하나

#include<queue>
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;


int N;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	int num;
	maxheap.push(-10001);
	minheap.push(10001);
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num < maxheap.top()) {
			maxheap.push(num);
			minheap.push(maxheap.top());
			maxheap.pop();
		}
		else {
			minheap.push(num);
		}
		if (minheap.size() > maxheap.size()) {
			maxheap.push(minheap.top());
			minheap.pop();
		}
		cout << maxheap.top()<<endl;
	}
	return 0;
}
