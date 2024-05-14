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


vector<pll> pave[200001];
vector<pll> road[200001];

bool visited[200001];

struct cmp {
    bool operator()(pll a, pll b) {
        return a.second > b.second;
    }
};

void solve() {
    ll N, K, X, Y;
    cin >> N >> K >> X >> Y;

    for (int i = 0; i < X; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        pave[u].push_back({ v,w });
        pave[v].push_back({ u,w });
    }
    for (int i = 0; i < Y; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        road[u].push_back({ v,w });
        road[v].push_back({ u,w });
    }

    pq<pll, vector<pll>, cmp> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        ll cur = q.top().first;
        ll d = q.top().second;
        q.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        if (cur == N) {
            cout << d;
            return;
        }

        for (pll e : pave[cur]) {
            ll nx = e.first;
            ll nd = d + e.second;
            if (visited[nx]) continue;
            q.push({ nx,nd });
        }

        for (pll e : road[cur]) {
            ll nx = e.first;
            ll nd = max(d, K) + e.second;
            if (visited[nx]) continue;
            q.push({ nx,nd });
        }
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
