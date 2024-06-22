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



struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    } 
};


int N, M;

void solve() {

    vector<vector<pii>> E(N);
    vector<vector<pii>> rE(N);

    int S, D;
    cin >> S >> D;


    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        rE[v].push_back({ u,w });
    }

    vector<int> dist(N, 0);

    pq<pii,vector<pii>, cmp> q;
    q.push({ S,1 });
    while (!q.empty()) {
        int cur = q.top().first;
        int d = q.top().second;
        q.pop();

        if (dist[cur]) continue;
        dist[cur] = d;
        for (pii nx : E[cur]) {
            if (dist[nx.first]) continue;
            q.push({ nx.first, nx.second + d });
        }
    }

    if (!dist[D]) {
        cout << -1 << endl;
        return;
    }


    vector<unordered_set<int>> exclude(N);
    vector<bool> visited(N, false);

    queue<int> Q;
    Q.push(D);
    visited[D] = true;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (pii nx : rE[cur]) {
            if (dist[nx.first] + nx.second == dist[cur]) {
                exclude[nx.first].insert(cur);
                if (visited[nx.first]) continue;
                visited[nx.first] = true;
                Q.push(nx.first);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }


    q.push({ S,0 });
    while (!q.empty()) {
        int cur = q.top().first;
        int d = q.top().second;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (cur == D) {
            cout << d << endl;
            return;
        }

        for (pii nx : E[cur]) {
            if (visited[nx.first]) continue;
            if (exclude[cur].count(nx.first)) continue;
            q.push({ nx.first, d + nx.second });
        }
    }

    cout << -1 << endl;
    return;


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    cin >> N >> M;
    while (N!=0) {
        solve();
        cin >> N >> M;
    }

    return 0;
}
