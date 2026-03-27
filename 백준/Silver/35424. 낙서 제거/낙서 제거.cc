#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
void solve(int tc) {
 
    ll N, K;
    cin >> N >> K;
 
    ll ret = 1;
    ll h = 0;
    ll l = N; ll r = 1;
    while (N--) {
        ll x; cin >> x;
        if ((h + 1) * (max(r, x) - min(l, x) + 1) > K) {
            ret += 1;
            h = 0; l = x; r = x;
        }
        h += 1; l = min(l, x); r = max(r, x);
    }
 
    cout << ret;
 
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
