#pragma warning(disable:4996)
//#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
#include<stack>
#include<algorithm>
int N, M, S, T;
vector<vector<int>> edge;
vector<vector<int>> reedge;
stack<int> s;
vector<bool> visited;
vector<int> scc;
vector<vector<int>> sccs;
vector<int> sccnum;
vector<int> scc_size;
vector<vector<int>> scc_edge;
int scc_start, scc_end;
void DFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        DFS(edge[node][i]);
    }
    s.push(node);
    return;
}
void reDFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < reedge[node].size(); i++) {
        reDFS(reedge[node][i]);
    }
    scc.push_back(node);
    return;
}

vector<int> DP;

int dp(int node) {
    if (DP[node] != -1) { return DP[node]; }
    if (node == scc_end) { return scc_size[node]; }
    int rt = 0;
    for (int i = 0; i < scc_edge[node].size(); i++) {
        rt = max(rt, dp(scc_edge[node][i]));
    }
    if (rt != 0) {
        return DP[node] = rt + scc_size[node];
    }
    return DP[node] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M >> S >> T;

    edge.resize(N + 1);
    reedge.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        reedge[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) {
        DFS(i);
    }
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }

    while (!s.empty()) {
        if (!visited[s.top()]) {
            scc.clear();
            reDFS(s.top());
            sccs.push_back(scc);
        }
        s.pop();
    }

    sccnum.resize(N + 1);
    scc_size.resize(sccs.size());
    for (int i = 0; i < sccs.size(); i++) {
        scc_size[i] = 0;
    }
    scc_edge.resize(sccs.size());
    for (int i = 0; i < sccs.size(); i++) {
        for (int j = 0; j < sccs[i].size(); j++) {
            sccnum[sccs[i][j]] = i;
            scc_size[i] += 1;
            if (sccs[i][j] == S) {
                scc_start = i;
            }
            if (sccs[i][j] == T) {
                scc_end = i;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < edge[i].size(); j++) {
            int node = edge[i][j];
            if (sccnum[i] == sccnum[node]) { continue; }
            scc_edge[sccnum[i]].push_back(sccnum[node]);
        }
    }
    for (int i = 0; i < sccs.size(); i++) {
        scc_edge[i].erase(unique(scc_edge[i].begin(), scc_edge[i].end()), scc_edge[i].end());
    }
    DP.resize(sccs.size());
    for (int i = 0; i < sccs.size(); i++) {
        DP[i] = -1;
    }

    cout << dp(scc_start);


    return 0;
}

