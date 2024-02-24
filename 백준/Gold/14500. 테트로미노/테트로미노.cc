//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int board[500][500];
int N, M;
bool visited[500][500];
int dfs(int x,int y,int t) {
    if (t == 0) return 0;
    if (visited[x][y]) return -1e9;
    visited[x][y] = 1;
    int ret = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir]; int ny = y + dy[dir];
        if (nx == -1 || nx == N || ny == -1 || ny == M) continue;
        if (visited[nx][ny]) continue;
        ret = max(ret, dfs(nx, ny, t - 1));
    }
    visited[x][y] = 0;
    return ret + board[x][y];
}

int tpol(int x, int y) {
    int ret = board[x][y];
    int minus = 1e9;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir]; int ny = y + dy[dir];
        int tmp;
        if (nx == -1 || nx == N || ny == -1 || ny == M) tmp = 0;
        else tmp = board[nx][ny];
        ret += tmp;
        minus = min(minus, tmp);
    }
    return ret - minus;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>board[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = max(dfs(i, j, 4),ans);
            ans = max(ans, tpol(i, j));
        }
    }
    cout << ans;
    return 0;
}