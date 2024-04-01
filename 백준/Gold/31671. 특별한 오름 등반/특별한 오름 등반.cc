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

//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
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


//////////////////////////////////////////////////////////////////////////////////////



int N, M;
int DP[2001][1001];
int dp(int x, int y) {
    if (y<0 || y>x || x + y > 2 * N) return -1;
    if (DP[x][y]) return DP[x][y];
    if (x == 0 && y == 0) return 0;
    int ret = max(dp(x - 1, y - 1), dp(x - 1, y + 1));
    if (ret == -1) return DP[x][y] = -1;
    return DP[x][y] = max(ret, y);
}


void solve(){

    cin >> N >> M;

    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= N; j++) {

        }
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        DP[x][y] = -1;
    }
    cout << dp(2 * N, 0);

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

