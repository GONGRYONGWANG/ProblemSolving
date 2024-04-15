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




//////////////////////////////////////////////////////////////////////////////////////


int board[20][20];
int visited[20][20];

void solve() {
    int N;
    cin >> N;
    pii s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                s = { i,j };
                board[i][j] = 0;
            }
        }
    }

    int sz = 2;
    int full = 0;
    int ans = 0;

    while (1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 0;
            }
        }

        queue<pii> q;
        q.push(s);
        visited[s.first][s.second] = 1;

        s = { inf,inf };
        int ret = inf;

        while (!q.empty()) {
            pii cur = q.front();
            int x = cur.first;
            int y = cur.second;
            q.pop();
            if (visited[x][y] > ret) continue;
            if (board[x][y] && board[x][y]<sz) {
                ret = visited[x][y];
                if (x < s.first || (x==s.first && y<s.second)) {
                    s = { x,y };
                }
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || board[nx][ny] > sz) continue;
                visited[nx][ny] = visited[x][y] + 1;
                q.push({ nx,ny });
            }
        }

        if (ret == inf) {
            break;
        }
        ans += ret - 1;
        full += 1;
        if (full == sz) {
            full = 0;
            sz += 1;
        }
        board[s.first][s.second] = 0;
    }

    cout << ans;


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
