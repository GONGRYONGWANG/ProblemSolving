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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////




ll mod = 1e9 + 7;

ll depth[300001];

ll treeA[1200000];
ll treeB[1200000];

void lazyProp(int node, int start, int end, ll* tree) {
    if (tree[node] == 0) return;
    if (start == end) return;
    tree[node * 2] += tree[node];
    tree[node * 2] %= mod;
    tree[node * 2 + 1] += tree[node];
    tree[node * 2 + 1] %= mod;
    tree[node] = 0;
}

void update(int node, int start, int end, int left, int right, ll v, ll* tree) {
    lazyProp(node, start, end, tree);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        tree[node] += v;
        tree[node] %= mod;
        lazyProp(node, start, end, tree);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, v, tree);
    update(node * 2 + 1, mid + 1, end, left, right, v, tree);
}

ll get(int node, int start, int end, int x, ll* tree) {
    lazyProp(node, start, end, tree);
    if (x<start || x>end) return 0;
    if (start == end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, x, tree) + get(node * 2 + 1, mid + 1, end, x, tree);
}



vector<int> child[300001];
int L[300001];
int R[300001];
int P[300001];

int idx = 0;
void dfs(int x) {
    L[x] = ++idx;
    depth[L[x]] = depth[L[P[x]]] + 1;
    for (int nx : child[x]) {
        dfs(nx);
    }
    R[x] = idx;
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    for (int i = 2; i <= N; i++) {
        int p; cin >> p;
        P[i] = p;
        child[p].push_back(i);
    }

    dfs(1);

    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            ll x, a, b;
            cin >> x >> a >> b;
            int l = L[x]; int r = R[x];
            a = (a + b * depth[l]) % mod;
            update(1, 1, N, l, r, a, treeA);
            update(1, 1, N, l, r, b, treeB);
        }
        else {
            int x; cin >> x;
            x = L[x];

            ll A = get(1, 1, N, x, treeA);
            ll B = get(1, 1, N, x, treeB);

            cout << (A + (mod - B) * depth[x]) % mod << endl;
        }
    }






    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}