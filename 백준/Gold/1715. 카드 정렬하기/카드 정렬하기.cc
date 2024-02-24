//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

#include<vector>
#include<queue>
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;

	priority_queue<int, vector<int>, cmp> pq;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		pq.push(x);
	}

	ll rt = 0;
	int sum;
	for (int i = 0; i < N - 1; i++) {
		sum = 0;
		sum += pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		rt += sum;
		pq.push(sum);
	}
	cout << rt;
	return 0;
}

