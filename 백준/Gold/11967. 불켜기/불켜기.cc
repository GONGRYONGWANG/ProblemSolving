//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int N, M;

bool board[101][101];
bool lighted[101][101];
bool visited[101][101];
vector<pii> sw[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int x, y, a, b;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        sw[x][y].push_back({ a,b });
    }

    board[1][1] = 1;
    lighted[1][1] = 1;
    queue<pii> q;
    q.push({ 1,1 });
    int nx, ny;
    while (!q.empty()) {
        x = q.front().first; y = q.front().second;
        q.pop();
        if (x == 0 || x == N + 1 || y == 0 || y == N + 1) continue;
        if (visited[x][y]) continue;
        if (board[x][y] && lighted[x][y]) {
            visited[x][y] = 1;
            for (int i = 0; i < sw[x][y].size(); i++) {
                nx = sw[x][y][i].first; ny = sw[x][y][i].second;
                if (visited[nx][ny]) continue;
                lighted[nx][ny] = 1;
                q.push({ nx,ny });
            }
            for (int i = 0; i < 4; i++) {
                nx = x + dx[i]; ny = y + dy[i];
                if (visited[nx][ny]) continue;
                board[nx][ny] = 1;
                q.push({ nx,ny});
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (lighted[i][j]) {
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}
