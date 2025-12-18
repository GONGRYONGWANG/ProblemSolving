#include <bits/stdc++.h>
using namespace std;
#define inf 1e9+7

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

    // if i then j
    void add_clause_then(int i, int j, bool f = true, bool g = true) {
        if (i < 0) f = !f;
        if (j < 0) g = !g;
        i = abs(i); j = abs(j);
        add_edge(i + (f ? 0 : n), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? n : 0));
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

    void add_clause_not(int i, bool f = true) {
        add_clause_or(i, i, !f, !f);
    }

    void add_clause_nand(int i, int j, bool f = true, bool g = true) {
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

int arr[101];
int sz[201];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
    
    for(int i=1; i<=N;i++) cin>>arr[i];
    
    TwoSat graph(N+1);
    for(int i=1; i<=N;i++){
        for(int j=1; j<=N;j++){
            char x; cin>>x;
            if(x=='1') graph.add_edge(i,j);
        }
    }
    
    graph.satisfiable();
    
    
    for(int i=1; i<=2*N;i++){
        sz[i] = inf;
    }
    
    for(int i=1; i<=N;i++){
        sz[graph.scc_id[i]] = min(sz[graph.scc_id[i]], arr[i]);
    }
    
    int ret= 0;
    for(int i=1; i<=2*N;i++){
        if(sz[i]!=inf) ret += sz[i];
    }
    
    cout<<ret;
    
    return 0;
}
