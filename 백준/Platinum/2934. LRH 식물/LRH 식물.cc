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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int tree[400000];
int lazy[400000];

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    else tree[node] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = 1;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right); update(node * 2 + 1, mid + 1, end, left, right);
}

int get(int node, int start, int end, int x) {
    lazyProp(node, start, end);
    if (x > end || x < start) return 0;
    if (start == end) {
        int ret = tree[node];
        tree[node] = 0;
        return ret;
    }
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, x) + get(node * 2 + 1, mid + 1, end, x);
}


void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, 100000, l) + get(1, 1, 100000, r) << endl;
        if (l + 1 <= r - 1) update(1, 1, 100000, l + 1, r - 1);
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