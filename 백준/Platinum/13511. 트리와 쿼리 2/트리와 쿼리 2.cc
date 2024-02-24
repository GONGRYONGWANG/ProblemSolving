//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N,M;
#include<vector>
#include<utility>
#include<queue>
queue<int> Q;
pair<int, long> parent[100001][18];
int depth[100001];
vector<pair<int,int>> edge[100001];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int u, v, w;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({ v,w });
        edge[v].push_back({ u,w });
    }

    for (int i = 1; i <= N; i++) {
        depth[i] = -1;
    }
    Q.push(1);
    depth[1] = 0;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (int i = 0; i < edge[node].size(); i++) {
            if (depth[edge[node][i].first] == -1) {
                parent[edge[node][i].first][0].first = node;
                parent[edge[node][i].first][0].second = edge[node][i].second;
                Q.push(edge[node][i].first);
                depth[edge[node][i].first] = depth[node] + 1;
            }
        }
    }

    for (int i = 0; i < 17; i++) {
        for (int j = 1; j <= N; j++) {
            if (parent[j][i].first != 0) {
                parent[j][i + 1].first = parent[parent[j][i].first][i].first;
                parent[j][i + 1].second = parent[parent[j][i].first][i].second + parent[j][i].second;
            }
        }
    }


    cin >> M;
    int x;
    for (int i = 0; i < M; i++) {
        cin >> x >> u >> v;

        long long ans = 0;
        int ou = u;
        int ov = v;

        if (depth[v] > depth[u]) {
            int tmp = u;
            u = v;
            v = tmp;
        }

        int diff = depth[u] - depth[v];
        for (int j = 0; diff != 0; j++) {
            if (diff % 2) {
                ans += parent[u][j].second;
                u = parent[u][j].first;
            }
            diff /= 2;
        }

        if (u != v) {
            for (int j = 17; j >= 0; j--) {
                if (parent[u][j].first != 0 && parent[u][j].first != parent[v][j].first) {
                    ans += parent[u][j].second;
                    ans += parent[v][j].second;
                    u = parent[u][j].first;
                    v = parent[v][j].first;
                }
            }
            ans += parent[u][0].second;
            ans += parent[v][0].second;
            u = parent[u][0].first;
        }

        if (x == 1) {
            cout << ans << endl;
        }

        else {
            int k;
            cin >> k;
            k--;
            k = depth[ou] - k;
            
            if (k > depth[u]) {
                int diff = depth[ou] - k;
                for (int j = 0; diff != 0; j++) {
                    if (diff % 2) {
                        ou = parent[ou][j].first;
                    }
                    diff /= 2;
                }
                cout << ou <<endl;
            }

            else {
                int diff = depth[ov] + k - 2 * depth[u];
                for (int j = 0; diff != 0; j++) {
                    if (diff % 2) {
                        ov = parent[ov][j].first;
                    }
                    diff /= 2;
                }
                cout << ov <<endl;
            }
        }
    }
    return 0;
}

