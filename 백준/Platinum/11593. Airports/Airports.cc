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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

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

ll init[501][501];
ll dist[501][501];
ll P[501];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> P[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> init[i][j];
            if (i != j) init[i][j] += P[j];
            dist[i][j] = init[i][j];
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<vector<ll>> v(M);
    for (int i = 0; i < M; i++) {
        ll s, f, t;
        cin >> s >> f >> t;
        v[i] = { t,s,f };
    }

    sort(v.begin(), v.end());

    BiMatch graph(M, M);

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            if (v[i][0] + init[v[i][1]][v[i][2]] + dist[v[i][2]][v[j][1]] <= v[j][0]) {
                graph.addEdge(i + 1, j + 1);
            }
        }
    }

    cout << M - graph.get();



    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}