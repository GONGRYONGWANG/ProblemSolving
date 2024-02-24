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



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	if (N == 1) {
		cout << 0;
		return 0;
	}
	priority_queue<int> pq;
	int d;
	cin >> d;
	for (int i = 1; i < N; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	int ans = 0;
	while (d+ans <= pq.top()) {
		ans++;
		int x = pq.top();
		pq.pop();
		pq.push(x - 1);
	}
	cout << ans;
	
	return 0;
}
