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

int N;
vector<int> arr;
vector<int> ans;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr.push_back(x);
	}
	for (int i = 0; i < N; i++) {
		x = arr[i];
		if (ans.empty() || x > ans.back()) {
			ans.push_back(x);
		}
		else{
			auto iter = lower_bound(ans.begin(), ans.end(), x);
			*iter = x;
		}
	}
	cout << ans.size();
	return 0;
}
// #7453

