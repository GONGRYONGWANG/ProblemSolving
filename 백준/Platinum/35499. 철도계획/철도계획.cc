#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int parent[100001];
bool cycle[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}
 
void solve(int tc) {
 
    int N, M;
    cin >> N >> M;
 
    for (int i = 1; i <= N; i++) parent[i] = i;
   
    vector<tuple<ll, int, int>> edge(M);
    for (auto& [w, u, v] : edge) {
        cin >> u >> v >> w;
    }
 
    sort(edge.rbegin(), edge.rend());
 
    ll ret = 0;
    for (auto& [w, u, v] : edge) {
        u = findp(u); v = findp(v);
        if (u == v && cycle[u]) continue;
        if(cycle[u]&&cycle[v]) continue;
        ret += w;
        if (u != v) {
            parent[v] = u;
            cycle[u] |= cycle[v];
        }
        else {
            cycle[u] = true;
        }
    }
 
    cout << ret;
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
