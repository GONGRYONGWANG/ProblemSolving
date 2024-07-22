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
    ll ret = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    if (ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
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


int DP[1002][1002];
pii arr[1002];
pii parent[1002][1002];
int dist(pii p1, pii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int dp(int a, int b) {
    if (a == 0 && b == 1) return 0;
    if (DP[a][b] != inf) return DP[a][b];
    if (a > b) {
        if (b == a - 1) {
            for (int i = 0; i < b; i++) {
                if (i == 1) continue;
                if (dist(arr[a], arr[i]) + dp(i, b) < DP[a][b]) {
                    DP[a][b] = dist(arr[a], arr[i]) + dp(i, b);
                    parent[a][b] = { i,b };
                }
            }
            return DP[a][b];
        }
        else {
            parent[a][b] = { a - 1,b };
            return DP[a][b] = dp(a - 1, b) + dist(arr[a - 1], arr[a]);
        }
    }
    else {
        if (a == b - 1) {
            for (int i = 0; i < a; i++) {
                if (i == 0) continue;
                if (dist(arr[b], arr[i]) + dp(a, i) < DP[a][b]) {
                    DP[a][b] = dist(arr[b], arr[i]) + dp(a, i);
                    parent[a][b] = { a,i };
                }
            }
            return DP[a][b];
        }
        else {
            parent[a][b] = { a,b - 1 };
            return DP[a][b] = dp(a, b - 1) + dist(arr[b - 1], arr[b]);
        }
    }



}

void solve() {
    int N, W;
    cin >> N >> W;
    arr[0] = { 1,1 };
    arr[1] = { N ,N };

    for (int i = 0; i <= W + 1; i++) {
        for (int j = 0; j <= W + 1; j++) {
            DP[i][j] = inf;
        }
    }

    for (int i = 2; i <= W+1; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    pii ans;
    int mn = inf;
    for (int i = 0; i <= W; i++) {
        if (i != 1) {
            if (dp(i, W + 1) < mn) {
                mn = dp(i, W + 1);
                ans = { i,W + 1 };
            }
        }
        if (i != 0) {
            if (dp(W + 1, i) < mn) {
                mn = dp(W + 1, i);
                ans = { W + 1,i };
            }
        }
    }

    cout << mn << endl;
    vector<int> ansv(W + 2);
    while (ans != make_pair(0, 1)) {
        ansv[ans.first] = 1;
        ansv[ans.second] = 2;
        ans = parent[ans.first][ans.second];
    }

    for (int i = 2; i <= W + 1; i++) {
        cout << ansv[i] << endl;
    }

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
