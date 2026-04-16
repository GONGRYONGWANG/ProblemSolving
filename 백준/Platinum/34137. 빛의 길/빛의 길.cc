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

ll tree[800000];
ll lazy[800000];

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] = lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, ll x) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = x;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, x);
    update(node * 2 + 1, mid + 1, end, left, right, x);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}


void solve(int tc) {

    ll N, M, T, K;
    cin >> N >> M >> T >> K;

    vector<int> init(M + 1);
    for (int i = 1; i <= M; i++) cin >> init[i];

    vector<tuple<ll, ll, ll, ll>> query(K);
    for (int i = 0; i < K; i++) {
        ll r, s, e, c;
        cin >> r >> s >> e >> c;
        query[i] = { N + 1 - r,s,e,c };
    }

    for (int i = 1; i <= M; i++) {
        query.push_back({ N,i,i,init[i] });
    }

    sort(query.begin(), query.end());

    vector<ll> ret(T + 1, 0);

    for (auto& [r, s, e, c] : query) {
        ret[c] += (e - s + 1) * r - get(1, 1, M, s, e);
        update(1, 1, M, s, e, r);
    }

    for (int i = 1; i <= T; i++) cout << ret[i] << " ";



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