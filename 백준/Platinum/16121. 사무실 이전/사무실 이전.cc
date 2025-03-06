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

vector<int> E[300001];
bool home[300001];
int L[300001];
int R[300001];

int idx = 0;
vector<int> homeidx = { 0 };
void ett(int x, int p) {
    L[x] = idx;
    if (home[x]) {
        idx += 1;
        homeidx.push_back(x);
    }
    for (int nx : E[x]) {
        if (nx == p) continue;
        ett(nx, x);
    }
    R[x] = idx;
}

ll mod = 998244353;
ll init[300001];
ll tree[1200000];
ll lazy[1200000];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = init[start] % mod;
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid);
    makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    tree[node] %= mod;
}

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node] * (end - start + 1);
    tree[node] %= mod;
    tree[node] += mod; tree[node] %= mod;
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

ll get(int node, int start, int end,int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return (get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right)) % mod;
}

void update(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = val;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val); update(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    tree[node] %= mod;
}

ll ret[300001];

void backtrack(int x, int p) {
    int l = L[x]; int r = R[x];
    ll A = 0; ll B = 0; ll m = r - l; ll n = idx - m;

    A = get(1, 1, idx, 1, l);
    if (r != idx) A += get(1, 1, idx, r + 1, idx);
    if (l != r) B = get(1, 1, idx, l + 1, r);
    if (l != r) update(1, 1, idx, l + 1, r, -2);
    update(1, 1, idx, 1, idx, 1);

    ret[x] = (A + B + n - m) * (A + B + n - m) - ((A + B) * (A + B) - ret[p]) - 2 * (A * (n - m - 1) + B * (n - m + 1) + n * (n - 1) / 2 + m * (m - 1) / 2 - n * m);
    ret[x] %= mod; ret[x] += mod; ret[x] %= mod;

    for (int nx : E[x]) {
        if (nx == p) continue;
        backtrack(nx, x);
    }
    update(1, 1, idx, 1, idx, -1);
    if (l != r) update(1, 1, idx, l + 1, r, 2);

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
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        home[x] = true;
    }

    ett(1, -1);

    vector<ll> dist(N + 1);
    queue<pii> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        auto [x, p] = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (nx == p) continue;
            dist[nx] = dist[x] + 1;
            q.push({ nx,x });
        }
    }

    for (int i = 1; i <= idx; i++) {
        init[i] = dist[homeidx[i]];
        ret[1] += init[i] * init[i] % mod;
    }
    ret[1] %= mod;

    makeTree(1, 1, idx);

    for (int nx : E[1]) {
        backtrack(nx, 1);
    }

    ll ans = 0;
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        ans += ret[x];
        ans %= mod;
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