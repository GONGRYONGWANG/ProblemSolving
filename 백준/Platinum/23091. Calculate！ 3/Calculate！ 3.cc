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

vector<pii> E[100001];
int parent[100001];
int pval[100001];

int L[100001];
int R[100001];

int init[100001];

int idx = 0;
void dfs(int x) {
    idx += 1;
    L[x] = idx;
    init[L[x]] = init[L[parent[x]]] ^ pval[x];
    for (pii& e: E[x]) {
        int nx = e.first;
        if (nx == parent[x]) continue;
        parent[nx] = x;
        pval[nx] = e.second;
        dfs(nx);
    }
    R[x] = idx;
}

ll tree[400000][32];
int lazy[400000];


void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    int ret[32];
    for (int i = 0; i < 32; i++) {
        ret[i ^ lazy[node]] = tree[node][i];
    }
    for (int i = 0; i < 32; i++) tree[node][i] = ret[i];
    if (start != end) {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node][init[start]] = 1;
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid);
    makeTree(node * 2 + 1, mid + 1, end);
    for (int i = 0; i < 32; i++) {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}

void update(int node, int start, int end, int left, int right, int val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] ^= val;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);
    for (int i = 0; i < 32; i++) {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}


void solve(int tc) {
    
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        E[u].push_back({ v,c });
        E[v].push_back({ u,c });
    }

    dfs(1);
    
    makeTree(1, 1, N);

    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            if (parent[b] == a) swap(a, b);
            update(1, 1, N, L[a], R[a], pval[a] ^ c);
            pval[a] = c;
        }
        else {
            int c;
            cin >> c;
            ll ans = 0;
            for (int i = 0; i < 32; i++) {
                ans += tree[1][i] * tree[1][i ^ c];
            }
            ans /= 2;
            cout << ans << endl;
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