//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int H, W;
char board[1002][1002];
int fm[1002][1002];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[1002][1002];
int sx, sy;
void solve() {
    cin >> W >> H;
    queue<vector<int>> q;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> board[i][j];
            visited[i][j] = 0;
            fm[i][j] = inf;
            if (board[i][j] == '*') {
                q.push({ 0,i,j });
            }
            if (board[i][j] == '#') visited[i][j] = 1;
            if (board[i][j] == '@') {
                sx = i; sy = j;
            }
        }
    }
    while (!q.empty()) {
        vector<int> v = q.front();
        int t = v[0]; int x = v[1]; int y = v[2];
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = 1;
        if (x == H + 1 || x == 0 || y == W + 1 || y == 0) {
            continue;
        }
        fm[x][y] = t;
        for (int i = 0; i < 4; i++) {
            q.push({ t + 1,x + dx[i],y + dy[i] });
        }
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            visited[i][j] = 0;
            if (board[i][j] == '#') visited[i][j] = 1;
        }
    }
    q.push({ 0,sx,sy });
    while (!q.empty()) {
        vector<int> v = q.front();
        int t = v[0]; int x = v[1]; int y = v[2];
        q.pop();
        if (x == H + 1 || x == 0 || y == W + 1 || y == 0) {
            cout << t<<endl; return;
        }
        if (visited[x][y]) continue;
        visited[x][y] = 1;
        if (fm[x][y] <= t) continue;
        for (int i = 0; i < 4; i++) {
            q.push({ t + 1,x + dx[i],y + dy[i] });
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}