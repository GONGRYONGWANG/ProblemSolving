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
#define INF ll(9e18)
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

int tree[800004];
int lazy[800004];
void makeTree(int node, int start, int end) {
    if (start == end) {
        lazy[node] = 0;
        if (start == 1) {
            tree[node] = 0;
        }
        else tree[node] = -inf;
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

int getidx(int node, int start, int end, int val) {
    lazyProp(node, start, end);
    if (tree[node] < val) return 0;
    if (start == end) return start;

    int mid = (start + end) / 2;

    int ret = getidx(node * 2 + 1, mid + 1, end, val);
    if (ret == 0) return getidx(node * 2, start, mid, val);
    else return ret;
}

void update(int node, int start, int end, int idx, int val) {
    lazyProp(node, start, end);
    if (idx > end || idx < start) return;
    if (start == end) {
        tree[node] = max(tree[node], val);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}


void solve(int tc) {

    int N, M;
    cin >> N >> M;
    makeTree(1, 1, N + 1);

    for (int i = 1; i <= N; i++) {
        lazy[1] += M;

        int x;
        cin >> x;

        int idx = getidx(1, 1, N + 1, x);
        if (idx != 0) update(1, 1, N + 1, idx + 1, x);
    }

    cout << N + 1 - getidx(1, 1, N + 1, 0);



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