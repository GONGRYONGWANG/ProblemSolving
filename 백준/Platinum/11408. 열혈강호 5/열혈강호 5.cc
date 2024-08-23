#include<bits/stdc++.h>
#include<ext/rope>
/*
string s;
s.c_str() -> 스트링을 char arr로
rope<char> rp(s.c_str());
rp.insert(idx, s.c_str());
rp.insert(idx, some_char);'
cout<<rp.substr(idx, length);
*/

using namespace std;
using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;

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


///////////////////////////////////////////////
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
                Edge &e = adj[u][i];
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

    pair<long long, long long> mcmf() {
        long long maxFlow = 0, minCost = 0;

        while (spfa()) {
            long long flow = LLONG_MAX;

            for (int u = sink; u != source; u = parent[u]) {
                Edge &e = adj[parent[u]][parentEdge[u]];
                flow = min(flow, e.cap - e.flow);
            }

            for (int u = sink; u != source; u = parent[u]) {
                Edge &e = adj[parent[u]][parentEdge[u]];
                e.flow += flow;
                adj[u][e.rev].flow -= flow;
                minCost += flow * e.cost;
            }

            maxFlow += flow;
        }

        return {maxFlow, minCost};
    }
};

void solve() {

    int N,M;
    cin>>N>>M;
    MCMF flow(N+M+3);
    int src= N+M+1; int sink = N+M+2;
    flow.setSource(src);
    flow.setSink(sink);

    for(int i=1; i<=N;i++){
        flow.addEdge(src,i,1,0);
        int k;
        cin>>k;
        while(k--){
            int v,cost;
            cin>>v>>cost;
            flow.addEdge(i,v+N,1,cost);
        }
    }

    for(int i=N+1;i<=N+M;i++){
        flow.addEdge(i,sink,1,0);
    }

    pair<ll,ll> ret = flow.mcmf();

    cout<<ret.first<<endl<<ret.second;

}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
