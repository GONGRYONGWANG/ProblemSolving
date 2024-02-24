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
	int T;
	cin >> T;
	while (T--) {
		int M;
		cin >> M;
		priority_queue<int, vector<int>, less<int>> pq1;
		priority_queue<int, vector<int>, greater<int>> pq2;
		vector<int> ans;
		int x;
		cin >> x;
		ans.push_back(x);
		pq1.push(x);
		for (int i = 0; i < M / 2; i++) {
			cin >> x;
			if (x >= pq1.top()) {
				pq2.push(x);
			}
			else {
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(x);
			}

			cin >> x;
			if (x <= pq2.top()) {
				pq1.push(x);
			}
			else {
				pq1.push(pq2.top());
				pq2.pop();
				pq2.push(x);
			}
			ans.push_back(pq1.top());
		}
		cout << M / 2 + 1 << endl;
		int cnt = 0;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
			cnt++;
			if (cnt == 10) {
				cnt = 0;
				cout << endl;
			}
		}
		cout << endl;
	}

	

	return 0;
}
