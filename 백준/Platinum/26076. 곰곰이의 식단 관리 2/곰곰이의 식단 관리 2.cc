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

struct VectorHasher {
    int operator()(const vector<int>& V) const {
        int hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

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

int ccw(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////


int board[2002][2002];
pii con[2002][2002];

void solve() {

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i <= N + 1; i++) {
        board[i][0] = board[i][M + 1] = 1;
    }
    for (int j = 0; j <= M + 1; j++) {
        board[0][j] = board[N+1][j] = 1;
    }
    board[0][0] = board[1][0] = board[0][1] = 0;
    board[N + 1][M] = board[N][M + 1] = board[N + 1][M + 1] = 0;

    board[N + 1][0] = 2;
    board[0][M + 1] = 3;

    queue<pii> q;
    q.push({ N + 1,0 });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx<0 || nx>N + 1 || ny<0 || ny>M + 1) continue;

            if (board[nx][ny] == 0) con[nx][ny].first = 1;
            else if (board[nx][ny] == 1 || board[nx][ny] == 3) {
                board[nx][ny] = 2;
                q.push({ nx,ny });
            }
        }
    }

    if (board[0][M + 1] == 2) {
        cout << 0;
        return;
    }

    q.push({ 0,M + 1 });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx<0 || nx>N + 1 || ny<0 || ny>M + 1) continue;

            if (board[nx][ny] == 0) con[nx][ny].second = 1;
            else if (board[nx][ny] == 1) {
                board[nx][ny] = 3;
                q.push({ nx,ny });
            }
        }
    }

    bool ans = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] != 0) continue;
            if (i == 1 && j == 1)continue;
            if (i == N && j == M) continue;
            if (con[i][j] == make_pair(1, 1)) ans = true;
        }
    }

    cout << (ans ? 1 : 2);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
