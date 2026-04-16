//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

int N, K;
#include<vector>
#include<algorithm>
vector<long long> cable;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	cin >> K>>N;
	cable.resize(K);

	long long low = 1;
	long long high = 1;

	for (int i = 0; i < K; i++) {
		cin >> cable[i];
		high = max(high, cable[i]);
	}

	long long result = 0;

	while (low <= high) {
		long long test_len = (low + high) / 2;
		long long cnt = 0;
		for(int i=0; i<K;i++){
			cnt += cable[i] / test_len;
		}
		if (cnt >= N) {
			result = max(result, test_len);
			low = test_len + 1;
		}
		else high = test_len - 1;
	}

	cout << result;

	return 0;
}


