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

char board[1002][1002];
bool visited[1002][1002][2];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    queue<vector<int>> q;
    q.push({ 1,1,0,1 }); // x,y,break_num,time

    while (!q.empty()) {
        vector<int> qf = q.front();
        int x = qf[0]; int y = qf[1]; int bn = qf[2]; int t = qf[3];
        q.pop();
        if (x == 0 || x == N + 1 || y == 0 || y == M + 1) continue;
        if (x == N && y == M) {
            cout << t;
            return 0;
        }
        if (board[x][y] == '1') bn += 1;
        if (bn == 2) continue;
        if (visited[x][y][bn]||visited[x][y][0]) continue;
        visited[x][y][bn] = 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (visited[nx][ny][0]) continue;
            q.push({ nx, ny,bn,t + 1 });
        }
    }
    cout << -1;
    return 0;
}