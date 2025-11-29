#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
 
vector<pii> E[100001];
int parent[100001][20];
int to_parent[100001];
int depth[100001];
 
 
void solve(int tc) {
 
    int N, M, Q;
    cin >> N >> M >> Q;
 
    for (int i = 0; i < N - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        E[u].push_back({ v,d });
        E[v].push_back({ u,d });
    }
 
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto [nx, d] : E[x]) {
            if (nx == parent[x][0]) continue;
            parent[nx][0] = x;
            to_parent[nx] = d;
            depth[nx] = depth[x] + 1;
            q.push(nx);
        }
    }
 
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
 
    vector<int> arr(M + 1, 0);
    while (Q--) {
        int i, j;
        cin >> i >> j;
        arr[i] = j;
    }
 
    int ret = 0;
    int s = 1;
    int t = 1;
    int time = 0;
    for (int i = 0; i < M; i++) {
 
        if (arr[i]) t = arr[i];
        if (time > i) continue;
 
        if (s == t) ret += 1;
        else {
            if (depth[s] >= depth[t]) {
                time = i + to_parent[s];
                s = parent[s][0];
            }
            else {
                int d = depth[t] - depth[s] - 1;
                int tmp = t;
                for (int j = 0; j < 20; j++) {
                    if (d & (1 << j)) tmp = parent[tmp][j];
                }
                if (parent[tmp][0] == s) {
                    time = i + to_parent[tmp];
                    s = tmp;
                }
                else {
                    time = i + to_parent[s];
                    s = parent[s][0];
                }
            }
        }
    }
 
    cout << ret;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
 
    return 0;
}