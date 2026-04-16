//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

#include<queue>
#include<utility>
#include<vector>

struct cmp {
	bool operator()(pair<ll, ll>& a, pair<ll, ll>& b) {
		if (a.first * b.second == a.second * b.first) {
			return a.first > b.first;
		}
		else {
			return a.first * b.second > a.second * b.first;
		}
	}
};

ll min(ll x, ll y) {
	if (x < y) {
		return x;
	}
	else return y;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	ll N;
	ll M;
	cin >> N >> M;
	priority_queue<pair<ll, ll>, vector <pair<ll, ll>>, cmp > pq;
	ll w, v;
	for (ll i = 0; i < N; i++) {
		cin >> w >> v;
		pq.push({ w,v });
	}

	ll result = 0;

	while (M > pq.top().first && !pq.empty()) {
		result += pq.top().second;
		M -= pq.top().first;
		pq.pop();
	}

	if (M == 0 || pq.empty()) {
		cout << result<<"/1";
		return 0;
	}
	
	else { // M < pq.top().first && !pq.empty()
		ll a, b;
		a = pq.top().second * M;
		b = pq.top().first;
		for (ll i = min(a, b); i >1; i--) {
			if (a % i == 0 && b % i == 0) {
				a = a / i;
				b = b / i;
				break;
			}
		}
		cout << result * b + a << "/" << b;
		return 0;
	}

	//result + (pq.top().second*M/pq.top().first)


	return 0;
}

