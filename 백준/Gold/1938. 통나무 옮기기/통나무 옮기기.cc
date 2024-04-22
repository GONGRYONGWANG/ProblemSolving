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
#include<bitset>
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

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

const string debug = "output: ";

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

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) {
    return powmod(x, mod - 2, mod);
}

ll factorial(ll x) {
    ll ret = 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dx_[8] = { -1,-1,-1,0,0,1,1,1 };
int dy_[8] = { -1,0,1,-1,1,-1,0,1 };

//////////////////////////////////////////////////////////////////////////////////////

int N;
char board[50][50];

int visited[50][50][2];

void solve() {
    cin >> N;

    vector<int> s, e;
    int scnt = 0 , ecnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') {
                scnt += 1;
                if (scnt == 2) {
                    if (i != 0 && board[i - 1][j] == 'B') s = { i,j,0 };
                    else s = { i,j,1 };
                }
            }
            else if (board[i][j] == 'E') {
                ecnt += 1;
                if (ecnt == 2) {
                    if (i != 0 && board[i - 1][j] == 'E') e = { i,j,0 };
                    else e = { i,j,1 };
                }
            }
        }
    }

    visited[e[0]][e[1]][e[2]] = 1;
    queue<vector<int>> q;
    q.push(e);
    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        int x = cur[0];
        int y = cur[1];
        int r = cur[2];
        if (r == 0) {
            if (x == 0 || x == N - 1) continue;
            if (board[x - 1][y] == '1' || board[x + 1][y] == '1') continue;
        }
        else {
            if (y == 0 || y == N - 1) continue;
            if (board[x][y - 1] == '1' || board[x][y + 1] == '1') continue;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny][r]) continue;
            if (board[nx][ny] == '1') continue;
            visited[nx][ny][r] = visited[x][y][r] + 1;
            q.push({ nx,ny,r });
        }

        if (visited[x][y][(r + 1) % 2]) continue;

        bool b = true;
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx_[dir];
            int ny = y + dy_[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) b = false;
            if (board[nx][ny] == '1') b = false;
        }
        if(b){
            visited[x][y][(r + 1) % 2] = visited[x][y][r] + 1;
            q.push({ x,y,(r + 1) % 2 });
        }

    }

    if (visited[s[0]][s[1]][s[2]]) cout << visited[s[0]][s[1]][s[2]] - 1;
    else cout << 0;


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
