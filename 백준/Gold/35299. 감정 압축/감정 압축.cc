#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
 
int arr[76];
 
int DP[80][40][40][2][11];
 
void solve(int tc) {
 
    string s;
    cin >> s;
    int K;
    cin >> K;
 
    int N = s.length() / 2;
    K /= 2;
 
    for (int i = 1; i <= N; i++) {
        arr[i] = (s[2 * i - 1] == ')');
    }
 
    for (int i = 1; i <= N; i++) {
        for (int a = 0; a <= K + 1; a++) {
            for (int b = 0; b <= K + 1; b++) {
                for (int x = 0; x < 2; x++) {
                    for (int y = 1; y <= 10; y++) {
                        DP[i][a][b][x][y] = inf;
                    }
                }
            }
        }
    }
 
    DP[1][1][1 + arr[1]][0][1] = 2;
    DP[1][1 + !arr[1]][1][1][1] = 2;
 
    for (int i = 2; i <= N; i++) {
        for (int a = 1; a <= K + 1; a++) {
            for (int b = 1; b <= K + 1; b++) {
                for (int x = 0; x < 2; x++) {
 
                    for (int prvx = 0; prvx < 2; prvx++) {
                        for (int prvy = 1; prvy <= 10; prvy++) {
                            DP[i][a][b][x][1] = min(DP[i][a][b][x][1], DP[i - 1][a - (x & !arr[i])][b - (!x & arr[i])][prvx][prvy] + 2);
                        }
                    }
 
                    DP[i][a][b][x][2] = DP[i - 1][a - (x & !arr[i])][b - (!x & arr[i])][x][1] + 1;
 
                    for (int y = 3; y <= 9; y++) {
                        DP[i][a][b][x][y] = DP[i - 1][a - (x & !arr[i])][b - (!x & arr[i])][x][y - 1];
                    }
 
                    DP[i][a][b][x][10] = min(DP[i - 1][a - (x & !arr[i])][b - (!x & arr[i])][x][9] + 1, DP[i - 1][a - (x & !arr[i])][b - (!x & arr[i])][x][10]);
 
 
                }
            }
        }
    }
 
    int ret = inf;
    for (int a = 1; a <= K + 1; a++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 1; y <= 10; y++) {
                ret = min(ret, DP[N][a][a][x][y]);
            }
        }
    }
 
    cout << ret;
 
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
