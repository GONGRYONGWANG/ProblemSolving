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
ll DP[101][10][2][2];
ll dp(int len, int s, bool zero, bool nine) {
    if (len == 1) {
        if (zero && nine) return 1;
        else return 0;
    }
    if (DP[len][s][zero][nine] != -1) return DP[len][s][zero][nine];

    ll ret = 0;
    if (s != 0) {
        if (s - 1 == 0) {
            ret += dp(len - 1, s - 1, 1, nine);
        }
        else ret += dp(len - 1, s - 1, zero, nine);
    }
    if (s != 9) {
        if (s + 1 == 9) {
            ret += dp(len - 1, s + 1, zero, 1);
        }
        else ret += dp(len - 1, s + 1, zero, nine);
    }
    return DP[len][s][zero][nine] = ret % mod;
}

void solve() {
    cin >> N;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            DP[i][j][0][0] = -1;
            DP[i][j][0][1] = -1;
            DP[i][j][1][0] = -1;
            DP[i][j][1][1] = -1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 8; i++) {
        ans += dp(N, i, 0, 0);
        ans %= mod;
    }
    ans += dp(N, 9, 0, 1);
    ans %= mod;
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