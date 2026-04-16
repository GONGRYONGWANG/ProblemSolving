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
#include<utility>

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	int d, w;
	vector<bool> booked(1001,0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		pq.push({ d,w });
	}
	int rt = 0;

	while (!pq.empty()) {
		int idx = pq.top().first;
		int val = pq.top().second;

		while (booked[idx]) {
			idx--;
		}
		if (idx != 0) {
			booked[idx] = 1;
			rt += val;
		}
		pq.pop();
	}
	cout << rt;
	return 0;
}

