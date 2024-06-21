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
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////




pll sz[100001];
bool color[100001];
vector<int> E[100001];
int parent[100001];
ll ans[100001];

void dfs(int x) {
    if (color[x]) sz[x].first += 1;
    else sz[x].second += 1;
    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        parent[nx] = x;
        dfs(nx);
        sz[x].first += sz[nx].first;
        sz[x].second += sz[nx].second;
    }
}

void solve() {
    int N;
    cin >> N;

    pll total = { 0,0 };

    for (int i = 1; i <= N; i++) {
        cin >> color[i];
        if (color[i]) total.first += 1;
        else total.second += 1;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= N; i++) {
        ans[i] = -1;
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int u;
        cin >> u;
        if (ans[u] != -1) {
            cout << ans[u] << endl;
            continue;
        }
        ll ret = 0;
        ret += (total.first - sz[u].first) * (sz[u].second - (!color[u])) + (total.second - sz[u].second) * (sz[u].first - (color[u]));
        ret *= 2;
        for (int nx : E[u]) {
            if (nx == parent[u]) continue;
            ret += sz[nx].first * (sz[u].second - (!color[u]) - sz[nx].second) + sz[nx].second * (sz[u].first - (color[u]) - sz[nx].first);
        }
        ans[u] = ret / 2;
        cout << ans[u] << endl;
    }





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
