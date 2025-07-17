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

ll tree[60][10000]; // 1667
ll lazy[60][10000];

void lazyProp(int node, int start, int end, int k) {
    if (lazy[k][node] == 0) return;
    tree[k][node] += lazy[k][node] * (end - start + 1);
    if (start != end) {
        lazy[k][node * 2] += lazy[k][node];
        lazy[k][node * 2 + 1] += lazy[k][node];
    }
    lazy[k][node] = 0;
}

void update(int node, int start, int end, int left, int right, ll x, int k) {
    if (left > right) return;
    lazyProp(node, start, end, k);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[k][node] += x;
        lazyProp(node, start, end, k);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, x, k); update(node * 2 + 1, mid + 1, end, left, right, x, k);
    tree[k][node] = tree[k][node * 2] + tree[k][node * 2 + 1];
}

ll get(int node, int start, int end, int left, int right, int k) {
    if (left > right) return 0;
    lazyProp(node, start, end, k);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[k][node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right, k) + get(node * 2 + 1, mid + 1, end, left, right, k);
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    for (int i = 61; i <= N + 60; i++) {
        ll x; cin >> x;
        update(1, 1, 2000, i / 60, i / 60, x, i % 60);
    }

    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, d; ll x;
            cin >> l >> r >> d >> x;
            l += 60; r += 60;
            for (int k = 0; k < 60; k++) {
                if ((k + 60 - l % 60) % d) continue;
                update(1, 1, 2000, l / 60 + (k < l % 60), r / 60 - (r % 60 < k), x, k);
            }
        }
        else {
            int l, r, d;
            cin >> l >> r >> d;
            l += 60; r += 60;
            ll ret = 0;
            for (int k = 0; k < 60; k++) {
                if ((k + 60 - l % 60) % d) continue;
                ret += get(1, 1, 2000, l / 60 + (k < l % 60), r / 60 - (r % 60 < k), k);
            }

            cout << ret << endl;

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