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


const int MCMFSZ = 605; // The # of nodes.
struct MCMF {
    int n;
    int c[MCMFSZ][MCMFSZ] = { 0 }; // capacity
    int f[MCMFSZ][MCMFSZ] = { 0 }; // flow
    int d[MCMFSZ][MCMFSZ] = { 0 }; // dist
    vector<int> g[MCMFSZ]; // graph
    int source, sink;

    MCMF() {
        init(n);
    }

    MCMF(int n, int s, int t) {
        init(n);
        source = s; sink = t;
    }

    void init(int _n) {
        n = _n + 1;
        source = sink = -1;
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
    }

    void setSource(int s) {
        source = s;
    }

    void setSink(int t) {
        sink = t;
    }

    void addEdge(int s, int e, int cap, int dist) {
        g[s].push_back(e); c[s][e] = cap; d[s][e] = dist;
        g[e].push_back(s); c[e][s] = 0; d[e][s] = -dist;
    }

    int mcmf() {
        int cnt = 0;
        int minCost = 0;
        int prv[MCMFSZ], dist[MCMFSZ];
        bool inque[MCMFSZ] = { 0 };
        while (1) {
            memset(prv, -1, sizeof prv); memset(dist, inf, sizeof dist); memset(inque, 0, sizeof inque);
            queue<int> q;
            dist[source] = 0;
            inque[source] = 1;
            q.push(source);

            while (q.size()) {
                int now = q.front(); q.pop(); inque[now] = 0;
                for (auto nxt : g[now]) {
                    if (c[now][nxt] - f[now][nxt] > 0 && dist[nxt] > dist[now] + d[now][nxt]) {
                        dist[nxt] = dist[now] + d[now][nxt];
                        prv[nxt] = now;
                        if (!inque[nxt]) {
                            q.push(nxt);
                            inque[nxt] = 1;
                        }
                    }
                }
            }
            if (prv[sink] == -1) break;
            int flow = inf; // Adjust maximum flow for long long
            for (int i = sink; i != source; i = prv[i]) {
                flow = min(flow, c[prv[i]][i] - f[prv[i]][i]);
            }
            for (int i = sink; i != source; i = prv[i]) {
                minCost += flow * d[prv[i]][i];
                f[prv[i]][i] += flow;
                f[i][prv[i]] -= flow;
            }
            cnt++;
        }
        //cout << cnt << "\n";
        return minCost;
    }
}; //출저: justicehui.github.io


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


struct MF {
    struct Edge {
        int to, rev;
        int flow, cap;
        Edge(int to, int rev, int cap) : to(to), rev(rev), flow(0), cap(cap) {}
    };

    int n;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

    MF(int n) : n(n), adj(n), level(n), ptr(n) {}

    void addEdge(int u, int v, int cap) {
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

    int dfs(int node, int sink, int pushed) {
        if (pushed == 0) return 0;
        if (node == sink) return pushed;

        for (int& cid = ptr[node]; cid < adj[node].size(); cid++) {
            Edge& e = adj[node][cid];
            if (level[e.to] != level[node] + 1 || e.flow == e.cap) continue;

            int tr = dfs(e.to, sink, min(pushed, e.cap - e.flow));
            if (tr == 0) continue;

            e.flow += tr;
            adj[e.to][e.rev].flow -= tr;
            return tr;
        }
        return 0;
    }

    int mf(int source, int sink) {
        int flow = 0;
        while (bfs(source, sink)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(source, sink, inf)) {
                flow += pushed;
            }
        }
        return flow;
    }
};



void solve() {

    int N, P;
    cin >> N >> P;
    MF flow(N + P + 1);
    for (int i = N + 1; i <= N + P; i++) {
        int u, v;
        cin >> u >> v;
        flow.addEdge(u, i, 1);
        flow.addEdge(i, v, 1);
    }
    cout << flow.mf(1, 2);






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

