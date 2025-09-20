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


int N, Q;

ll arr[500001];
vector<int> E[500001];

ll mx[500001];
int parent[500001];
pii lr[500001];



ll tree[2000000];
bool updated[2000000];
ll lazy[2000000];

void lazyProp(int node, int start, int end) {
    if (start != end && updated[node]) {
        updated[node * 2] = updated[node * 2 + 1] = true;
    }

    if (lazy[node] == -INF) return;
    tree[node] = lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = -INF;
}

void update(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        updated[node] = true; lazy[node] = val;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val); 
    update(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

bool getupdated(int node, int start, int end, int x) {
    lazyProp(node, start, end);
    if (x > end || x < start) return false;
    if (start == end) return updated[node];
    int mid = (start + end) / 2;
    return getupdated(node * 2, start, mid, x) || getupdated(node * 2 + 1, mid + 1, end, x);
}

ll get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

int idx = 0;
void dfs(int x) {
    idx += 1;
    lr[x].first = idx;
    update(1, 1, N, lr[x].first, lr[x].first, arr[x]);
    mx[x] = max(mx[parent[x]], arr[parent[x]]);
    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        parent[nx] = x;
        dfs(nx);
    }
    lr[x].second = idx;
}




void solve(int tc) {
    
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    mx[0] = arr[0] = -INF;
    dfs(1);

    for (int i = 1; i < 4 * N; i++) {
        lazy[i] = -INF;
        updated[i] = false;
    }

    while (Q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            if (getupdated(1, 1, N, lr[x].first)) continue;
            update(1, 1, N, lr[x].first, lr[x].second, mx[x]);
        }
        else {
            cout << get(1, 1, N, lr[x].first, lr[x].second) << endl;
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