#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9


int V, E;
#include<vector>
#include<utility>
#include<algorithm>

int dist[401][401];



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dist[i][j] = INF;
        }
    }
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for (int m = 1; m <= V; m++) {
        for (int i = 1; i < V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][j] > dist[i][m] + dist[m][j]) {
                    dist[i][j] = dist[i][m] + dist[m][j];
                }
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= V; i++) {
        ans = min(ans, dist[i][i]);
    }
    if (ans == INF) { cout << -1; }
    else { cout << ans; }
    return 0;
}
