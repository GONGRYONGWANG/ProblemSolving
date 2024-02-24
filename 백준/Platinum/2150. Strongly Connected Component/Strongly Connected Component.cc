#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int V, E;
#include<vector>
#include<algorithm>
vector<int>edge[10001];
vector<int>reedge[10001];
#include<stack>
stack<int> s;
bool visited[10001];
void DFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        if (!visited[edge[node][i]]) {
            DFS(edge[node][i]);
        }
    }
    s.push(node);
    return;
}

vector<vector<int>> result;
vector<int> ans;
void reDFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < reedge[node].size(); i++) {
        if (!visited[reedge[node][i]]) {
            reDFS(reedge[node][i]);
        }
    }
    ans.push_back(node);
    return;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> V >> E;
    int u, v;

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        reedge[v].push_back(u);
    }


    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    for (int i = 1; i <= V; i++) {
        visited[i] = 0;
    }

    while (!s.empty()) {
        if (!visited[s.top()]) {
            ans.clear();
            reDFS(s.top());
            sort(ans.begin(), ans.end());
            result.push_back(ans);
        }
        s.pop();
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << -1 << endl;
    }
    return 0;
}
