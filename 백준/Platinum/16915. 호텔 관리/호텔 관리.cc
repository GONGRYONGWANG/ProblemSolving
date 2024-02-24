#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18


int N, M;
#include<vector>
#include<stack>
#include<algorithm>
vector<vector<int>> sw;
vector<bool> arr;
vector<vector<int>> edge;
vector<vector<int>> reedge;
stack<int> s;
vector<bool> visited;
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
    check[node] = cnt;
    for (int i = 0; i < reedge[node].size(); i++) {
        reDFS(reedge[node][i]);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    sw.resize(N + 1);
    arr.resize(N + 1);
    edge.resize(2 * M + 1);
    reedge.resize(2 * M + 1);
    visited.resize(2 * M + 1);
    check.resize(2 * M + 1);
    bool b;
    for (int i = 1; i <= N; i++) {
        cin >> b;
        arr[i] = b;
    }
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        int x;
        for (int j = 0; j < k; j++) {
            cin >> x;
            sw[x].push_back(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        int a = sw[i][0];
        int b = sw[i][1];
        if (arr[i]) {
            edge[a].push_back(b);
            edge[a+M].push_back(b+M);
            edge[b].push_back(a);
            edge[b + M].push_back(a + M);
            reedge[a].push_back(b);
            reedge[a + M].push_back(b + M);
            reedge[b].push_back(a);
            reedge[b + M].push_back(a + M);
        }
        else {
            edge[a].push_back(b+M);
            edge[a + M].push_back(b);
            edge[b].push_back(a+M);
            edge[b + M].push_back(a);
            reedge[a].push_back(b + M);
            reedge[a + M].push_back(b);
            reedge[b].push_back(a + M);
            reedge[b + M].push_back(a);
        }
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
    for (int i = 1; i <= M;i++) {
        if (check[i] == check[i + M]) {
            cout << 0; return 0;
        }
    }
    cout << 1;
    return 0;
}

