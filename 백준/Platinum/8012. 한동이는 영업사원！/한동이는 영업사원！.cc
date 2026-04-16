//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9


int N, M;
int parent[30001][16];
#include<vector> 
vector<int> edge[30001];
int depth[30001];
#include<queue>
queue<int> Q;
#include<algorithm>


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    Q.push(1);
    for (int i = 1; i <= N; i++) {
        depth[i] = -1;
    }
    depth[1] = 0;
    while (!Q.empty()) {
        int node = Q.front();
        int d = depth[node];
        Q.pop();
        for (int i = 0; i < edge[node].size(); i++) {
            if (depth[edge[node][i]] == -1) {
                Q.push(edge[node][i]);
                depth[edge[node][i]] = d + 1;
                parent[edge[node][i]][0] = node;
            }
        }
    }

    //bottom-up으로 parent 채우기
    for (int i = 0; i < 15; i++) {
        for (int j = 2; j <= N; j++) {
            if (parent[j][i] != 0) {
                parent[j][i + 1] = parent[parent[j][i]][i];
            }
        }
    }


    //###############################################

    cin >> M;
    int ans = 0;
    int u, v;
    cin >> u;
    ans += depth[u];
    for (int i = 0; i < M - 1; i++) {
        cin >> v;
        int ov = v;
        ans += depth[u] + depth[v];
        if (depth[u] < depth[v]) {
            int tmp = u;
            u = v;
            v = tmp;
        }
        int diff = depth[u] - depth[v];
        for (int j = 0; diff != 0; j++) {
            if (diff % 2) { u = parent[u][j]; }
            diff /= 2;
        }
        if (u != v) {
            for (int j = 15; j >= 0; j--) {
                if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        ans -= depth[u] * 2;
        u = ov;
    }
    cout << ans;

    return 0;
}

