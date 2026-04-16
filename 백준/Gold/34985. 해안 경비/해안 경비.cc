#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define endl "\n"

ll arr[200001];
ld psum[200000];

void solve(int tc) {
    ll W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i < N; i++) {
        ld d = arr[i + 1] - arr[i];
        psum[i] = d * d * H / (d + W) / 2 + psum[i - 1];
    }

    int Q;
    cin >> Q;
    cout << fixed;
    cout.precision(9);

    while (Q--) {
        int l, r;
        cin >> l >> r;
        r -= 1;
        cout << ld(W + arr[r + 1] - arr[l]) * H / 2 - (psum[r] - psum[l - 1]) << endl;
    }
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