//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
#include<algorithm>
#include<stack>
int N, M;
int S, P;
stack<int> s;
vector<vector<int>> edge;
vector<vector<int>> reedge;
vector<long long> cash;
vector<bool> isrest;
vector<bool> visited;
vector<int> scc;
vector<vector<int>> sccs;
vector<long long> scc_cash;
vector<bool> scc_isrest;
vector<int> sccnum;
vector<vector<int>> scc_edge;
int scc_start;

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



vector<long long> DP;

long long dp(int node) {
    if (DP[node] != -1) { return DP[node]; }
    long long rt = 0;
    for (int i = 0; i < scc_edge[node].size(); i++) {
        rt = max(rt, dp(scc_edge[node][i]));
    }
    if (rt == 0) {
        if (!scc_isrest[node]) {
            return DP[node] = 0;
        }
        else {
            return DP[node] = scc_cash[node];
        }
    }
    return DP[node] = rt + scc_cash[node];
}



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;

    edge.resize(N+1);
    reedge.resize(N+1);
    cash.resize(N + 1);
    isrest.resize(N + 1);
    visited.resize(N + 1);
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        reedge[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) {
        cin >> cash[i];
        isrest[i] = 0;
        visited[i] = 0;
    }
    cin >> S >> P;
    for (int i = 0; i < P; i++) {
        cin >> x;
        isrest[x] = 1;
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
    scc_edge.resize(sccs.size());
    scc_cash.resize(sccs.size());
    scc_isrest.resize(sccs.size());
    for (int i = 0; i < sccs.size(); i++) {
        scc_cash[i] = 0;
        scc_isrest[i] = 0;
        for (int j = 0; j < sccs[i].size(); j++) {
            sccnum[sccs[i][j]] = i;
            scc_cash[i] += cash[sccs[i][j]];
            if (isrest[sccs[i][j]]) {
                scc_isrest[i] = 1;
            }
            if (sccs[i][j] == S) {
                scc_start = i;
            }
        }
    }
    
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < edge[i].size(); j++) {
            if (sccnum[i]==sccnum[edge[i][j]]) { continue; }
            scc_edge[sccnum[i]].push_back(sccnum[edge[i][j]]);
        }
        scc_edge[sccnum[i]].erase(unique(scc_edge[sccnum[i]].begin(), scc_edge[sccnum[i]].end()), scc_edge[sccnum[i]].end());
    }

    DP.resize(sccs.size());
    for (int i = 0; i < sccs.size(); i++) {
        DP[i] = -1;
    }
    cout << dp(scc_start);

    return 0;
}

