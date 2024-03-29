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

ll fastpow(ll x, ll n, ll mod = INF) {
    if (n == 0) return 1;
    if (n % 2) return x * fastpow(x, n - 1, mod) % mod;
    ll half = fastpow(x, n / 2, mod);
    return half * half % mod;
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


char board[50][50];
int flood[50][50];
int visited[50][50];

void solve() {
    int R, C;
    cin >> R >> C;
    pii D;
    pii S;

    queue<pii> q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            
            flood[i][j] = inf;
            cin >> board[i][j];
            if (board[i][j] == 'S') D = { i,j };
            else if (board[i][j] == 'D') S = { i,j };
            else if (board[i][j] == '*') {
                q.push({ i,j});
                flood[i][j] = 1;
            }

        }
    }

    while (!q.empty()) {
        pii cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (flood[nx][ny] != inf) continue;
            if (board[nx][ny] == 'D') continue;
            if (board[nx][ny] == 'X') continue;
            flood[nx][ny] = flood[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    q.push(D);
    visited[D.first][D.second] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 'X') continue;
            if (flood[nx][ny] <= visited[x][y] + 1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({ nx,ny });
        }
    }

    if (visited[S.first][S.second] == 0) {
        cout << "KAKTUS";
    }
    else cout << visited[S.first][S.second] - 1;


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

