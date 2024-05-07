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

//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

vector<pii> E[100001];
int cnt[100001];
int dist[100001];
vector<int> parent[100001];


void solve() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        cnt[v] += 1;
    }

    int s, e;
    cin >> s >> e;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < E[cur].size(); i++) {
            int nx = E[cur][i].first;
            int d = E[cur][i].second;

            if (dist[cur] + d > dist[nx]) {
                dist[nx] = dist[cur] + d;
                parent[nx].clear();
            }
            if (dist[cur] + d == dist[nx]) {
                parent[nx].push_back(cur);
            }

            cnt[nx] -= 1;
            if (cnt[nx] == 0) q.push(nx);
        }
    }

    cout << dist[e] << endl;

    int ans = 0;
    vector<bool> visited(100001, false);
    q.push(e);
    visited[e] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans += parent[cur].size();
        for (int nx : parent[cur]) {
            if (visited[nx]) continue;
            visited[nx] = true;
            q.push(nx);
        }
    }

    cout << ans;

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
