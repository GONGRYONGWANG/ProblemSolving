#include<bits/stdc++.h>
using namespace std;


int DP[201][201];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N, a, b;
    cin >> N >> a >> b;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            DP[i][j] = 1e9;
        }
    }
    DP[0][0] = 0;
    while (N--) {
        int x, y;
        cin >> x >> y;
        for (int i = a; i >= 0; i--) {
            for (int j = b; j >= 0; j--) {
                DP[min(i + x, a)][min(j + y, b)] = min(DP[min(i + x, a)][min(j + y, b)], DP[i][j] + 1);
            }
        }
    }


    if (DP[a][b] == 1e9) cout << -1;
    else cout << DP[a][b];

    return 0;
}