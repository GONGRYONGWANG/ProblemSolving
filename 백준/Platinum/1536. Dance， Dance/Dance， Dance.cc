// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
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
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
struct MF { // Dinic O(V^2*E)
    struct Edge {
        int to, rev;
        long long flow, cap;
        Edge(int to, int rev, long long cap) : to(to), rev(rev), flow(0), cap(cap) {}
    };

    int n;
    vector<vector<Edge>> adj; // get이후 edge vector를 이용해서 trace, cap<=flow인 간선은 continue하며 bfs.
    vector<int> level, ptr;

    MF(int n) : n(n), adj(n), level(n), ptr(n) {}

    void addEdge(int u, int v, long long cap, bool directed = true) {
        if (cap == 0) return;
        adj[u].emplace_back(v, adj[v].size(), cap);
        if (!directed) adj[v].emplace_back(u, adj[u].size() - 1, cap);
        else adj[v].emplace_back(u, adj[u].size() - 1, 0);
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
    long long get(int source, int sink) {
        long long flow = 0;
        while (bfs(source, sink)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(source, sink, LLONG_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }
    void trace(int src) {
        queue<int> q;
        q.push(src);
        vector<bool> visited(n, false);
        visited[src] = true;
        vector<int> ret;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (Edge& e : adj[cur]) {
                if (e.cap <= e.flow) continue;
                if (visited[e.to]) continue;
                q.push(e.to);
                ret.push_back(e.to);
                visited[e.to] = true;
            }
        }
        cout << ret.size() << " ";
        for (int x : ret) {
            cout << x << " ";
        }
        cout << endl;
    }
};

///////////////////////////////////////////////////////////////


bool adj[51][51];

void solve(int tc) {

    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char x;
            cin >> x;
            adj[i][j] = (x == '1');
        }
    }

    for (int ret = 1; ret <= N; ret++) {
        MF graph(6 * N + 3); // 1~N B , ~2N B1, ~3N B2, ~4N G, ~5N G1, ~6N G2
        int src = 6 * N + 1; int sink = 6 * N + 2;
        for (int i = 1; i <= N; i++) {
            graph.addEdge(src, i, ret);
            graph.addEdge(i, i + N, ret);
            graph.addEdge(i, i + 2 * N, K);
            graph.addEdge(i + 3 * N, sink, ret);
            graph.addEdge(i + 4 * N, i + 3 * N, ret);
            graph.addEdge(i + 5 * N, i + 3 * N, K);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adj[i][j]) graph.addEdge(i + N, j + 4 * N, 1);
                else graph.addEdge(i + 2 * N, j + 5 * N, 1);
            }
        }

        if (graph.get(src, sink) != N * ret) {
            cout << ret - 1;
            return;
        }
    }

    cout << N;


    


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}