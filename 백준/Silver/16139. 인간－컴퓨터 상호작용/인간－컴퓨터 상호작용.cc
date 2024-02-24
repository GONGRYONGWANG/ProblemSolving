#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
#define inf 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<vector>
#include<utility>
#include<algorithm>
#include<string>



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


	string S;
	cin >> S;
	
	vector<vector<int>> dp(S.length());
	dp[0].resize(26, 0);
	dp[0][int(S[0]) - 97] += 1;
	for (int i = 1; i < S.length(); i++) {
		dp[i] = dp[i - 1];
		dp[i][int(S[i]) - 97] += 1;
	}
	int q;
	cin >> q;
	char a;
	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> a >> l >> r;
		int ans = dp[r][int(a) - 97];
		if (l != 0) {
			ans -= dp[l-1][int(a) - 97];
		}
		cout << ans<<endl;
	}
	
	return 0;
}

