#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve(int tc) {
    ll x, y, p, a, b;
    cin >> x >> y >> p >> a >> b;
    cout << (2 * p + 2 * b * (y - 1) - a * (x - 1)) * x / 2;
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