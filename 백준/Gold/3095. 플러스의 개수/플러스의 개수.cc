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
    ll ret= (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
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

vector<bool> board[2002];
short DP0[2002][2002][4];
short DP1[2002][2002][4];

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i <= N + 1; i++) {
        board[i].resize(N + 2, false);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char x;
            cin >> x;
            board[i][j] = (x == '1');
        }
    }


    vector<int> dx0 = { -1,-1,1,1 };
    vector<int> dy0 = { -1,1,1,-1 };
    vector<int> dx1 = { -1,0,1,0 };
    vector<int> dy1 = { 0,-1,0,1 };

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!board[i][j]) {
                DP0[i][j][0] = min(DP0[i - 1][j - 1][0], min(DP0[i - 1][j][0], DP0[i][j - 1][0])) + 1;
            }
            else {
                for (int dir = 0; dir < 2; dir++) {
                    DP1[i][j][dir] = DP1[i + dx1[dir]][j + dy1[dir]][dir] + 1;
                }
            }
        }
    }

    for (int i = N; i >= 1; i--) {
        for (int j = N; j >= 1; j--) {
            if (!board[i][j]) {
                DP0[i][j][2]= min(DP0[i + 1][j + 1][2], min(DP0[i + 1][j][2], DP0[i][j + 1][2])) + 1;
            }
            else {
                for (int dir = 2; dir < 4; dir++) {
                    DP1[i][j][dir] = DP1[i + dx1[dir]][j + dy1[dir]][dir] + 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = N; j >= 1; j--) {
            if (!board[i][j]) {
                DP0[i][j][1] = min(DP0[i - 1][j + 1][1], min(DP0[i - 1][j][1], DP0[i][j + 1][1])) + 1;
            }
        }
    }

    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= N; j++) {
            if (!board[i][j]) {
                DP0[i][j][3] = min(DP0[i + 1][j - 1][3], min(DP0[i + 1][j][3], DP0[i][j - 1][3])) + 1;
            }
        }
    }

    int ans = 0;


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!board[i][j]) continue;
            short ret = 3000;
            for (int dir = 0; dir < 4; dir++) {
                ret = min(ret, DP0[i + dx0[dir]][j + dy0[dir]][dir]);
                ret = min(ret, DP1[i + dx1[dir]][j + dy1[dir]][dir]);
            }
            ans += ret;
        }
    }

    cout << ans;

    return;

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
