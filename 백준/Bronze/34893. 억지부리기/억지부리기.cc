#include<bits/stdc++.h>
using namespace std;

void solve(int tc) {

    long long a, b, c;
    cin >> a >> b >> c;

    long long ret;
    if (a > c) {
        ret = c + (a - c) / 3;
    }
    else {
        ret = a;
    }

    cout << min(ret, b);
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