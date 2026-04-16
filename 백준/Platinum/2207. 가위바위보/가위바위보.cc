#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18

int N, M;
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath>
vector<vector<int>> edge;
vector<vector<int>> reedge;
vector<bool> visited;
stack<int> s;
vector<int> check;
int cnt;
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
    check[node] = cnt;
    return;
}
int Not(int node) {
    if (node <= M) {
        return node + M;
    }
    return node - M;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    edge.resize(2 * M + 1);
    reedge.resize(2 * M + 1);
    visited.resize(2 * M + 1);
    check.resize(2 * M + 1);
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (x < 0) {
            x = abs(x) + M;
        }
        if (y < 0) {
            y = abs(y) + M;
        }
        edge[Not(x)].push_back(y);
        edge[Not(y)].push_back(x);
        reedge[y].push_back(Not(x));
        reedge[x].push_back(Not(y));
    }
    for (int i = 1; i <= 2 * M; i++) {
        visited[i] = 0;
    }
    for (int i = 1; i <= 2 * M; i++) {
        DFS(i);
    }
    for (int i = 1; i <= 2 * M; i++) {
        visited[i] = 0;
    }
    cnt = 0;
    while (!s.empty()) {
        if (!visited[s.top()]) {
            cnt++;
            reDFS(s.top());
        }
        s.pop();
    }
    for (int i = 1; i <= M; i++) {
        if (check[i] == check[i + M]) {
            cout << "OTL"; return 0;
        }
    }
    cout << "^_^";
    return 0;
}

