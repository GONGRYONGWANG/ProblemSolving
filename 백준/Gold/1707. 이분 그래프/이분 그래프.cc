//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

vector<vector<int>> edge;
vector<int> color;

void DFS(int node, int col) {
    color[node] = col;
    for (int i = 0; i < edge[node].size(); i++) {
        if (!color[edge[node][i]]) {
            DFS(edge[node][i], col % 2 + 1);
        }
    }
    return;
}

void solve() {
    int V, E;
    cin >> V >> E;
    
    edge.resize(V + 1);
    for (int i = 0; i <= V; i++) {
        edge[i].clear();
    }
    color.clear();
    color.resize(V + 1, 0);
    int x, y;
    for (int i = 0; i < E; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= V; i++) {
        if (!color[i]) {
            DFS(i,1);
        }
    }
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < edge[i].size(); j++) {
            if (color[i] == color[edge[i][j]]) {
                cout << "NO" << endl;  return;
            }
        }
    }
    cout << "YES" << endl; 
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int K;
    cin >> K;
    while (K--) {
        solve();
    }
    return 0;
}