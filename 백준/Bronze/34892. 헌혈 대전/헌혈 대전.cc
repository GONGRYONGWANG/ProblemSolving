#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int tc) {

    ll N, a, b, c, d, e, f, g, h;
    cin >> N >> a >> b >> c >> d >> e >> f >> g >> h;

    int cnt = 0;

    ll x, y, z;

    for (ll i = 0; i <= N; i++) {
        for (ll j = 0; i + j <= N; j++) {
            ll k = N - i - j;
            if (a * i + b * j + c * k != d) continue;
            if (e * i + f * j + g * k != h) continue;
            cnt += 1;
            x = i; y = j; z = k;
        }
    }

    if (cnt == 1) {
        cout << 0 << endl;
        cout << x << " " << y << " " << z;
    }
    else if (cnt == 0) cout << 2;
    else cout << 1;
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