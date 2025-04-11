// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
#define INF ll(9e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


pll parent[200001][18];
int depth[200001];

vector<pll> E[200001];
struct cmp {
    bool operator()(vector<ll>& a, vector<ll>& b) {
        return a[2] > b[2];
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<vector<ll>> edges(M);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
        edges[i] = { u,v,w };
    }

    ll total = 0;

    vector<bool> visited(N + 1, false);
    pq<vector<ll>, vector<vector<ll>>, cmp> q; // x,p,d
    q.push({ 1,0,0 });
    while (!q.empty()) {
        int x = q.top()[0];
        int p = q.top()[1];
        ll d = q.top()[2];
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        total += d;
        parent[x][0] = { p,d };
        depth[x] = depth[p] + 1;
        for (pll& e : E[x]) {
            if (visited[e.first]) continue;
            q.push({ e.first,x,e.second });
        }
    }


    for (int j = 1; j < 18; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = { parent[parent[i][j - 1].first][j - 1].first, max(parent[parent[i][j - 1].first][j - 1].second , parent[i][j - 1].second) };
        }
    }

    for (vector<ll>& e : edges) {
        int u = e[0]; int v = e[1]; ll w = e[2];
        ll ret = total + e[2];
        if (depth[u] < depth[v]) swap(u, v);
        int d = depth[u] - depth[v];
        ll mx = 0;

        for (int j = 0; j < 18; j++) {
            if (d & (1 << j)) {
                mx = max(mx, parent[u][j].second);
                u = parent[u][j].first;
            }
        }

        if (u != v) {
            for (int j = 17; j >= 0; j--) {
                if (parent[u][j].first != parent[v][j].first) {
                    mx = max(mx, parent[u][j].second);
                    mx = max(mx, parent[v][j].second);
                    u = parent[u][j].first;
                    v = parent[v][j].first;
                }
            }
            mx = max(mx, parent[u][0].second);
            mx = max(mx, parent[v][0].second);
        }

        ret -= mx;

        cout << ret << endl;
    }



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