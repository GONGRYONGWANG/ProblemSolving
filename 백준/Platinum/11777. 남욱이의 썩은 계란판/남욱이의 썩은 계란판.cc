// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
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
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
struct MCMF { // SPFA O(VEf) - Practically Ef
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

    void addEdge(int u, int v, long long cap, long long cost, bool directed = true) {
        if (cap == 0) return;
        adj[u].emplace_back(v, adj[v].size(), cap, cost);
        adj[v].emplace_back(u, adj[u].size() - 1, 0, -cost); // 역방향 간선
        if (!directed) {
            adj[v].emplace_back(u, adj[u].size(), cap, cost);
            adj[u].emplace_back(v, adj[v].size() - 1, 0, -cost);
        }
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
    pair<long long, long long> get(int _source = -1, int _sink = -1) {
        if (_source != -1) {
            setSource(_source);
            setSink(_sink);
        }
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
///////////////////////////////////////////////////////////////

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }
};

int arr[4000000];

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    ll total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i * N + j];
            total += arr[i * N + j];
        }
    }

    pq<vector<int>, vector<vector<int>>, cmp> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 1 != N) q.push({ i * N + j, (i + 1) * N + j,arr[i * N + j] + arr[(i + 1) * N + j] });
            if (j + 1 != N) q.push({ i * N + j, i * N + j + 1,arr[i * N + j] + arr[i * N + j + 1] });
            while (q.size() > 10 * K) q.pop();
        }
    }

    int idx = 0;
    vector<int> index(N * N, 0);
    vector<int> L; vector<int> R;
    vector<vector<int>> edges;
    while (!q.empty()) {
        int a = q.top()[0]; int b = q.top()[1];
        int w = q.top()[2];
        q.pop();
        if ((a / N + a % N) % 2) swap(a, b);
        if (!index[a]) {
            index[a] = ++idx;
            L.push_back(idx);
        }
        if (!index[b]) {
            index[b] = ++idx;
            R.push_back(idx);
        }
        edges.push_back({ index[a],index[b],w });
    }

    int src1 = idx + 1; int src2 = idx + 2; int sink = idx + 3;
    MCMF graph(idx + 4);
    graph.addEdge(src1, src2, K, 0);
    for (int l : L) {
        graph.addEdge(src2, l, 1, 0);
    }
    for (int r : R) {
        graph.addEdge(r, sink, 1, 0);
    }

    for (int i = 0; i < edges.size(); i++) {
        int l = edges[i][0]; int r = edges[i][1]; int w = 1000 - edges[i][2];
        graph.addEdge(l, r, 1, w);
    }

    pll ret = graph.get(src1, sink);

    cout << total - (ret.first * 1000 - ret.second);

}
    


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}