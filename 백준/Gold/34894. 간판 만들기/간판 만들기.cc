#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define INF ll(2e18)


void solve(int tc){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> arr(N);
    for (ll& x : arr) cin >> x;

    ll u = INF, o = INF, s = INF, p = INF, c = INF;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'U') u = min(u, arr[i]);
        else if (S[i] == 'O') o = min(o, u + arr[i]);
        else if (S[i] == 'S') s = min(s, o + arr[i]);
        else if (S[i] == 'P') p = min(p, s + arr[i]);
        else c = min(c, p + arr[i]);
    }

    if (c == INF) cout << -1;
    else cout << c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}