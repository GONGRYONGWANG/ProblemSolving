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

int popcount(uint n) { // https://blog.naver.com/jinhan814/222540111549
    n = (n >> 1 & 0x55555555) + (n & 0x55555555);
    n = (n >> 2 & 0x33333333) + (n & 0x33333333);
    n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}

int N, Q;

int arr[200001];
set<int> st[21];

int tree[800000];
void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = (1 << arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = (tree[node * 2] | tree[node * 2 + 1]);
}

int get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return (get(node * 2, start, mid, left, right) | get(node * 2 + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = (1 << arr[x]);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x); update(node * 2 + 1, mid + 1, end, x);
    tree[node] = (tree[node * 2] | tree[node * 2 + 1]);
}

int pc[200001];

int pctree[800000][21];
void updatepctree(int node, int start, int end, int idx, int k, int v) {
    if (idx > end || idx < start) return;
    pctree[node][k] += v;
    if (start == end) return;
    int mid = (start + end) / 2;
    updatepctree(node * 2, start, mid, idx, k, v);
    updatepctree(node * 2 + 1, mid + 1, end, idx, k, v);
}
int getpctree(int node, int start, int end, int left, int right, int k) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return pctree[node][k];
    int mid = (start + end) / 2;
    return getpctree(node * 2, start, mid, left, right, k) + getpctree(node * 2 + 1, mid + 1, end, left, right, k);
}

void updatepc(int idx) {
    auto it = st[arr[idx]].find(idx);
    int l = *prev(it) + 1;
    int r = idx;
    pc[idx] = popcount(get(1, 1, N, l, r));
}

void change(int idx, int val) {
    int prv = arr[idx];
    updatepctree(1, 1, N, idx, pc[idx], -1);

    for (int i = 1; i <= 20; i++) {
        auto it = st[i].upper_bound(idx);
        if (*it == N + 1) continue;
        updatepctree(1, 1, N, *it, pc[*it], -1);
    }

    arr[idx] = val;
    st[prv].erase(idx);
    st[val].insert(idx);
    update(1, 1, N, idx);
    updatepc(idx);
    updatepctree(1, 1, N, idx, pc[idx], 1);

    for (int i = 1; i <= 20; i++) {
        auto it = st[i].upper_bound(idx);
        if (*it == N + 1) continue;
        updatepc(*it);
        updatepctree(1, 1, N, *it, pc[*it], 1);
    }

}

void solve(int tc) {

    cin >> N >> Q;
    for (int i = 1; i <= 20; i++) {
        st[i].insert(0);
        st[i].insert(N + 1);
    }
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        st[arr[i]].insert(i);
    }

    makeTree(1, 1, N);

    for (int i = 1; i <= N; i++) {
        updatepc(i);
        updatepctree(1, 1, N, i, pc[i], 1);
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, val;
            cin >> idx >> val;
            change(idx, val);
        }
        else {
            int l, r, k;
            cin >> l >> r >> k;
            int ret = 0;
            for (int i = k + 1; i <= 20; i++) {
                ret += getpctree(1, 1, N, l, r, i);
            }
            for (int i = 1; i <= 20; i++) {
                auto it = st[i].lower_bound(l);
                if (*it > r) continue;
                if (pc[*it] <= k) ret += 1;
            }
            cout << ret << endl;
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