#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

/*
int COMB[100][100];
int comb(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;
    if (COMB[n][r]) return COMB[n][r];
    return COMB[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}
*/

//////////////////////////////////////////////////////////////////////////////////////

int board[5][5];
bool visited[5][5][64];

void solve() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    int r, c ,t, key;
    cin >> r >> c;
    t = 0;
    key = 0;
    if (board[r][c] < 7 && board[r][c]>0) {
        key |= (1 << (board[r][c] - 1));
    }
    queue<vector<int>> q;
    q.push({ r,c,0,key });
    visited[r][c][key] = true;
    while (!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        int x = node[0];
        int y = node[1];
        int t = node[2];
        int k = node[3];

        if (k == 63) {
            cout << t;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx, ny, nk;
            nx = x + dx[dir];
            ny = y + dy[dir];
            nk = k;
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || board[nx][ny]==-1) continue;
            if (board[nx][ny] < 7 && board[nx][ny]>0) {
                nk |= (1 << (board[nx][ny] - 1));
            }
            if (visited[nx][ny][nk]) continue;
            visited[nx][ny][nk] = true;
            q.push({ nx,ny,t + 1,nk });
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx, ny, nk;
            nx = x;
            ny = y;
            nk = k;
            while (nx + dx[dir] >= 0 && nx + dx[dir] < 5 && ny + dy[dir] >= 0 && ny + dy[dir] < 5 && board[nx][ny]!=7 && board[nx + dx[dir]][ny + dy[dir]] != -1) {
                nx += dx[dir];
                ny += dy[dir];
            }
            if (board[nx][ny] < 7 && board[nx][ny]>0) {
                nk |= (1 << (board[nx][ny] - 1));
            }
            if (visited[nx][ny][nk]) continue;
            visited[nx][ny][nk] = true;
            q.push({ nx,ny,t + 1,nk });
        }
    }
    cout << -1;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }

    return 0;
}