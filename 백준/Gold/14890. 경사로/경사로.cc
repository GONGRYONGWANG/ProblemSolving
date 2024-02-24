//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int board[100][100];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 2 * N;
    int cnt;
    for (int i = 0; i < N; i++) {
        cnt = 1;
        for (int j = 1; j < N; j++) {
            if (board[i][j] == board[i][j - 1]) {
                cnt++;
            }
            else if (board[i][j - 1] + 1 == board[i][j]) {
                if (cnt >= L) {
                    cnt = 1;
                    continue;
                }
                else {
                    ans -= 1; break;
                }
            }
            else if (board[i][j - 1] - 1 == board[i][j]) {
                if (j + L - 1 < N) {
                    bool x = 0;
                    for (int k = 0; k < L; k++) {
                        if (board[i][j] != board[i][j + k]) {
                            x = 1;
                            break;
                        }
                    }
                    if (x) {
                        ans -= 1; break;
                    }
                    cnt = 0;
                    j = j + L-1;
                    continue;
                }
                else {
                    ans -= 1; break;
                }
            }
            else {
                ans -= 1;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cnt = 1;
        for (int j = 1; j < N; j++) {
            if (board[j][i] == board[j-1][i]) {
                cnt++;
            }
            else if (board[j-1][i] + 1 == board[j][i]) {
                if (cnt >= L) {
                    cnt = 1;
                    continue;
                }
                else {
                    ans -= 1; break;
                }
            }
            else if (board[j-1][i] - 1 == board[j][i]) {
                if (j + L - 1 < N) {
                    bool x = 0;
                    for (int k = 0; k < L; k++) {
                        if (board[j][i] != board[j+k][i]) {
                            x = 1;
                            break;
                        }
                    }
                    if (x) {
                        ans -= 1; break;
                    }
                    cnt = 0;
                    j = j + L-1;
                    continue;
                }
                else {
                    ans -= 1; break;
                }
            }
            else {
                ans -= 1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}