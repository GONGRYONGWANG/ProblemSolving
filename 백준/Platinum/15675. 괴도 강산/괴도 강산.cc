#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18
#include<vector>
#include<stack>
vector<vector<int>> edge;
vector<vector<int>> reedge;
vector<bool> visited;
vector<int> check;
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
int cnt;
void reDFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < reedge[node].size(); i++) {
        reDFS(reedge[node][i]);
    }
    check[node] = cnt;
    return;
}

int N, M;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    edge.resize(2 * (N + M) + 1);
    reedge.resize(2 * (N + M) + 1);
    visited.resize(2 * (N + M) + 1);
    check.resize(2 * (N + M) + 1);
    char x;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> x;
            if (x == '#') {
                edge[i].push_back(N + j);
                edge[N + j].push_back(i);
                edge[i + N + M].push_back(N + M + N + j);
                edge[N + M + N + j].push_back(i + N + M);
                reedge[i].push_back(N + j);
                reedge[N + j].push_back(i);
                reedge[i + N + M].push_back(N + M + N + j);
                reedge[N + M + N + j].push_back(i + N + M);
            }
            if (x == '*') {
                edge[i].push_back(N + M + N + j);
                edge[N + M + N + j].push_back(i);
                edge[i + N + M].push_back(N + j);
                edge[N + M + N + j].push_back(i);
                reedge[i].push_back(N + M + N + j);
                reedge[N + M + N + j].push_back(i);
                reedge[i + N + M].push_back(N + j);
                reedge[N + M + N + j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= 2 * (N + M); i++) {
        visited[i] = 0;
    }

    for (int i = 1; i <= 2*(N+M); i++) {
        DFS(i);
    }

    for (int i = 1; i <= 2 * (N + M); i++) {
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
    for (int i = 1; i <= (N + M); i++) {
        if (check[i] == check[i + N + M]) {
            cout << 0; return 0;
        }
    }
    cout << 1;
    return 0;
}

