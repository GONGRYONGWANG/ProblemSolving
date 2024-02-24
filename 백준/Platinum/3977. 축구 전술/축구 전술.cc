//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
#include<stack>
#include<algorithm>
vector<vector<int>> edge;
vector<vector<int>> reedge;
vector<bool> visited;
int N, M;
stack<int> s;
vector<int> scc;
vector<vector<int>> sccs;
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
void Test() {
    cin >> N >> M;
    sccs.clear();
    edge.clear();
    reedge.clear();
    edge.resize(N);
    reedge.resize(N);
    visited.clear();
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        reedge[y].push_back(x);
    }
    for (int i = 0; i < N; i++) {
        DFS(i);
    }
    for (int i = 0; i < N; i++) {
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
    vector<int> sccnum;
    sccnum.resize(N);
    for (int i = 0; i < sccs.size(); i++) {
        for (int j = 0; j < sccs[i].size(); j++) {
            sccnum[sccs[i][j]] = i;
        }
    }
    vector<vector<int>> sccedge;
    vector<int> sccreedge;
    sccedge.resize(sccs.size());
    sccreedge.resize(sccs.size());
    for (int i = 0; i < sccs.size(); i++) {
        sccreedge[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < edge[i].size(); j++) {
            if (sccnum[i] == sccnum[edge[i][j]]) { continue; }
            sccedge[sccnum[i]].push_back(sccnum[edge[i][j]]);
            sccreedge[sccnum[edge[i][j]]] += 1;
        }
    }
    int cnt = 0;
    int startingscc = 0;
    for (int i = 0; i < sccs.size(); i++) {
        if (sccreedge[i] == 0) {
            startingscc = i;
            cnt++;
        }
    }
    if (cnt > 1) {
        cout << "Confused" << endl<<endl; return;
    }
    sort(sccs[startingscc].begin(), sccs[startingscc].end());
    for (int i = 0; i < sccs[startingscc].size(); i++) {
        cout << sccs[startingscc][i] << endl;
    }
    cout << endl;

    return;
}




int T;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> T;
    while (T--) {
        Test();
    }
    return 0;
}

