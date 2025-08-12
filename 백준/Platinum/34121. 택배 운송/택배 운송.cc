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

vector<pll> E[200001];
pll parent[200001];
pll lr[200001];
bool inLine[200001];

void dfs(int x) {
    for (auto [nx, d] : E[x]) {
        if (inLine[nx] || parent[x].first == nx) continue;
        lr[nx] = { lr[x].first + d, lr[x].second - d };
        dfs(nx);
    }
}


ll tree[200001];
ll lazy[200001];

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, int x) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = x;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, x); update(node * 2 + 1, mid + 1, end, left, right, x);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
 
void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    queue<int> q;
    q.push(1);
    parent[1] = { 0,0 };

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto [nx,d] : E[x]) {
            if (nx == parent[x].first) continue;
            parent[nx] = { x,d };
            q.push(nx);
        }
    }

    lr[N] = { 0,0 };
    int root = N;

    while (root != 1) {
        lr[parent[root].first] = { lr[root].first + parent[root].second , lr[root].second + parent[root].second };
        inLine[root] = true;
        root = parent[root].first;
    }
    inLine[1] = true;

    for (int i = 1; i <= N; i++) {
        if (!inLine[i]) continue;
        dfs(i);
    }


    vector<vector<ll>> query(Q);

    map<ll, int> m;

    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        ll l, r;
        if (t == 1) {
            ll a, b;
            cin >> a >> b;
            l = lr[a].first - b; r = lr[a].second + b;
            l = max(l, 0ll);  r = min(r, lr[1].first);
            if (r > l) {
                m[l] = 0; m[r] = 0;
            }
        }
        else {
            int C; cin >> C;
            C -= 1;
            l = query[C][1]; r = query[C][2];
        }
        query[i] = { t,l,r };
    }

    int n = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        n += 1;
        it->second = n;
    }


    for (int i = 0; i < Q; i++) {
        if (m.rbegin()->first != lr[1].first || m.begin()->first != 0) {
            cout << "NO" << endl;
            continue;
        }
        int t = query[i][0];
        ll l = query[i][1]; ll r = query[i][2];
        if (l < r) {
            l = m[l]; r = m[r] - 1;
            if (t == 1) update(1, 1, n - 1, l, r, 1);
            else update(1, 1, n - 1, l, r, -1);



        }

        if (tree[1] == 0) cout << "NO";
        else cout << "YES";
        cout << endl;

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