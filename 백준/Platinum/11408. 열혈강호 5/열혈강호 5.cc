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
#include<cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


struct VectorHasher { // unordered_set<vector<int>,VectorHasher>
    size_t operator()(const vector<int>& V) const {
        size_t hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

struct MF {
    struct Edge {
        int to, rev;
        long long flow, cap;
        Edge(int to, int rev, long long cap) : to(to), rev(rev), flow(0), cap(cap) {}
    };

    int n;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

    MF(int n) : n(n), adj(n), level(n), ptr(n) {}

    void addEdge(int u, int v, long long cap) {
        adj[u].emplace_back(v, adj[v].size(), cap);
        adj[v].emplace_back(u, adj[u].size() - 1, 0); // 역방향 간선
    }

    bool bfs(int source, int sink) {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (Edge& e : adj[node]) {
                if (level[e.to] == -1 && e.flow < e.cap) { // 잔여 용량이 있는 간선을 찾음
                    level[e.to] = level[node] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] != -1;
    }

    long long dfs(int node, int sink, long long pushed) {
        if (pushed == 0) return 0;
        if (node == sink) return pushed;

        for (int& cid = ptr[node]; cid < adj[node].size(); cid++) {
            Edge& e = adj[node][cid];
            if (level[e.to] != level[node] + 1 || e.flow == e.cap) continue;

            long long tr = dfs(e.to, sink, min(pushed, e.cap - e.flow));
            if (tr == 0) continue;

            e.flow += tr;
            adj[e.to][e.rev].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long getmf(int source, int sink) {
        long long flow = 0;
        while (bfs(source, sink)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(source, sink, LLONG_MAX)) {
                flow += pushed;
            }
        }
        return flow;
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

ll xgcd(ll a, ll b) {
    ll r1 = a; ll r2 = b;
    ll s1 = 1; ll s2 = 0;
    ll t1 = 0; ll t2 = 1;
    while (1) {
        ll q = r1 / r2;
        ll r = r1 - q * r2;
        ll s = s1 - q * s2;
        ll t = t1 - q * t2;
        if (r == 0) return s2;
        r1 = r2; r2 = r;
        s1 = s2; s2 = s;
        t1 = t2; t2 = t;
    }
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

ll modinv(ll x, ll mod) { // when mod is primenum
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


//int dx[4] = { 1,0,-1,0 }; // DRUL
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

struct MCMF {
    struct Edge {
        int to, rev;
        long long cap, flow, cost;
        Edge(int to, int rev, long long cap, long long cost) : to(to), rev(rev), cap(cap), flow(0), cost(cost) {}
    };

    int n;
    vector<vector<Edge>> adj;
    vector<long long> dist;
    vector<int> parent, parentEdge;
    vector<bool> inQueue;
    int source, sink;

    MCMF(int n) : n(n), adj(n), dist(n), parent(n), parentEdge(n), inQueue(n), source(-1), sink(-1) {}

    void setSource(int s) {
        source = s;
    }

    void setSink(int t) {
        sink = t;
    }

    void addEdge(int u, int v, long long cap, long long cost) {
        adj[u].emplace_back(v, adj[v].size(), cap, cost);
        adj[v].emplace_back(u, adj[u].size() - 1, 0, -cost); // 역방향 간선
    }

    bool spfa() {
        fill(dist.begin(), dist.end(), LLONG_MAX);
        fill(inQueue.begin(), inQueue.end(), false);
        queue<int> q;
        dist[source] = 0;
        inQueue[source] = true;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (int i = 0; i < adj[u].size(); ++i) {
                Edge& e = adj[u][i];
                if (e.flow < e.cap && dist[u] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[u] + e.cost;
                    parent[e.to] = u;
                    parentEdge[e.to] = i;

                    if (!inQueue[e.to]) {
                        inQueue[e.to] = true;
                        q.push(e.to);
                    }
                }
            }
        }

        return dist[sink] != LLONG_MAX;
    }

    pair<long long, long long> getmcmf() {
        long long maxFlow = 0, minCost = 0;

        while (spfa()) {
            long long flow = LLONG_MAX;

            for (int u = sink; u != source; u = parent[u]) {
                Edge& e = adj[parent[u]][parentEdge[u]];
                flow = min(flow, e.cap - e.flow);
            }

            for (int u = sink; u != source; u = parent[u]) {
                Edge& e = adj[parent[u]][parentEdge[u]];
                e.flow += flow;
                adj[u][e.rev].flow -= flow;
                minCost += flow * e.cost;
            }

            maxFlow += flow;
        }

        return { maxFlow, minCost };
    }
};




void solve() {

    int N, M;
    cin >> N >> M;
    MCMF flow(N + M + 3);
    int src = N + M + 1; int sink = N + M + 2;
    flow.setSource(src);
    flow.setSink(sink);

    for (int i = 1; i <= N; i++) {
        flow.addEdge(src, i, 1, 0);
        int k;
        cin >> k;
        while (k--) {
            int v, cost;
            cin >> v >> cost;
            flow.addEdge(i, v + N, 1, cost);
        }
    }

    for (int i = N + 1; i <= N + M; i++) {
        flow.addEdge(i, sink, 1, 0);
    }

    pair<ll, ll> ret = flow.getmcmf();

    cout << ret.first << endl << ret.second;




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

