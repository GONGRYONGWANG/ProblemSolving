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

int N;
ll mod = 1e9;
ll DP[101][10][1024];
ll dp(int len, int s, int bit) {
    if (len == 1) {
        if (bit == 1023) return 1;
        else return 0;
    }
    if (DP[len][s][bit] != -1) return DP[len][s][bit];

    ll ret = 0;
    if (s != 0) {
        ret += dp(len - 1, s - 1, bit | (1 << (s - 1)));
    }
    if (s != 9) {
        ret += dp(len - 1, s + 1, bit | (1 << (s + 1)));
    }
    return DP[len][s][bit] = ret % mod;
}

void solve() {
    cin >> N;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 1024; k++) {
                DP[i][j][k] = -1;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp(N, i, (1<<i));
        ans %= mod;
    }
    cout << ans;
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