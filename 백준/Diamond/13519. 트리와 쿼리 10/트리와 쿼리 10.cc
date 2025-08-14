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


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

struct treeNode {
    int sum = inf, l = 0, r = 0, mx = 0;
};

treeNode mer(treeNode A, treeNode B) {
    if (A.sum == inf) return B;
    if (B.sum == inf) return A;
    treeNode ret;
    ret.sum = A.sum + B.sum;
    ret.mx = max(max(A.mx, B.mx), A.r + B.l);
    ret.l = max(A.l, A.sum + B.l);
    ret.r = max(B.r, B.sum + A.r);
    return ret;
}

treeNode rev(treeNode T) {
    treeNode ret = T;
    swap(ret.l, ret.r);
    return ret;
}

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


treeNode tree[400000];
int lazy[400000];

void lazyProp(int node, int start, int end) {
    if (lazy[node] == inf) return;
    tree[node].sum = lazy[node] * (end - start + 1);
    tree[node].mx = max(0, tree[node].sum);
    tree[node].l = tree[node].r = tree[node].mx;
    if (start != end) {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = inf;
}

void update(int node, int start, int end, int left, int right, int w) {
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
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void update_tree(int a, int b, int w) {
    while(top[a] != top[b]) {
        if (depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        update(1, 1, idx, in[st], in[a], w);
        a = parent[st];
    }
    if (depth[a] > depth[b]) swap(a, b);
    update(1, 1, idx, in[a], in[b], w);
}

treeNode dummy;

treeNode get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return dummy;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}


treeNode query(int a, int b) { // get path between a and b
    treeNode L, R;
    while (top[a] != top[b]) {
        if (depth[top[a]] < depth[top[b]]) {
            int st = top[b];
            R = mer(get(1, 1, idx, in[st], in[b]), R);
            b = parent[st];
        }
        else {
            int st = top[a];
            L = mer(L, rev(get(1, 1, idx, in[st], in[a])));
            a = parent[st];
        }
    }

    if (depth[a] < depth[b]) {
        L = mer(L, get(1, 1, idx, in[a], in[b]));
    }
    else {
        L = mer(L, rev(get(1, 1, idx, in[b], in[a])));
    }

    return mer(L, R);
}



void solve(int tc) {

    int N;
    cin >> N;
    vector<int> init(N + 1);
    for (int i = 1; i <= N; i++) cin >> init[i];

    for (int i = 1; i < 4 * N; i++) lazy[i] = inf;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    dfs1(1); dfs2(1);

    for (int i = 1; i <= N; i++) {
        update(1, 1, N, in[i], in[i], init[i]);
    }

    int M;
    cin >> M;
    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            if (in[u] > in[v]) swap(u, v);
            cout << query(u, v).mx << endl;
        }
        else {
            int u, v, w;
            cin >> u >> v >> w;
            update_tree(u, v, w);
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