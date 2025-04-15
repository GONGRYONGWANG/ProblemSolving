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
#define INF ll(9e18)
const int inf = 1e9 + 7;
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
struct BiMatch { // Hopcroft-Karp O(E*sqrtV)
    int n, m; // n: left side vertices, m: right side vertices
    vector<vector<int>> adj; // adjacency list
    vector<int> pairU, pairV, dist;
    // pairU 또는 pairV를 출력해서 매칭 결과를 print 가능.

    BiMatch(int n, int m) : n(n), m(m), adj(n + 1), pairU(n + 1), pairV(m + 1), dist(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (pairU[u] == 0) { // If u is free (not matched)
                dist[u] = 0;
                q.push(u);
            }
            else {
                dist[u] = INT_MAX;
            }
        }

        dist[0] = INT_MAX;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] < dist[0]) {
                for (int v : adj[u]) {
                    if (dist[pairV[v]] == INT_MAX) { // If pairV[v] is not yet visited
                        dist[pairV[v]] = dist[u] + 1;
                        q.push(pairV[v]);
                    }
                }
            }
        }

        return dist[0] != INT_MAX; // If there's an augmenting path
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u]) {
                if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
            dist[u] = INT_MAX;
            return false;
        }
        return true;
    }

    int get() {
        fill(pairU.begin(), pairU.end(), 0);
        fill(pairV.begin(), pairV.end(), 0);
        int matching = 0;

        while (bfs()) {
            for (int u = 1; u <= n; u++) {
                if (pairU[u] == 0 && dfs(u)) {
                    matching++;
                }
            }
        }

        return matching;
    }

};
///////////////////////////////////////////////////////////////

vector<pll> E[1000];
ll dist[1000];
struct cmp {
    bool operator()(vector<ll>& a, vector<ll>& b) {
        return a[1] > b[1];
    }
};

vector<int> EE[1000];
bool isclient[1000];

void solve(int tc) {

    int N, M, C;
    cin >> N >> M >> C;

    vector<int> arr(C);
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
        isclient[arr[i]] = true;
    }

    for (int i = 0; i < M; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
    }

    pq<vector<ll>, vector<vector<ll>>, cmp> q;
    q.push({ 0, 1, 0 });
    while (!q.empty()) {
        int x = q.top()[0];
        ll d = q.top()[1];
        int p = q.top()[2];
        q.pop();
        if (dist[x]) {
            if (dist[x] == d) {
                EE[p].push_back(x);
            }
            continue;
        }
        dist[x] = d;
        EE[p].push_back(x);
        for (pll& e : E[x]) {
            if (dist[e.first]) continue;
            q.push({ e.first,e.second + d,x });
        }
    }

    BiMatch graph(N - 1, N - 1);

    for (int c : arr) {
        queue<int> q;
        q.push(c);
        vector<bool> visited(N, false);
        visited[c] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (isclient[x] && x != c) {
                graph.addEdge(c, x);
            }
            for (int nx : EE[x]) {
                if (visited[nx]) continue;
                q.push(nx);
                visited[nx] = true;
            }
        }
    }

    cout << C - graph.get();


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