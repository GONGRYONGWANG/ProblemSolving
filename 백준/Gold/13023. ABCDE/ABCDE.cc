//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int N, M;
vector<vector<int>> edge;
vector<bool> visited;
int len;
bool dfs(int node) {
    len += 1;
    visited[node] = 1;
    if (len >= 5) return 1;
    for (int i = 0; i < edge[node].size(); i++) {
        if (!visited[edge[node][i]]) {
            if (dfs(edge[node][i])) return 1;
        }
    }
    len -= 1;
    visited[node] = 0;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N >> M;
    int a, b;
    edge.resize(N);
    visited.resize(N,0);
    while (M--) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    len = 0;
    for (int i = 0; i < N; i++) {
        if (dfs(i)) {
            cout << 1; return 0;
        }
    }
    cout << 0;
    return 0;
}