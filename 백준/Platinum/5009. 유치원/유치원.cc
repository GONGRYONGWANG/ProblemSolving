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
#define INF ll(1e18+7)
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
struct TwoSat { // for SCC and TwoSat.
    int n;
    vector<vector<int>> g, gr; // gr is the reversed graph
    vector<int> scc_id, topological_order, answer; // scc_id[v]: ID of the SCC containing node v
    vector<bool> visited;

    TwoSat() {}

    TwoSat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        scc_id.resize(2 * n);
        visited.resize(2 * n);
        answer.resize(2 * n);
    }

    // Can be used conveniently for SCC tasks by using the edge function only. The drawback is double memory usage.
    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // For the following three functions
    // int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.

    // At least one of them is true
    void add_clause_or(int i, int j, bool f = true, bool g = true) {
        if (i < 0) f = !f;
        if (j < 0) g = !g;
        i = abs(i); j = abs(j);
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int i, int j, bool f = true, bool g = true) {
        if (i < 0) {
            add_clause_xor(-i, j, !f, g);
            return;
        }
        if (j < 0) {
            add_clause_xor(i, -j, f, !g);
            return;
        }
        add_clause_or(i, j, f, g);
        add_clause_or(i, j, !f, !g);
    }

    // Both of them have the same value
    void add_clause_xnor(int i, int j, bool f = true, bool g = true) {
        add_clause_xor(i, j, !f, g);
    }

    // Topological sort
    void dfs(int u) {
        visited[u] = true;

        for (const auto& v : g[u])
            if (!visited[v]) dfs(v);

        topological_order.push_back(u);
    }

    // Extracting strongly connected components
    void scc(int u, int id) {
        visited[u] = true;
        scc_id[u] = id;

        for (const auto& v : gr[u])
            if (!visited[v]) scc(v, id);
    }

    // Returns true if the given proposition is satisfiable and constructs a valid assignment
    bool satisfiable() {
        fill(visited.begin(), visited.end(), false);

        for (int i = 0; i < 2 * n; i++)
            if (!visited[i]) dfs(i);

        fill(visited.begin(), visited.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;
        for (const auto& v : topological_order)
            if (!visited[v]) scc(v, id++);

        // Constructing the answer
        for (int i = 0; i < n; i++) {
            if (scc_id[i] == scc_id[i + n]) return false;
            answer[i] = (scc_id[i] > scc_id[i + n] ? 1 : 0);
        }

        return true;
    }

};
///////////////////////////////////////////////////////////////

int arr[201][200];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int l = 0;
    int r = N - 1;
    while (l < r) {
        int m = (l + r) / 2;
        TwoSat graph(3 * N + 1);
        for (int i = 1; i <= N; i++) {
            if (arr[i][0] == 0) {
                graph.add_clause_or(-i, -i);
                graph.add_clause_xor(i + N, i + 2 * N);
            }
            else if (arr[i][0] == 1) {
                graph.add_clause_or(-(i + N), -(i + N));
                graph.add_clause_xor(i, i + 2 * N);
            }
            else {
                graph.add_clause_or(-(i + 2 * N), -(i + 2 * N));
                graph.add_clause_xor(i, i + N);
            }

            for (int j = m + 1; j < N; j++) {
                int x = arr[i][j];
                graph.add_clause_or(-i, -x);
                graph.add_clause_or(-(i + N), -(x + N));
                graph.add_clause_or(-(i + 2 * N), -(x + 2 * N));
            }

        }
        if (graph.satisfiable()) r = m;
        else l = m + 1;
    }

    cout << l;



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