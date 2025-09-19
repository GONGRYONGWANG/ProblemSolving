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

struct treeNode{
    ll total = 0;
    ll mx = 0, mn =0 ;
    ll lmx = 0, lmn = 0;
    ll rmx = 0, rmn = 0;
    ll mxval = 0;

    treeNode(ll val) {
        total = val;
        mx = max(0ll, val); mn = min(0ll , val);
        lmx = rmx = mx;
        lmn = rmn = mn;
        mxval = val;
    }

    treeNode() = default;

};


treeNode mer(treeNode A, treeNode B) {
    treeNode ret;
    ret.total = A.total + B.total;
    ret.mx = max(max(A.mx, B.mx),  A.rmx + B.lmx);
    ret.mn = min(min(A.mn, B.mn), A.rmn + B.lmn);
    ret.lmx = max(A.lmx, A.total + B.lmx);
    ret.lmn = min(A.lmn, A.total + B.lmn);
    ret.rmx = max(B.rmx, B.total + A.rmx);
    ret.rmn = min(B.rmn, B.total + A.rmn);
    ret.mxval = max(A.mxval, B.mxval);
    return ret;
}

treeNode tree[800000];
ll arr[200001];
void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = treeNode(arr[x]);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x);
    update(node * 2 + 1, mid + 1, end, x);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}


void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll a, b;
            cin >> a >> b;
            arr[a] += b;
            update(1, 1, N, a);
        }
        else {
            if (tree[1].mxval <= 0) cout << tree[1].mxval;
            else cout<< max(tree[1].mx, tree[1].total - tree[1].mn);
            cout << endl;
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