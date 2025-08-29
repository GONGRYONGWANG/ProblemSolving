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

vector<int> E[100001];
int sz[100001], depth[100001], parent[100001], top[100001], in[100001];
int hchild[100001]; // heavy child

void dfs1(int x) { // get parent and heavy child of each node
    sz[x] = 1;
    for (int& nx : E[x]) {
        if (parent[x] == nx) continue;
        depth[nx] = depth[x] + 1;
        parent[nx] = x;
        dfs1(nx);
        sz[x] += sz[nx];
        if (sz[nx] > sz[hchild[x]]) hchild[x] = nx;
    }
}

int idx = 0;
void dfs2(int x) { // assign dfs order (HLD tree index)
    idx += 1;
    in[x] = idx;
    if (hchild[x]) { // if not leaf
        top[hchild[x]] = top[x];
        dfs2(hchild[x]);
    }
    for (auto nx : E[x]) {
        if (parent[x] == nx) continue;
        if (nx == hchild[x]) continue;
        top[nx] = nx;
        dfs2(nx);
    }
    // out[x] = idx  // ETT variation
}

ll tree[400000];
ll lazy[400000];
void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, ll w) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = w;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, w);
    update(node * 2 + 1, mid + 1, end, left, right, w);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll get(int node, int start, int end, int x) {
    lazyProp(node, start, end);
    if (x > end || x < start) return 0;
    if (start == end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, x) + get(node * 2 + 1, mid + 1, end, x);
}

void updatequery(int a, int b, ll w) {
    while(top[a] != top[b]) {
        if (depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        update(1, 1, idx, in[st], in[a], w);
        a = parent[st];
    }
    if (depth[a] > depth[b]) swap(a, b);
    update(1, 1, idx, in[a], in[b], w);
    update(1, 1, idx, in[a], in[a], -w);
}


void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    dfs1(1); dfs2(1); 

    while (M--) {
        char q;
        cin >> q;
        if (q == 'P') {
            int u, v;
            cin >> u >> v;
            updatequery(u, v, 1);
        }
        else {
            int u, v;
            cin >> u >> v;
            if (u == parent[v]) swap(u, v);
            cout << get(1, 1, N, in[u]) << endl;
        }
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