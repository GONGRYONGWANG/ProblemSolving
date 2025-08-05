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

struct Node {
    int l, r, x;
};

Node mer(Node& A, Node& B) {
    return { A.l,B.r,min(A.x,B.x) };
}


int C[100001];
int T[100001];
Node tree[400000];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = { T[start],T[start],C[start] };
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

int lazy[400000];

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node].l += lazy[node];
    tree[node].r += lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, int d) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] += d;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, d);
    update(node * 2 + 1, mid + 1, end, left, right, d);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

int getT(int node, int start, int end, int idx) {
    lazyProp(node, start, end);
    if (idx > end || idx < start) return 0;
    if (start == end) return tree[node].l;
    int mid = (start + end) / 2;
    return getT(node * 2, start, mid, idx) + getT(node * 2 + 1, mid + 1, end, idx);
}

int getX(int node, int start, int end, int L, int R) {
    lazyProp(node, start, end);
    if (tree[node].l > R || tree[node].r < L) return inf;
    if (L <= tree[node].l && R >= tree[node].r) return tree[node].x;
    int mid = (start + end) / 2;
    return min(getX(node * 2, start, mid, L, R), getX(node * 2 + 1, mid + 1, end, L, R));
}


void solve(int tc) {
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> C[i];

    for (int i = 2; i <= N; i++) {
        cin >> T[i];
        T[i] += T[i - 1];
    }

    makeTree(1, 1, N);

    for (int i = N; i >= 2; i--) {
        T[i] -= T[i - 1];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        string s;
        cin >> s;
        if (s.front() == 'U') {
            int x, t;
            cin >> x >> t;
            int d = t - T[x+1];
            T[x + 1] = t;
            update(1, 1, N, x + 1, N, d);
        }
        else {
            int x, m;
            cin >> x >> m;
            int g = getT(1, 1, N, x);
            cout << getX(1, 1, N, g - m, g + m) << endl;
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