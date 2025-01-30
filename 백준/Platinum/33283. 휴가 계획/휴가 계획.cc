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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int parent[200001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}
vector<int> E[200001];

int idx[200001];
int depth[200001];
int cnt = 1;
int init[400000];
int tree[1600000];
void dfs(int x, int p) {
    idx[x] = cnt;
    init[cnt] = depth[x];
    cnt += 1;
    for (int nx : E[x]) {
        if (nx == p) continue;
        depth[nx] = depth[x] + 1;
        dfs(nx, x);
        init[cnt] = depth[x];
        cnt += 1;
    }
}

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = init[start];
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return inf;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return min(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (findp(u) == findp(v)) continue;
        parent[findp(v)] = findp(u);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    dfs(1, -1);

    N = 2 * N - 1;
    makeTree(1, 1, N);

    int Q;
    cin >> Q;
    while (Q--) {
        int s, e;
        cin >> s >> e;

        int p = get(1, 1, N, min(idx[s], idx[e]), max(idx[s], idx[e]));
        cout << depth[s] - p + depth[e] - p - 1 << endl;
    }

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