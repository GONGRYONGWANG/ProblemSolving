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
#include<algorithm>

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	int d, p;
	vector<bool> booked(10001, 0);
	priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;

	for (int i = 0; i < N; i++) {
		cin >> p >> d;
		pq.push({ d,p });
	}

	int rt = 0;
	while (!pq.empty()) {
		int day = pq.top().first;
		int pay = pq.top().second;
		pq.pop();
		while (day!=0&&booked[day]) {
			day--;
		}
		if (day != 0) {
			booked[day] = 1;
			rt += pay;
		}
	}
	cout << rt;

	return 0;
}
