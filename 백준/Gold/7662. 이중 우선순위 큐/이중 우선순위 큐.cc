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
#include<utility>

struct cmp2 {
	bool operator()(pair<int, int> a, pair<int, int>b) {
		return a.first > b.first;
	}
};
struct cmp1 {
	bool operator()(pair<int, int> a, pair<int, int>b) {
		return a.first < b.first;
	}
};

void RUN() {
	int k;
	cin >> k;
	vector<bool> poped;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1>  pq1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2>  pq2;
	int idx = 0;
	char c;
	int x;
	pair<int, int> a;
	for (int i = 0; i < k; i++) {
		cin >> c >> x;

		if (c == 'I') {
			poped.push_back(0);
			pq1.push({ x,idx });
			pq2.push({ x,idx });
			idx++;
		}

		else {
			if (x == 1) {
				while (!pq1.empty()) {
					a = pq1.top();
					pq1.pop();
					if (!poped[a.second]) {
						poped[a.second] = 1;
						break;
					}
				}
			}
			else {
				while (!pq2.empty()) {
					a = pq2.top();
					pq2.pop();
					if (!poped[a.second]) {
						poped[a.second] = 1;
						break;
					}
				}
			}
		}
	}

	while (!pq1.empty()) {
		a = pq1.top();
		if (!poped[a.second]) {
			break;
		}
		pq1.pop();
	}
	if (pq1.empty()) {
		cout << "EMPTY" << endl;
		return;
	}
	cout << a.first<<" ";
	while (!pq2.empty()) {
		a = pq2.top();
		if (!poped[a.second]) {
			break;
		}
		pq2.pop();
	}
	cout << a.first<<endl;
	return;
}





int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		RUN();
	}
	return 0;
}

