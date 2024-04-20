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
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

//////////////////////////////////////////////////////////////////////////////////////



char board[100][100];
int toexit[100][100];
int from1[100][100];
int from2[100][100];

void solve() {
    int N, M;
    cin >> N >> M;

    deque<pii> exit, f1, f2;
    pii s1, s2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            toexit[i][j] = from1[i][j] = from2[i][j] = -1;
            char x;
            cin >> x;
            board[i][j] = x;
            if (x == '*') continue;
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                if (x == '#') {
                    toexit[i][j] = 1;
                    exit.push_back({ i,j });
                }
                else {
                    toexit[i][j] = 0;
                    exit.push_front({ i,j });
                }

            }
            if (x == '$') {
                if (f1.empty()) {
                    from1[i][j] = 0;
                    f1.push_back({ i,j });
                    s1 = { i,j };
                }
                else {
                    from2[i][j] = 0;
                    f2.push_back({ i,j });
                    s2 = { i,j };
                }
            }
        }
    }

    while (!exit.empty()) {
        pii cur = exit.front();
        int x = cur.first;
        int y = cur.second;
        exit.pop_front();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '*') continue;
            if (toexit[nx][ny] != -1) continue;

            if (board[nx][ny] == '#') {
                toexit[nx][ny] = toexit[x][y] + 1;
                exit.push_back({ nx,ny });
            }
            else {
                toexit[nx][ny] = toexit[x][y];
                exit.push_front({ nx,ny });
            }
        }
    }

    while (!f1.empty()) {
        pii cur = f1.front();
        int x = cur.first;
        int y = cur.second;
        f1.pop_front();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '*') continue;
            if (from1[nx][ny] != -1) continue;

            if (board[nx][ny] == '#') {
                from1[nx][ny] = from1[x][y] + 1;
                f1.push_back({ nx,ny });
            }
            else {
                from1[nx][ny] = from1[x][y];
                f1.push_front({ nx,ny });
            }
        }
    }


    while (!f2.empty()) {
        pii cur = f2.front();
        int x = cur.first;
        int y = cur.second;
        f2.pop_front();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '*') continue;
            if (from2[nx][ny] != -1) continue;

            if (board[nx][ny] == '#') {
                from2[nx][ny] = from2[x][y] + 1;
                f2.push_back({ nx,ny });
            }
            else {
                from2[nx][ny] = from2[x][y];
                f2.push_front({ nx,ny });
            }
        }
    }


    int ans = toexit[s1.first][s1.second] + toexit[s2.first][s2.second];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '*') continue;
            if (from1[i][j] == -1 || from2[i][j] == -1 || toexit[i][j] == -1) continue;
            int ret = from1[i][j] + from2[i][j] + toexit[i][j];
            if (board[i][j] == '#') ret -= 2;
            ans = min(ans, ret);
        }
    }

    cout << ans << endl;

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
