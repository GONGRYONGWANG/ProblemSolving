#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll DP[101][10001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<tuple<ll, ll, ll>> arr(N);
    for (auto& [b, a, c] : arr) cin >> a >> b >> c;

    sort(arr.rbegin(), arr.rend());

    for (auto [b, a, c] : arr) {
        for (int i = N; i >= 1; i--) {
            for (int j = c; j <= M; j++) {
                DP[i][j] = max(DP[i][j], DP[i - 1][j - c] + a + b * (N - i));
            }
        }
    }

    ll ret = 0;
    for (int i = 1; i <= N; i++) {
        ret = max(ret, DP[i][M]);
    }

    cout << ret;
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