//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

char board[1001][1001];
bool visited[1001][1001][11];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    queue<vector<int>> q;
    q.push({ 1,1,1,0 }); // x,y,t,k
    while (!q.empty()) {
        int x, y, t, k;
        x = q.front()[0]; y = q.front()[1]; t = q.front()[2]; k = q.front()[3];
        q.pop();
        if (x == 0 || x == N + 1 || y == 0 || y == M + 1) continue;
        bool isvisited = 0;
        for (int i = 0; i <= k; i++) {
            if (visited[x][y][i]) {
                isvisited = 1; break;
            }
        }
        if (isvisited) continue;
        if (board[x][y] == '1') {
            if (t % 2 == 1) {
                q.push({ x,y,t + 1,k });
                continue;
            }
            visited[x][y][k] = 1;
            k += 1;
        }
        else visited[x][y][k] = 1;

        if (k == K + 1) continue;
        if (x == N && y == M) {
            cout << t; return 0;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            isvisited = 0;
            for (int i = 0; i <= k; i++) {
                if (visited[nx][ny][i]) {
                    isvisited = 1; break;
                }
            }
            if (isvisited) continue;
            q.push({ nx,ny,t + 1,k });
        }
    }

    cout << -1;
    return 0;
}