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


vector<int> E[100001];
int sz[100001], depth[100001], parent[100001], top[100001], in[100001];
int hchild[100001];

void dfs1(int x) {
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
void dfs2(int x) {
    idx += 1;
    in[x] = idx;
    if (hchild[x]) {
        top[hchild[x]] = top[x];
        dfs2(hchild[x]);
    }
    for (auto nx : E[x]) {
        if (parent[x] == nx) continue;
        if (nx == hchild[x]) continue;
        top[nx] = nx;
        dfs2(nx);
    }
}

int tree[400000];

void update(int node, int start, int end, int x, int w) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = w;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x, w);
    update(node * 2 + 1, mid + 1, end, x, w);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return max(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

int N, M;

int query(int a, int b) {
    int ret = 0;
    while (top[a] != top[b]) {
        if (depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret = max(ret, get(1, 1, N, in[st], in[a]));
        a = parent[st];
    }

    if (depth[a] > depth[b]) swap(a, b);
    ret = max(ret, get(1, 1, N, in[a], in[b]));
    return ret;
}


void solve(int tc) {

    cin >> N >> M;

    vector<pii> arr;
    for (int i = 1; i <= N; i++) {
        int T; cin >> T;
        arr.push_back({ T,i });
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    dfs1(1); dfs2(1);

    vector<tuple<int,int,int,int>> Q(M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Q[i] = { c,a,b,i };
    }
    sort(Q.begin(), Q.end());

    int pos = 0;
    vector<bool> ret(M);
    for (auto& [c, a, b, i] : Q) {
        while (pos != N && arr[pos].first <= c) {
            if (arr[pos].first == c) update(1, 1, N, in[arr[pos].second], arr[pos].first);
            pos += 1;
        }
        ret[i] = (query(a, b) == c);
    }

    for (bool b : ret) cout << b;

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