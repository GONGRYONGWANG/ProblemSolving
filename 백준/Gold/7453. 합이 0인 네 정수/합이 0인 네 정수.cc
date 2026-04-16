//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

#include<vector>
#include<algorithm>

int n;
vector<vector<long long>> arr(4);

vector<long long> AB;
vector<long long> CD;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	

	cin >> n;

	long long x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> x;
			arr[j].push_back(x);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(arr[0][i] + arr[1][j]);
			CD.push_back(arr[2][i] + arr[3][j]);
		}
	}

	sort(AB.rbegin(), AB.rend());
	sort(CD.begin(), CD.end());

	long long answer = 0;
	auto CD_iter_low = CD.begin();
	auto CD_iter_high = CD.begin();
	for (int i = 0; i < n * n; i++) {
		CD_iter_high = upper_bound(CD_iter_high, CD.end(), -AB[i]);
		CD_iter_low = lower_bound(CD_iter_low, CD.end(), -AB[i]);
		answer += CD_iter_high - CD_iter_low;
	}

	cout << answer;

	
	return 0;
}


