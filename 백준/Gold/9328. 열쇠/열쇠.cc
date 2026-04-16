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

char board[104][104];
vector<pii> k[26];

bool con[104][104];
bool visited[104][104];
int ans;
int key;


void solve() {
    int H, W;
    cin >> H >> W;
    for (int i = 0; i <= H + 3; i++) {
        for (int j = 0; j <= W + 3; j++) {
            con[i][j] = 0;
        }
    }

    for (int i = 0; i <= H + 3; i++) {
        board[i][0] = board[i][W + 3] = '*';
        visited[i][0] = visited[i][W + 3] = 1;
    }
    for (int j = 0; j <= W + 3; j++) {
        board[0][j] = board[H + 3][j] = '*';
        visited[0][j] = visited[H + 3][j] = 1;
    }
    for (int i = 1; i <= H + 2; i++) {
        board[i][1] = board[i][W + 2] = '.';
        visited[i][1] = visited[i][W + 2] = 0;
    }
    for (int j = 1; j <= W + 2; j++) {
        board[1][j] = board[H + 2][j] = '.';
        visited[1][j] = visited[H + 2][j] = 0;
    }

    for (int i = 0; i < 26; i++) {
        k[i].clear();
    }

    for (int i = 2; i < H + 2; i++) {
        for (int j = 2; j < W + 2; j++) {
            cin >> board[i][j];
            if ((int)board[i][j] >= 65 && (int)board[i][j] <= 90) {
                k[(int)board[i][j] - 65].push_back({ i,j });
            }
            visited[i][j] = 0;
            if (board[i][j] == '*') visited[i][j] = 1;
        }
    }

    

    ans = 0;
    key = 0;
    string keys;
    cin >> keys;
    if (keys !="0") {
        for (int i = 0; i < keys.size(); i++) {
            key |= 1 << ((int)keys[i] - 97);
        }
    }

    queue<pii> q;
    q.push({ 1,1 });
    con[1][1] = 1;
    while (!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        int t = (int)board[x][y];
        q.pop();
        if (visited[x][y]) continue; // *
        if (!con[x][y]) continue;
        if (t >= 65 && t<= 90) { // ABCD
            if (!(key & (1<<(t-65)))) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                con[nx][ny] = 1;
                if (!visited[nx][ny]) {
                    q.push({ nx,ny });
                }
            }
        }
        else if (board[x][y] == '.') { // .
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                con[nx][ny] = 1;
                if (!visited[nx][ny]) {
                    q.push({ nx,ny });
                }
            }
        }
        else if (board[x][y]=='$'){ // $
            ans += 1;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                con[nx][ny] = 1;
                if (!visited[nx][ny]) {
                    q.push({ nx,ny });
                }
            }
        }
        else { // abcd
            key |= 1<<(t-97);
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                con[nx][ny] = 1;
                if (!visited[nx][ny]) {
                    q.push({ nx,ny });
                }
            }
            for (int i = 0; i < k[t - 97].size(); i++) {
                if (!visited[k[t - 97][i].first][k[t - 97][i].second]) {
                    q.push(k[t - 97][i]);
                }
            }
        }
        visited[x][y] = 1;
    }
    cout << ans<<endl;
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