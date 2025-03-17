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
const ll INF = 1e18 + 7;
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


vector<pii> E[300001];
int depth[300001];
pii parent[300001][19];
void dfs(int x) {
    for (auto [nx, d] : E[x]) {
        if (nx == parent[x][0].first) continue;
        depth[nx] = depth[x] + 1;
        parent[nx][0] = { x,d };
        dfs(nx);
    }
}

pii lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int d = depth[u] - depth[v];
    int ret = 0;
    for (int i = 0; i < 19; i++) {
        if (d & (1 << i)) {
            ret = max(ret, parent[u][i].second);
            u = parent[u][i].first;
        }
    }

    if (u == v) return { u,ret };
    
    for (int i = 18; i >= 0; i--) {
        if (parent[u][i].first == parent[v][i].first) continue;
        ret = max(ret, max(parent[u][i].second, parent[v][i].second));
        u = parent[u][i].first; v = parent[v][i].first;
    }

    ret = max(ret, max(parent[u][0].second, parent[v][0].second));
    return { parent[u][0].first,ret };
}

pii mer(pii a, pii b) {
    if (a.first == 0) return b;
    if (b.first == 0) return a;
    pii ret = lca(a.first, b.first);
    ret.second = max(ret.second, max(a.second, b.second));
    return ret;
}


pii tree[1200000];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = { start, 0 };
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}
pii get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return { 0,0 };
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void solve(int tc) {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    parent[1][0] = { 0,0 };
    dfs(1);

    for (int j = 1; j < 19; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = { parent[parent[i][j - 1].first][j - 1].first, max(parent[i][j - 1].second ,parent[parent[i][j - 1].first][j - 1].second) };
        }
    }

    makeTree(1, 1, N);

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, N, l, r).second<< endl;
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