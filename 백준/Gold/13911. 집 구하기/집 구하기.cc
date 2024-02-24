//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

struct cmp {
    bool operator()(pll a, pll b) {
        return a.second > b.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int V, E;
    cin >> V >> E;
    vector<vector<pii>> edge(V + 2);
    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({ v,w });
        edge[v].push_back({ u,w });
    }

    ll M, x;
    cin >> M >> x;
    for (int i = 0; i < M; i++) {
        cin >> u;
        edge[0].push_back({ u,0 });
    }

    ll S, y;
    cin >> S >> y;
    for (int i = 0; i < S; i++) {
        cin >> u;
        edge[V + 1].push_back({ u,0 });
    }

    pq<pll, vector<pll>, cmp> q;
    vector<ll> mc(V + 2, -1);
    q.push({ 0,0 });
    while (!q.empty()) {
        ll node = q.top().first;
        ll dist = q.top().second;
        q.pop();
        if (dist > x) break;
        if (mc[node]!=-1) continue;
        mc[node] = dist;
        for (int i = 0; i < edge[node].size(); i++) {
            if (mc[edge[node][i].first]==-1 && dist + edge[node][i].second <= x) {
                q.push({ edge[node][i].first,dist + edge[node][i].second });
            }
        }
    }

    while (!q.empty()) q.pop();

    vector<ll> st(V + 2, -1);
    q.push({ V + 1,0 });
    while (!q.empty()) {
        int node = q.top().first;
        ll dist = q.top().second;
        q.pop();
        if (dist > y) break;
        if (st[node]!=-1) continue;
        st[node] = dist;
        for (int i = 0; i < edge[node].size(); i++) {
            if (st[edge[node][i].first] ==-1&& dist + edge[node][i].second <= y) {
                q.push({ edge[node][i].first,dist + edge[node][i].second });
            }
        }
    }

    ll ans = 1e10;
    for (int i = 1; i <= V; i++) {
        if (mc[i]>0 && st[i]>0) {
            ans = min(ans, mc[i] + st[i]);
        }
    }
    if (ans == 1e10) cout << -1;
    else cout << ans;

    return 0;
}