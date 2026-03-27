#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF ll(2e18)
 
 
ll DP[300001];
pll arr[300001];
void solve(int tc) {
 
    ll N, M, C;
    cin >> N >> M >> C;
 
    arr[0] = { 0,0 };
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second; // t,f
 
    for (int i = 1; i <= N; i++) {
        DP[i] = INF;
        ll mxt = arr[i].first; ll mxf = arr[i].second;
        for (int j = i - 1; j >= i - C && j >= 0; j--) {
            ll s = max(mxt, DP[j]);
            DP[i] = min(DP[i], s + (mxf - 1) * (1 + (i != N)));
            mxt = max(mxt, arr[j].first); mxf = max(mxf, arr[j].second);
        }
    }
 
    cout << DP[N];
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
 
    return 0;
}
