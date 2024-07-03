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


// F[];
ll factorial(ll x) {
    ll ret = 1;
    //ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
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


vector<pii> E[200000];
int sz[200000];
bool visited[200000];

void getsz(int cur, int p) {
    sz[cur] = 1;
    for (pii nx : E[cur]) {
        if (nx.first == p || visited[nx.first]) continue;
        getsz(nx.first, cur);
        sz[cur] += sz[nx.first];
    }
}

int getcent(int cur, int p, int size) {
    for (pii nx : E[cur]) {
        if (nx.first == p || visited[nx.first]) continue;
        if (sz[nx.first] > size  / 2) {
            return getcent(nx.first, cur, size);
        }
    }
    return cur;
}

int N, K;
int ans;
map<int, int> m;

void dnq(int x) {
    getsz(x, -1);
    int cent = getcent(x, -1, sz[x]);
    visited[cent] = true;
    m.clear();
    m[0] = 0;
    for (pii nx : E[cent]) {
        if (visited[nx.first]) continue;
        queue<vector<int>> q; // cur, dist, prv, depth
        q.push({ nx.first, nx.second, cent, 1 });
        while (!q.empty()) {
            int cur = q.front()[0];
            int dist = q.front()[1];
            int prv = q.front()[2];
            int depth = q.front()[3];
            q.pop();
            if (m.count(K - dist)) {
                ans = min(ans, m[K - dist] + depth);
            }
            for (pii nxt : E[cur]) {
                if (nxt.first == prv || visited[nxt.first]) continue;
                q.push({ nxt.first, nxt.second + dist, cur, depth + 1 });
            }
        }

        q.push({ nx.first, nx.second, cent, 1 });
        while (!q.empty()) {
            int cur = q.front()[0];
            int dist = q.front()[1];
            int prv = q.front()[2];
            int depth = q.front()[3];
            q.pop();
            if (!m.count(dist)) {
                m[dist] = depth;
            }
            else m[dist] = min(m[dist], depth);
            for (pii nxt : E[cur]) {
                if (nxt.first == prv || visited[nxt.first]) continue;
                q.push({ nxt.first, nxt.second + dist, cur, depth + 1 });
            }
        }
    }

    for (pii nx : E[cent]) {
        if (visited[nx.first]) continue;
        dnq(nx.first);
    }
}

void solve() {

    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }
    ans = inf;
    dnq(0);
    if (ans == inf) cout << -1;
    else cout << ans;


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
