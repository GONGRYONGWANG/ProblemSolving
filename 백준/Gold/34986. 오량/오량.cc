#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

ll comb[2001][2001];
ll mod = 1e9 + 7;

void solve(int tc) {

    if (tc == 1) {
        for (int i = 0; i <= 2000; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
            }
        }
    }

    int N;
    cin >> N;
    bool flag = false;
    ll ret = 1;
    int n = N;
    while (N--) {
        int x; cin >> x;
        flag |= (x != 1);
        ret = (ret * comb[n][x]) % mod;
        n -= x;
    }

    if (!flag) ret = 1;
    cout << ret << endl;

    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}