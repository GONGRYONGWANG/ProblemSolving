// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
#include<chrono>
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
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<pii> E[1001];
pll parent[1001][11];
int depth[1001];

ll dist(int u, int v) {
    ll ret = 0;
    if (depth[u] < depth[v]) swap(u, v);
    int d = depth[u] - depth[v];
    for (int j = 0; j <= 10; j++) {
        if (d & (1 << j)) {
            ret += parent[u][j].second;
            u = parent[u][j].first;
        }
    }
    if (u == v) return ret;
    for (int j = 10; j >= 0; j--) {
        if (parent[u][j].first != parent[v][j].first) {
            ret += parent[u][j].second + parent[v][j].second;
            u = parent[u][j].first;
            v = parent[v][j].first;
        }
    }
    ret += parent[u][0].second;
    ret += parent[v][0].second;
    return ret;
}
 
void solve(int tc) {
    
    int N, M;
    cin >> N >> M;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    for (int i = 1; i <= N; i++) {
        sort(E[i].begin(), E[i].end());
    }

    vector<int> v;
    queue<int> q;
    q.push(1);
    depth[1] = 1;
    parent[1][0] = { 0,0 };
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        v.push_back(x);
        for (auto& [nx,d] : E[x]) {
            if (depth[nx]) continue;
            depth[nx] = depth[x] + 1;
            parent[nx][0] = { x,d };
            q.push(nx);
        }
    }
    v.push_back(1);

    for (int j = 1; j <= 10; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j].first = parent[parent[i][j - 1].first][j - 1].first;
            parent[i][j].second = parent[parent[i][j - 1].first][j - 1].second + parent[i][j - 1].second;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dist(v[i - 1], v[i]);
    }

    cout << ans;



}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}