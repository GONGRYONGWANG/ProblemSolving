#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(4e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


vector<int> E[200001];

vector<int> ret;
int parent[200001];
int sz[200001];
vector<pll> child[200001];

void getsz(int x) {
    sz[x] = 1;
    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        parent[nx] = x;
        getsz(nx);
        sz[x] += sz[nx];
        child[x].push_back({ sz[nx],nx });
    }
    sort(child[x].rbegin(), child[x].rend());
}
void dfs(int x) {
    for (int i = 0; i < child[x].size(); i++) {
        int c = child[x][i].second;
        dfs(c);
    }
    ret.push_back(x);
}

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    getsz(1);
    dfs(1);

    for (int x : ret) cout << x << " ";






}




int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}