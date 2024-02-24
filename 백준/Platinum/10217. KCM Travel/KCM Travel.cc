#pragma warning(disable:4996) 
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<utility>
#include<string>
#include<set>
#include<unordered_set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
#define inf 1e9

int dist[101][10001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<vector<int>>> E(N+1);
    for (int i = 0; i < K; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        E[u].push_back({ v,c,d });
    }

    int ans = 1e9;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dist[i][j] = inf;
        }
    }

    queue<vector<int>> q;
    q.push({ 1,0,0 });
    while (!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        int x = node[0];
        int c = node[1];
        int d = node[2];
        if (c > M) continue;
        if (dist[x][c] < d) continue;
        if (x == N) ans = min(ans, d);
        for (int i = 0; i < E[x].size(); i++) {
            int nx, nc, nd;
            nx = E[x][i][0];
            nc = E[x][i][1] + c;
            nd = E[x][i][2] + d;
            if (nc > M) continue;
            if (dist[nx][nc] <= nd) continue;
            for (int j = nc + 1; j <= M; j++) {
                if (dist[nx][j] <= nd) break;
                dist[nx][j] = nd;
            }
            dist[nx][nc] = nd;
            q.push({ nx,nc,nd });
        }
    }

    if (ans == inf) cout << "Poor KCM";
    else cout << ans;

    return 0;
}