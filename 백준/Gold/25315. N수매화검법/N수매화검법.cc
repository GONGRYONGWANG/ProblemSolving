//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}


int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll a = x1 * y2 + x2 * y3 + x3 * y1;
	ll b = y1 * x2 + y2 * x3 + y3 * x1;
	if (a < b) {
		return 1;
	}
	else return -1;
}

bool cross(pair<pair<ll,ll>, pair<ll, ll>> p1, pair<pair<ll, ll>, pair<ll, ll>> p2) {
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = p1.first.first;
	y1 = p1.first.second;
	x2 = p1.second.first;
	y2 = p1.second.second;
	x3 = p2.first.first;
	y3 = p2.first.second;
	x4 = p2.second.first;
	y4 = p2.second.second;
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {
		return 1;
	}
	else return 0;
}

#include<vector>
#include<utility>


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;

	ll result = 0;

	vector<pair<pair<ll, ll>, pair<ll, ll>>> line;
	vector<ll> weight;
	ll sx, sy, ex, ey , w;
	for (int i = 0; i < N; i++) {
		cin >> sx >> sy >> ex >> ey >> w;
		line.push_back({ {sx,sy},{ex,ey} });
		weight.push_back(w);
		result += w;
		for (int i = 0; i < line.size()-1; i++) {
			if (cross(line[line.size() - 1], line[i])) {
				result += min(weight[line.size() - 1], weight[i]);
			}
		}
	}
	cout << result;
	return 0;
}

