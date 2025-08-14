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

vector<short> E[30001];
short sz[30001], depth[30001], parent[30001], top[30001], in[30001];
short hchild[30001]; // heavy child

void dfs1(int x) { // get parent and heavy child of each node
    sz[x] = 1;
    for (short& nx : E[x]) {
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

int tree[120000];

void update(int node, int start, int end, int x, int w) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = w;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x, w);
    update(node * 2 + 1, mid + 1, end, x, w);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}


int query(int a, int b) { // get path between a and b
    int ret = 0;
    while (top[a] != top[b]) {
        if (depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret += get(1, 1, idx, in[st], in[a]);
        a = parent[st];
    }

    if (depth[a] > depth[b]) swap(a, b);
    ret += get(1, 1, idx, in[a], in[b]);
    return ret;
}

///////////////////////////////////////////////////////////////


short P[30001];
int findp(int x) {
    if (P[x] == x) return x;
    return P[x] = findp(P[x]);
}

void solve(int tc) {

    int N;
    cin >> N;

    vector<int> init(N + 1);
    for (int i = 1; i <= N; i++) cin >> init[i];

    int M;
    cin >> M;
    vector<tuple<int, int, int>> Q(M);

    for (int i = 1; i <= N; i++) P[i] = i;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        int t;
        if (s.front() == 'b') t = 1;
        else if (s.front() == 'p') t = 2;
        else t = 3;
        int a, b;
        cin >> a >> b;
        Q[i] = { t,a,b };
        if (t == 1 && findp(a)!=findp(b)) {
            P[findp(a)] = findp(b);
            E[a].push_back(b);
            E[b].push_back(a);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (findp(i) != findp(1)) {
            E[i].push_back(1);
            E[1].push_back(i);
            P[findp(i)] = findp(1);
        }
    }

    dfs1(1); dfs2(1);

    for (int i = 1; i <= N; i++) P[i] = i;

    for (int i = 1; i <= N; i++) update(1, 1, N, in[i], init[i]);

    for (auto& [t, a, b] : Q) {
        if (t == 1) {
            if (findp(a) == findp(b)) cout << "no";
            else {
                cout << "yes";
                P[findp(a)] = findp(b);
            }
            cout << endl;
        }
        else if (t == 2) {
            update(1, 1, N, in[a], b);
        }
        else {
            if (findp(a) != findp(b)) {
                cout << "impossible";
            }
            else {
                cout << query(a, b);
            }
            cout << endl;
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