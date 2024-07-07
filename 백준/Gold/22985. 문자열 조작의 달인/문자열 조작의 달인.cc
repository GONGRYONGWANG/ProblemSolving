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
    size_t operator()(const vector<int>& V) const {
        size_t hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct PiiHasher {
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
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


//const ll Fsize = 1;
//ll F[Fsize];
ll factorial(ll x) {
    ll ret = 1;
    //ret = F[x]; //
    return ret;
}

//ll modI[Fsize];  ll modIF[Fsize];
ll modinvfactorial(ll x) {
    ll ret = 1;
    //ret = modIF[x]; //
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    if (r == 0 || n == r) return 1;
    return factorial(n) * modinvfactorial(n - r) % mod * modinvfactorial(r) % mod;
}

ll ccw(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

bool intersect(pll A, pll B, pll C, pll D) { // 선분 교차 판정 A-B , C-D
    if (A > B) swap(A, B);
    if (C > D) swap(C, D);

    ll l1 = ccw(A, B, C) * ccw(A, B, D);
    ll l2 = ccw(C, D, A) * ccw(C, D, B);

    if (l1 == 0 && l2 == 0) {
        return A <= D && C <= B;
    }
    return l1 <= 0 && l2 <= 0;
}



//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

ll N, M;

int arr[300];
ll DP[300][7501][2];
ll mod = 1e9 + 7;
ll Psum[300][7501][2];

ll dp(int x, int n, bool b);

ll psum(int x, int n, bool b) {
    if (n < 0) return 0;
    if (Psum[x][n][b] != -1) return Psum[x][n][b];
    if (n == 0) return Psum[x][n][b] = dp(x, 0, b);
    return Psum[x][n][b] = (psum(x, n - 1, b) + dp(x, n, b)) % mod;
}
ll dp(int x, int n, bool b) {
    if (x == N) {
        if (n > 0) return 0;
        return 1;
    }
    if (DP[x][n][b] != -1) return DP[x][n][b];

    ll ret = 0;

    if (b) {
        ret += psum(x + 1, n, 1) - psum(x + 1, n - min(arr[x], n) - 1, 1) + mod;
    }
    else {
        ret += psum(x + 1, n, 0) - psum(x + 1, n - arr[x], 0) + psum(x + 1, n - arr[x], 1) + mod;
    }
    ret %= mod;

    return DP[x][n][b] = ret;
}

void solve() {
    cin >> N >> M;
    ll total = 0;
    for (int i = 0; i < N; i++) {
        char x;
        cin >> x;
        arr[i] = 'z' - x;
        total += arr[i];
    }


    for (int i = 0; i < 300; i++) {
        for (int j = 0; j <= 7500; j++) {
            DP[i][j][0] = DP[i][j][1] = -1;
            Psum[i][j][0] = Psum[i][j][1] = -1;
        }
    }

    M = min(M, total);
    cout << dp(0, M, 0);




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
