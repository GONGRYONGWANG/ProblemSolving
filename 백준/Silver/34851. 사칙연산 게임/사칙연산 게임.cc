#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 
void solve(int tc) {
 
    int N;
    cin >> N;
 
    ll mod = 1e9 + 7;
    ll ret;
    cin >> ret;
 
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        if (x == 1 || (i == 0 && ret == 1)) {
            ret = (ret + x) % mod;
        }
        else {
            ret = ret * x % mod;
        }
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