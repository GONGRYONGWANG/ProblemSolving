//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
#include<stack>
#include<algorithm>
int N, M;
vector<vector<int>> edge;
vector<vector<int>> reedge;
vector<bool> visited;
vector<int> scc;
vector<vector<int>> sccs;
stack<int> s;
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
    edge.clear();
    reedge.clear();
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


    sccs.clear();

    while (!s.empty()) {
        if (!visited[s.top()]) {
            scc.clear();
            reDFS(s.top());
            sccs.push_back(scc);
        }
        s.pop();
    }

    vector<int> sccnum;
    sccnum.resize(N + 1);
    for (int i = 0; i < sccs.size(); i++) {
        for (int j = 0; j < sccs[i].size(); j++) {
            sccnum[sccs[i][j]] = i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < sccs.size(); i++) {
        bool state = 0;
        for (int j = 0; j < sccs[i].size(); j++) {
            for (int k = 0; k < reedge[sccs[i][j]].size(); k++) {
                if (sccnum[reedge[sccs[i][j]][k]] == sccnum[sccs[i][j]]) { continue; }
                state = 1;
                break;
            }
            if (state) { break; }
        }
        if (!state) { cnt++; }
    }
    cout << cnt<<endl;


    return;
}








int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        Test();
    }

    return 0;
}

