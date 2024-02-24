#pragma warning(disable:4996) 
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

struct cmp {
    bool operator()(vector<ll>a, vector<ll>b) {
        return a[1] > b[1];
    }
};

ll visited[10001][21];
vector<pll> E[10001];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            visited[i][j] = 1e18;
        }
    }
    priority_queue<vector<ll>,vector<vector<ll>>, cmp> q;
    q.push({ 1,0,0 });
    while (!q.empty()) {
        vector<ll> node = q.top();
        q.pop();
        ll x = node[0];
        ll d = node[1];
        ll k = node[2];
        if (x == N) {
            cout << d;
            return 0;
        }
        if (visited[x][k]<d) continue;
        for (pll e : E[x]) {
            ll nx = e.first;
            ll nd = e.second + d;
            if (visited[nx][k] > nd) {
                q.push({ nx,nd,k });
                visited[nx][k] = nd;
            }
            if (k!=K && visited[nx][k + 1]>d) {
                q.push({ nx,d,k + 1 });
                visited[nx][k + 1] = d;
            }
        }
    }
    return 0;
}