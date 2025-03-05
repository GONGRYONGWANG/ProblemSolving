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
const ll INF = 1e18 + 7;
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
struct TwoSat {
    int n;
    vector<vector<int>> g, gr;
    vector<int> scc_id, order, answer;
    vector<bool> visited;

    TwoSat() {}
    TwoSat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        scc_id.resize(2 * n);
        visited.resize(2 * n, false);
        answer.resize(n);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    int var(int x, bool val) {
        return 2 * (abs(x) - 1) + (val ? 0 : 1);
    }

    void add_clause_or(int i, int j, bool fi = true, bool fj = true) {
        if (i < 0) { i = -i; fi = !fi; }
        if (j < 0) { j = -j; fj = !fj; }
        int u = var(i, fi), v = var(j, fj);
        add_edge(u ^ 1, v); // ~u -> v
        add_edge(v ^ 1, u); // ~v -> u
    }

    void add_clause_xor(int i, int j, bool fi = true, bool fj = true) {
        if (i < 0) { i = -i; fi = !fi; }
        if (j < 0) { j = -j; fj = !fj; }
        add_clause_or(i, j, fi, fj);
        add_clause_or(i, j, !fi, !fj);
    }

    void add_clause_xnor(int i, int j, bool fi = true, bool fj = true) {
        if (i < 0) { i = -i; fi = !fi; }
        if (j < 0) { j = -j; fj = !fj; }
        add_clause_xor(i, j, !fi, fj);
    }

    void dfs1(int u) {
        visited[u] = true;
        for (int v : g[u])
            if (!visited[v]) dfs1(v);
        order.push_back(u);
    }

    void dfs2(int u, int id) {
        visited[u] = true;
        scc_id[u] = id;
        for (int v : gr[u])
            if (!visited[v]) dfs2(v, id);
    }

    bool satisfiable() {
        fill(visited.begin(), visited.end(), false);
        order.clear();

        for (int i = 0; i < 2 * n; i++)
            if (!visited[i]) dfs1(i);

        fill(visited.begin(), visited.end(), false);
        reverse(order.begin(), order.end());

        int id = 0;
        for (int v : order)
            if (!visited[v]) dfs2(v, id++);

        for (int i = 0; i < n; i++) {
            if (scc_id[2 * i] == scc_id[2 * i + 1]) return false;
            answer[i] = (scc_id[2 * i] > scc_id[2 * i + 1] ? 1 : 0);
        }

        return true;
    }
};
///////////////////////////////////////////////////////////////


void solve(int tc) {

    int N, M, C, K;
    cin >> N >> M >> C >> K;
    TwoSat graph(N + 1);
    vector<bool> init(N + 1, false);
    while (M--) {
        int x;
        cin >> x;
        init[x] = true;
    }
    while (C--) {
        int u, v;
        cin >> u >> v;
        graph.add_clause_or(u, v);
        init[u] = false; init[v] = false;
    }
    while (K--) {
        int a, b;
        cin >> a >> b;
        graph.add_clause_or(-a, -b);
    }

    for (int i = 1; i <= N; i++) {
        if (init[i]) graph.add_clause_or(i, i);
    }

    if (graph.satisfiable()) cout << "YES";
    else cout << "NO";


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