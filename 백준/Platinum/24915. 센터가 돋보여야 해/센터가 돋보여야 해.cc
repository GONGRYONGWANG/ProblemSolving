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

struct treeNode {
    treeNode() {}
    treeNode(int mx, int mn, int ab_mx, int bc_mx, int abc_mx) : mx(mx), mn(mn), ab_mx(ab_mx), bc_mx(bc_mx), abc_mx(abc_mx) {}
    int mx, mn, ab_mx, bc_mx, abc_mx;
};

treeNode mer(treeNode t1, treeNode t2) {
    if (t1.mx == -inf * 2) return t2;
    if (t2.mx == -inf * 2) return t1;
    treeNode ret;
    ret.mx = max(t1.mx, t2.mx);
    ret.mn = min(t1.mn, t2.mx);
    ret.abc_mx = max(max(t1.abc_mx, t2.abc_mx), max(t1.ab_mx - t2.mn, t2.bc_mx - t1.mn));
    ret.ab_mx = max(max(t1.ab_mx, t2.ab_mx), t2.mx - t1.mn);
    ret.bc_mx = max(max(t1.bc_mx, t2.bc_mx), t1.mx - t2.mn);
    return ret;
}

treeNode tree[1333332];
int arr[333334];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = { arr[start],arr[start], -inf * 2, -inf * 2, -inf * 2 };
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = { arr[start],arr[start], -inf * 2, -inf * 2, -inf * 2 };
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x); update(node * 2 + 1, mid + 1, end, x);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

treeNode get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return { -inf * 2, 0,0,0,0 };
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}


void solve(int tc) {

    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    makeTree(1, 1, N);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            arr[x] = y;
            update(1, 1, N, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, N, l, r).abc_mx << endl;
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