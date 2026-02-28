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

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
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

int comp[150][150][2];
bool unsat[45001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i + j) % 2) {
                comp[i][j][0] = ++idx1; 
                comp[i][j][1] = ++idx1; 
            }
            else {
                comp[i][j][0] = ++idx2;
                comp[i][j][1] = ++idx2;
            }
        }
    }

    BiMatch graph(idx1, idx2);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i + j) % 2 == 0) {
                comp[i][j][0] += idx1;
                comp[i][j][1] += idx1;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            unsat[comp[i][j][0]] |= (i == 0 || i == N - 1);
            unsat[comp[i][j][1]] |= (j == 0 || j == M - 1);
            char x; cin >> x;
            if (x == '-') {
                unsat[comp[i][j][0]] = unsat[comp[i][j][1]] = true;
            }
            else if (x == '^') {
                if (i != 0) unsat[comp[i - 1][j][0]] = true;
                if (i != N - 1) unsat[comp[i + 1][j][0]] = true;
                if (j != 0) unsat[comp[i][j - 1][1]] = true;
                if (j != M - 1) unsat[comp[i][j + 1][1]] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i + j) % 2 == 0) continue;

            if (!unsat[comp[i][j][0]]) {
                int u = comp[i][j][0];
                if (i != 0 && !unsat[comp[i - 1][j][0]]) {
                    int v = comp[i - 1][j][0] - idx1;
                    graph.addEdge(u, v);
                }
                if (i != N - 1 && !unsat[comp[i + 1][j][0]]) {
                    int v = comp[i + 1][j][0] - idx1;
                    graph.addEdge(u, v);
                }
                if (j != 0 && !unsat[comp[i][j - 1][1]]) {
                    int v = comp[i][j - 1][1] - idx1;
                    graph.addEdge(u, v);
                }
                if (j != M - 1 && !unsat[comp[i][j + 1][1]]) {
                    int v = comp[i][j + 1][1] - idx1;
                    graph.addEdge(u, v);
                }

                if (i != 0 && !unsat[comp[i - 1][j][1]]) {
                    int v = comp[i - 1][j][1] - idx1;
                    graph.addEdge(u, v);
                }
                if (i != N - 1 && !unsat[comp[i + 1][j][1]]) {
                    int v = comp[i + 1][j][1] - idx1;
                    graph.addEdge(u, v);
                }
            }

            if (!unsat[comp[i][j][1]]) {
                int u = comp[i][j][1];
                if (i != 0 && !unsat[comp[i - 1][j][0]]) {
                    int v = comp[i - 1][j][0] - idx1;
                    graph.addEdge(u, v);
                }
                if (i != N - 1 && !unsat[comp[i + 1][j][0]]) {
                    int v = comp[i + 1][j][0] - idx1;
                    graph.addEdge(u, v);
                }
                if (j != 0 && !unsat[comp[i][j - 1][1]]) {
                    int v = comp[i][j - 1][1] - idx1;
                    graph.addEdge(u, v);
                }
                if (j != M - 1 && !unsat[comp[i][j + 1][1]]) {
                    int v = comp[i][j + 1][1] - idx1;
                    graph.addEdge(u, v);
                }

                if (j != 0 && !unsat[comp[i][j - 1][0]]) {
                    int v = comp[i][j - 1][0] - idx1;
                    graph.addEdge(u, v);
                }
                if (j != M - 1 && !unsat[comp[i][j + 1][0]]) {
                    int v = comp[i][j + 1][0] - idx1;
                    graph.addEdge(u, v);
                }
            }
        }
    }

    int ret = idx1 + idx2;
    for (int i = 1; i <= idx1 + idx2; i++) ret -= unsat[i];

    ret -= graph.get();

    cout << ret;

    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}