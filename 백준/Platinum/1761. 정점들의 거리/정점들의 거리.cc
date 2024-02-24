//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9



int N, M;
#include<vector>
#include<queue>
#include<utility>
vector<pair<int,int>> edge[40001];
pair<int,int> parent[40001][17];
int depth[40001];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int a, b,c;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    queue<int> Q;
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
            if (depth[edge[node][i].first]==-1) {
                parent[edge[node][i].first][0].first = node;
                parent[edge[node][i].first][0].second = edge[node][i].second;
                depth[edge[node][i].first] = d + 1;
                Q.push(edge[node][i].first);
            }
        }
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 1; j <= N; j++) {
            if (parent[j][i].first != 0) {
                parent[j][i + 1].first = parent[parent[j][i].first][i].first;
                parent[j][i + 1].second = parent[j][i].second + parent[parent[j][i].first][i].second;
            }
        }
    }


    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        int ans = 0;
        if (depth[b] > depth[a]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        int diff = depth[a] - depth[b];
        for (int j = 0; diff!= 0; j++) {
            if (diff % 2) {
                ans += parent[a][j].second;
                a = parent[a][j].first;
            }
            diff /= 2;
        }
        if (a == b) {
            cout << ans << endl; continue;
        }
        for (int j = 16; j >= 0; j--) {
            if (parent[a][j].first != 0 && parent[a][j].first != parent[b][j].first) {
                ans += parent[a][j].second;
                ans += parent[b][j].second;
                a = parent[a][j].first;
                b = parent[b][j].first;
            }
        }
        ans += parent[a][0].second;
        ans += parent[b][0].second;
        cout << ans << endl;
    }
    return 0;
}

