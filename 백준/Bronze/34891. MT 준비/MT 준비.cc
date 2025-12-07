#include<bits/stdc++.h>
using namespace std;

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    
    cout << (N + M - 1) / M;
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