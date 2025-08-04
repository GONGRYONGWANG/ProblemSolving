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
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int tree[800000];

int cal(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return x;
    if (x == 1 || y == 1) return 1;
    if (x == y) return x;
    return 1;
}

void lazyProp(int node, int start, int end) {
    if (start == end || tree[node] == 0) return;
    tree[node * 2] = cal(tree[node], tree[node * 2]);
    tree[node * 2 + 1] = cal(tree[node], tree[node * 2 + 1]);
    tree[node] = 0;
}

void update(int node, int start, int end, int left, int right, int x) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        tree[node] = cal(tree[node], x);
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, x);
    update(node * 2 + 1, mid + 1, end, left, right, x);
}

int get(int node, int start, int end, int idx) {
    lazyProp(node, start, end);
    if (idx > end || idx < start) return 0;
    if (start == end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, idx) + get(node * 2 + 1, mid + 1, end, idx);
}

int ret[800000];
int mer(int x, int y) {
    if (x == 1) return y;
    return x;
}

void insert(int node, int start, int end, int idx, int x) {
    if (idx > end || idx < start) return;
    if (start == end) {
        ret[node] = x;
        return;
    }
    int mid = (start + end) / 2;
    insert(node * 2, start, mid, idx, x);
    insert(node * 2 + 1, mid + 1, end, idx, x);
    ret[node] = mer(ret[node * 2], ret[node * 2 + 1]);
}

int getret(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && right >= end) return ret[node];
    int mid = (start + end) / 2;
    return mer(getret(node * 2, start, mid, left, right), getret(node * 2 + 1, mid + 1, end, left, right));
}

void solve(int tc) {
    
    int N, Q;
    cin >> N >> Q;

    vector<tuple<int, int, int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        update(1, 1, N, l, r, x);
        query[i] = { l,r,x };
    }

    for (int i = 1; i <= 4 * N; i++) ret[i] = 1;

    for (int i = 1; i <= N; i++) {
        int g = get(1, 1, N, i);
        if (g == 0) g = 1;
        insert(1, 1, N, i, g);
    }

    for (auto [l, r, x] : query) {
        int g = getret(1, 1, N, l, r);
        if (g != x) {
            cout << -1;
            return;
        }
    }

    for (int i = 1; i <= N; i++) {
        int g = get(1, 1, N, i);
        if (g == 0) g = 1;
        cout << g << " ";
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