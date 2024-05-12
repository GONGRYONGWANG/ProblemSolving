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


vector<pii> E[100001];
pll lr[100001];

int tree[400000][20];
bool lazy[400000][20];

void lazyProp(int node, int start, int end, int x) {
    if (!lazy[node][x]) return;
    tree[node][x] = end - start + 1 - tree[node][x];
    if (start != end) {
        lazy[node * 2][x] = !lazy[node * 2][x];
        lazy[node * 2 + 1][x] = !lazy[node * 2 + 1][x];
    }
    lazy[node][x] = 0;
}

void update(int node, int start, int end, int left, int right, int x) {
    lazyProp(node, start, end, x);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node][x] = 1;
        lazyProp(node, start, end, x);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, x);
    update(node * 2 + 1, mid + 1, end, left, right, x);
    tree[node][x] = tree[node * 2][x] + tree[node * 2 + 1][x];
}

ll get(int node, int start, int end, int left, int right, int x) {
    lazyProp(node, start, end, x);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node][x];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right, x) + get(node * 2  + 1, mid + 1, end, left, right, x);
}


int d[100001];

int idx;
void dfs(int x) {
    idx += 1;
    lr[x].first = idx;
    for (int i = 0; i < E[x].size(); i++) {
        int nx = E[x][i].first;
        if (lr[nx].first) continue;
        d[nx] = E[x][i].second;
        dfs(nx);
    }
    lr[x].second = idx;
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    idx = 0;
    dfs(1);

    for (int i = 1; i <= N; i++) {
        int l = lr[i].first;
        int r = lr[i].second;

        int tmp = 1;
        for (int x = 0; x <= 19; x++) {
            if ((d[i] & tmp) != 0) {
                update(1, 1, N, l, r, x);
            }
            tmp *= 2;
        }
    }


    int Q;
    cin >> Q;
    while (Q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int u, v;
            cin >> u >> v;
            int tmp = v;
            v ^= d[u];
            d[u] = tmp;

            tmp = 1;
            for (int x = 0; x <= 19; x++) {
                if (v & tmp) {
                    update(1, 1, N, lr[u].first, lr[u].second, x);
                }
                tmp *= 2;
            }
        }
        else {

            ll ans = 0;

            int u, v;
            cin >> u >> v;
            ll tmp = 1;
            for (int x = 0; x <= 19; x++) {
                ll A = get(1, 1, N, lr[u].first, lr[u].second, x);
                ll B = get(1, 1, N, lr[v].first, lr[v].second, x);

                ans += (A * (lr[v].second - lr[v].first + 1 - B) + B * (lr[u].second - lr[u].first + 1 - A)) * tmp;
                tmp *= 2;
            }
            cout << ans << endl;
        }

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
