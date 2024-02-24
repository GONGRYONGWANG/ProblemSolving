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
#include<algorithm>
#include<queue>

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	int N;
	cin >> N;
	int s, t;
	vector<pair<int, int>> lectures;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		lectures.push_back({ s,t });
	}
	sort(lectures.begin(), lectures.end());
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(0);
	for (int i = 0; i < N; i++) {
		pair<int, int> lec = lectures[i];
		if (lec.first >= pq.top()) {
			pq.pop();
		}
		pq.push(lec.second);
	}
	cout << pq.size();
	return 0;
}

//#11000
