#include<bits/stdc++.h>
using namespace std;

void solve(int tc) {


    int N, M, K;
    cin >> N >> M >> K;
    if (M <= N) cout << 1;
    else if (N == 1) cout << 2;
    else if (N == 2) {
        if (K > N + 1) cout << 3;
        else cout << 4;
    }
    else cout << 5;

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