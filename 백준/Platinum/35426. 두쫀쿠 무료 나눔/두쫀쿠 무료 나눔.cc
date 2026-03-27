#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pq priority_queue
 
 
vector<pll> E[100001];
struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};
 
bool visited[100001];
 
void solve(int tc) {
 
    int N, M;
    cin >> N >> M;
    while (M--) {
        int p, q; ll w;
        cin >> p >> q >> w;
        if (w % 2 == 0) continue;
        w *= (q - p + 1);
        E[p - 1].push_back({ q,w });
        E[q].push_back({ p - 1,w });
    }
 
    pq<pll, vector<pll>, cmp> q;
    q.push({ 0,0 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        if (x == N) {
            cout << d;
            return;
        }
        for (auto& [nx, w] : E[x]) {
            if (visited[nx]) continue;
            q.push({ nx,d + w });
        }
    }
 
    cout << "Dujjonku so expensive T.T";
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
