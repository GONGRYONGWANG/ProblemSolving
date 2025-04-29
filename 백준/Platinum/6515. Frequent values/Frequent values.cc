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
#define INF ll(4e18)
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
    int mx = -1, l = 0, r = 0, lcnt = 0, rcnt = 0;
    treeNode() {}
};

treeNode mer(treeNode A, treeNode B) {
    if (A.mx == -1) return B;
    if (B.mx == -1) return A;
    treeNode ret;
    ret.l = A.l;
    ret.r = B.r;
    ret.lcnt = A.lcnt;
    ret.rcnt = B.rcnt;
    if (A.r != B.l) {
        ret.mx = max(A.mx, B.mx);
        
        return ret;
    }
    if (A.l == A.r) ret.lcnt += B.lcnt;
    if (B.l == B.r) ret.rcnt += A.rcnt;
    ret.mx = max(max(A.mx, B.mx),A.rcnt + B.lcnt);
    return ret;
}

int arr[100001];
treeNode tree[400000];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node].mx = tree[node].lcnt = tree[node].rcnt = 1;
        tree[node].l = tree[node].r = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

treeNode get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return treeNode();
    if (left <= start && right >= end) {
        
        return tree[node];
    }
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void solve(int tc) {

    while (1) {
        int N, Q;
        cin >> N;
        if (N == 0) break;
        cin >> Q;
        for (int i = 1; i <= N; i++) cin >> arr[i];
        makeTree(1, 1, N);
        while (Q--) {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, N, l, r).mx << endl;
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