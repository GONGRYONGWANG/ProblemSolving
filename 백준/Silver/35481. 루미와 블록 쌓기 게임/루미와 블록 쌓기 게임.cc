#include<bits/stdc++.h>
using namespace std;
 
bool board[20][10];
 
void solve(int tc) {
 
    for (int i = 19; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            char x; cin >> x;
            board[i][j] = (x == '#');
        }
    }
 
    int ret = 0;
    for (int i = 0; i < 19; i++) {
        int cnt = 0;
        for (int j = 0; j < 10; j++) {
            cnt += board[i][j];
        }
        if (cnt != 9) break;
        if (i < 10 && (board[i][i] || !board[i+1][i])) break;
        if (i >= 10 && (board[i][18 - i] || !board[i+1][18 - i])) break;
        ret += 1;
    }
 
    if (ret == 19) {
        cout << "GM";
        return;
    }
 
    if (ret == 0) {
        cout << "X";
        return;
    }
 
    if (ret <= 9) {
        cout << 10 - ret;
        return;
    }
 
    cout << "S" << ret - 9;
 
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
