//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

#include<vector>
#include<utility>
#include<queue>
#include<map>


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int K, N;
	cin >> K >> N;

	vector<ll> pn;
	ll x;
	for (int i = 0; i < K; i++) {
		cin >> x;
		pn.push_back(x);
	}

	map<ll, bool> ck;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	pq.push(1);
	ck[1] = 1;
	ll M = 1;
	for (int i = 0; i < N; i++) {
		ll num = pq.top();
		pq.pop();
		for (int j = 0; j < K; j++) {
			if (pq.size() > N && num * pn[j] > M) {
				break;
			}
			if (ck[num * pn[j]]) { continue; }
			else {
				pq.push(num * pn[j]);
				ck[num * pn[j]] = 1;
				if (M > pn[j] * num) {
					M = M;
				}
				else {
					M = pn[j] * num;
				}
			}
		}
	}
	cout << pq.top();

	return 0;
}
