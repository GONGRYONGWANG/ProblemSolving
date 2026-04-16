//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

ll DP[1001][1001];
ll mod = 1000000003;
ll dp(int n, int k) {
    if (DP[n][k] != -1) return DP[n][k];
    if (k == 0) return 1;
    if (k == 1) return n;

    if (n % 2 == 0) {
        if (k > n / 2) return 0;
    }
    else {
        if (k > n / 2 + 1) return 0;
        if (k == n / 2 + 1) return 1;
    }

    return DP[n][k] = (dp(n - 1, k) + dp(n - 2, k - 1)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            DP[i][j] = -1;
        }
    }
    cout << (dp(N - 3, K - 1) + dp(N - 1, K))%mod;
    return 0;
}