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

//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////




void solve() {

    int K, M, P;
    cin >> K >> M >> P;

    vector<vector<int>> E(M + 1);
    vector<vector<int>> rE(M + 1);
    vector<int> cnt(M + 1);
    vector<int> stra(M + 1, 0);
    for (int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        rE[v].push_back(u);
        cnt[v] += 1;
    }

    queue<int> q;
    for (int i = 1; i <= M; i++) {
        if (cnt[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int mx = 1;
        int mxcnt = 0;
        for (int p : rE[x]) {
            if (stra[p] > mx) {
                mx = stra[p];
                mxcnt = 1;
            }
            else if (stra[p] == mx) {
                mxcnt += 1;
            }
        }

        if (mxcnt >= 2) {
            stra[x] = mx + 1;
        }
        else stra[x] = mx;


        for (int nx : E[x]) {
            cnt[nx] -= 1;
            if (cnt[nx] == 0) q.push(nx);
        }
    }

    cout << K << " " << stra[M] << endl;



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
