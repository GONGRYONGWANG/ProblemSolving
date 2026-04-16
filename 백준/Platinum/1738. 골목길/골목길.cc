#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18
int N, M;
#include<vector>
#include<utility>
#include<queue>
vector<pair<int, int>> line[101];
long long dist[101];
bool cycle[101];
int parent[101];
queue<int> Q;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int u, v, w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        line[u].push_back({ v,w });
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = -INF;
    }
    dist[1] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < line[j].size(); k++) {
                if (dist[j] != -INF && dist[line[j][k].first] < dist[j] + line[j][k].second) {
                    dist[line[j][k].first] = dist[j] + line[j][k].second;
                    parent[line[j][k].first] = j;
                    if (i == N) {
                        Q.push(line[j][k].first);
                    }
                }
            }
        }
    }
    if (dist[N] == -INF) { cout << -1; return 0; }

    while (!Q.empty() && !cycle[N]) {
        int node = Q.front();
        if (cycle[node]) { Q.pop(); continue; }
        cycle[node] = 1;
        for (int i = 0; i < line[node].size(); i++) {
            if (!cycle[line[node][i].first]) {
                Q.push(line[node][i].first);
            }
        }
    }
    if (cycle[N]) {
        cout << -1; return 0;
    }
    vector<int> ans;
    int node = N;
    while (node != 1) {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(1);
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}
