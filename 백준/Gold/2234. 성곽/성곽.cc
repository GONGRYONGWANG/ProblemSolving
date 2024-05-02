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

/////////////////////////////////////////////////////////////////////////////////////


int sz[50][50];
pii parent[50][50];

pii findp(int x, int y) {
    if (parent[x][y] == make_pair(x, y)) return { x,y };
    return parent[x][y] = findp(parent[x][y].first, parent[x][y].second);
}

void mer(pii a, pii b) {
    a = findp(a.first, a.second);
    b = findp(b.first, b.second);
    parent[b.first][b.second] = a;
}


void solve() {
    int N, M;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            parent[i][j] = { i,j };
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            if ((x & 1) == 0) {
                mer({ i,j }, { i,j - 1 });
            }
            if ((x & 2) == 0) {
                mer({ i,j }, { i - 1, j });
            }
            if ((x & 4) == 0) {
                mer({ i,j }, { i,j + 1 });
            }
            if ((x & 8) == 0) {
                mer({ i,j }, { i + 1,j });
            }
        }
    }
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (findp(i, j) == make_pair(i, j)) num += 1;
            sz[findp(i, j).first][findp(i, j).second] += 1;
        }
    }
    cout << num << endl;

    int mxsz = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mxsz = max(mxsz, sz[findp(i, j).first][findp(i, j).second]);
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (findp(i, j) == findp(nx, ny)) continue;
                ans = max(ans, sz[findp(i, j).first][findp(i, j).second] + sz[findp(nx, ny).first][findp(nx, ny).second]);
            }
        }
    }
    cout << mxsz << endl;
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
