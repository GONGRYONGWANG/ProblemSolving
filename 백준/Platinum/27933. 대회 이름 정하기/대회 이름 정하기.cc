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


struct treeNode {
    ll kk = -INF, ky = -INF, yk = -INF, yy = -INF;

    treeNode() {}
    treeNode(ll x, bool b) {
        if (b) kk = x;
        else yy = x;
    }

};

treeNode mer(treeNode A, treeNode B) {
    treeNode ret;
    ret.kk = max(max(A.kk, B.kk), max(A.ky + B.kk, A.kk + B.yk));
    ret.ky = max(max(A.ky, B.ky), max(A.ky + B.ky, A.kk + B.yy));
    ret.yk = max(max(A.yk, B.yk), max(A.yk + B.yk, A.yy + B.kk));
    ret.yy = max(max(A.yy, B.yy), max(A.yy + B.ky, A.yk + B.yy));
    return ret;
}

ll arr[500001];
bool KY[500001];

treeNode tree[2000000];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = treeNode(arr[start], KY[start]);
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid);
    makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

treeNode dummy;

treeNode get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return dummy;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        char x; cin >> x;
        KY[i] = (x == 'K');
    }
    for (int i = 1; i <= N; i++) cin >> arr[i];

    makeTree(1, 1, N);

    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;

        treeNode ret = get(1, 1, N, l, r);
        
        ll ky = max(ret.ky, 0ll);
        ll yk = max(ret.yk, 0ll);
        if (ky > yk) cout << "K " << ky;
        else if (yk > ky) cout << "Y " << yk;
        else cout << "YK " << yk;
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