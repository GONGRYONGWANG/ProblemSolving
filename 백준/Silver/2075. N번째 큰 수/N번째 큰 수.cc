//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;


#include<queue>
#include<vector>

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	priority_queue<int,vector<int>,greater<int>> pq;
	int x;
	for(int i=0; i<N;i++){
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			pq.push(x);
			pq.pop();
		}
	}
	cout << pq.top();


	return 0;
}

