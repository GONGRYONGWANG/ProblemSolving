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
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
struct BridgeNArticulation { // 단절점, 단절선 O(V+E)
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    // Variables for finding bridges and articulation points
    vector<int> discoveryTime, low;
    vector<bool> visited;
    int time;
    unordered_set<pii, PiiHasher> bridges;
    unordered_set<int> articulationPoints;

    BridgeNArticulation(int vertices) : V(vertices), adj(vertices), discoveryTime(vertices, -1), low(vertices, -1), visited(vertices, false), time(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parent) {
        visited[u] = true;
        discoveryTime[u] = low[u] = time++;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                ++children;
                dfs(v, u);

                // Update low value of u for parent function calls
                low[u] = min(low[u], low[v]);

                // Check if the edge u-v is a bridge
                if (low[v] > discoveryTime[u]) {
                    bridges.insert({ min(u, v), max(u, v) });
                }

                // Check if u is an articulation point
                if (parent != -1 && low[v] >= discoveryTime[u]) {
                    articulationPoints.insert(u);
                }
            }
            else if (v != parent) {
                // Update low value of u for back edge
                low[u] = min(low[u], discoveryTime[v]);
            }
        }

        // Special case for root of DFS tree
        if (parent == -1 && children > 1) {
            articulationPoints.insert(u);
        }
    }

    void get() {
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
    }

};
///////////////////////////////////////////////////////////////

int parent[300001];
int sz[300001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

vector<int> E[300001];

void dfs(int x, int p) {
    for (int nx : E[x]) {
        if (nx == p) continue;
        dfs(nx, x);
        sz[x] += sz[nx] + 1;
    }
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<pii> edges(M);
    BridgeNArticulation graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        graph.addEdge(u, v);
        edges[i] = { u,v };
    }

    if (M % 2 == 0) {
        cout << 0;
        return;
    }

    graph.get();

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (auto [u, v] : edges) {
        if (graph.bridges.count({ u,v })) continue;
        u = findp(u); v = findp(v);
        sz[u] += 1;
        if (u == v) continue;
        sz[u] += sz[v];
        parent[v] = u;
    }



    for (auto [u, v] : graph.bridges) {
        u = findp(u); v = findp(v);
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int root = 0;

    for (int i = 1; i <= N; i++) {
        if (findp(i) == i) {
            root = i;
            break;
        }
    }

    dfs(root, 0);

    vector<int> ret;

    for (int i = 0; i < M; i++) {
        auto [u, v] = edges[i];
        if (!graph.bridges.count({ u,v })) {
            ret.push_back(i + 1);
            continue;
        }
        int a = findp(u); int b = findp(v);
        if (sz[a] > sz[b]) swap(a, b);
        if (sz[a] % 2) continue;
        ret.push_back(i + 1);
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for (int x : ret) cout << x << " ";




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