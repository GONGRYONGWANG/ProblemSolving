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
#include<chrono>
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
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


struct BridgeNArticulation { //단절점, 단절선 O(V+E) BCC
    int V;
    vector<vector<pair<int, int>>> adj; // {neighbor, edge_id}

    vector<int> discoveryTime, low;
    vector<bool> visited;
    int time;

    vector<bool> isBridge;            // edge_id -> true if it's a bridge
    vector<bool> isArticulationPoint; // node -> true if it's an articulation point
    vector<pair<int, int>> edges;     // edge_id -> (u, v) 저장

    int edgeCount = 0;

    BridgeNArticulation(int vertices)
        : V(vertices),
        adj(vertices),
        discoveryTime(vertices, -1),
        low(vertices, -1),
        visited(vertices, false),
        time(0),
        isArticulationPoint(vertices, false) {}

    void addEdge(int u, int v) {
        adj[u].emplace_back(v, edgeCount);
        adj[v].emplace_back(u, edgeCount);
        edges.emplace_back(u, v);
        ++edgeCount;
    }

    void dfs(int u, int parent, int parentEdgeId) {
        visited[u] = true;
        discoveryTime[u] = low[u] = time++;
        int children = 0;

        for (auto [v, edgeId] : adj[u]) {
            if (!visited[v]) {
                ++children;
                dfs(v, u, edgeId);

                low[u] = min(low[u], low[v]);

                if (low[v] > discoveryTime[u]) {
                    isBridge[edgeId] = true;
                }

                if (parent != -1 && low[v] >= discoveryTime[u]) {
                    isArticulationPoint[u] = true;
                }
            }
            else if (edgeId != parentEdgeId) {
                low[u] = min(low[u], discoveryTime[v]);
            }
        }

        if (parent == -1 && children > 1) {
            isArticulationPoint[u] = true;
        }
    }

    void get() {
        isBridge.assign(edgeCount, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, -1);
            }
        }
    }
};

int parent[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

int ret[100000];
void solve(int tc) {

    int N, M;
    cin >> N >> M;

    map<int, vector<tuple<int, int, int>>> m;

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        m[z].push_back({ x,y,i });
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) ret[i] = 3;

    for (auto it = m.begin(); it != m.end(); it++) {

        map<int, int> comp;
        for (auto& [u, v, i] : it->second) {
            if (findp(u) == findp(v)) continue;
            ret[i] -= 1;
            comp[findp(u)] = 0;
            comp[findp(v)] = 0;
        }

        int cnt = 0;
        for (auto iter = comp.begin(); iter != comp.end(); iter++) {
            cnt += 1;
            iter->second = cnt;
        }

        BridgeNArticulation graph(cnt + 1);

        vector<int> idx;
        for (auto& [u, v, i] : it->second) {
            if (findp(u) == findp(v)) continue;
            idx.push_back(i);
            graph.addEdge(comp[findp(u)], comp[findp(v)]);
        }

        graph.get();
        for (int j = 0; j < graph.isBridge.size(); j++) {
            if (graph.isBridge[j]) ret[idx[j]] -= 1;
        }

        for (auto& [u, v, i] : it->second) {
            parent[findp(u)] = findp(v);
        }
    }


    for (int i = 0; i < M; i++) cout << ret[i] << endl;




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