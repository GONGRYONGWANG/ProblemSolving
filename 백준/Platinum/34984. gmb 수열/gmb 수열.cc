#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> cnt(301, 0);
    vector<vector<ll>> DP(301, vector<ll>(301, 0));
    ll ret = 0;
    ll mod = 1e9 + 7;
    while (N--) {
        int x; cin >> x;
        for (int i = 0; i <= 300 - x; i++) {
            ret += DP[i + x][i];
            ret %= mod;
            DP[i][x] += DP[i + x][i];
            DP[i][x] %= mod;
        }
        for (int i = 0; i <= 300; i++) {
            DP[i][x] += cnt[i];
            DP[i][x] %= mod;
        }
        cnt[x] += 1;
    }

    cout << ret;

    return 0;

}