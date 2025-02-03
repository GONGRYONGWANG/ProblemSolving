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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

struct Node {
    ll sum = 0, mn = 0, mx = 0;
    Node() {}
    Node(ll sum, ll mn, ll mx) : sum(sum), mn(mn), mx(mx) {}
};

ll arr[200001];

Node mer(Node t1, Node t2) {
    return { t1.sum + t2.sum, min(t1.mn,t2.mn), max(t1.mx,t2.mx) };
}

Node tree[800000];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = { arr[start],arr[start],arr[start] };
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int idx) {
    if (idx > end || idx < start) return;
    if (start == end) {
        tree[node] = { arr[start],arr[start],arr[start] };
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx); update(node * 2 + 1, mid + 1, end, idx);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

int getl(int node, int start, int end, int left, int right, ll val) {
    if (left > end || right < start) return inf;
    int mid = (start + end) / 2;
    if (left <= start && right >= end) {
        if (tree[node].mx < val) return inf;
        if (tree[node].mn >= val) return start;
        if (tree[node * 2 + 1].mn >= val) return min(mid + 1, getl(node * 2, start, mid, left, right, val));
        return getl(node * 2 + 1, mid + 1, end, left, right, val);
    }
    int ret = getl(node * 2 + 1, mid + 1, end, left, right, val);
    if (ret == mid + 1 || ret == inf) ret = min(ret, getl(node * 2, start, mid, left, right, val));
    return ret;
}

int getr(int node, int start, int end, int left, int right, ll val) {
    if (left > end || right < start) return -inf;
    int mid = (start + end) / 2;
    if (left <= start && right >= end) {
        if (tree[node].mx < val) return -inf;
        if (tree[node].mn >= val) return end;
        if (tree[node * 2].mn >= val) return max(mid, getr(node * 2 + 1, mid + 1, end, left, right, val));
        return getr(node * 2, start, mid, left, right, val);
    }

    int ret = getr(node * 2, start, mid, left, right, val);
    if (ret == mid || ret == -inf) ret = max(ret, getr(node * 2 + 1, mid + 1, end, left, right, val));
    return ret;

}

ll getsum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node].sum;
    int mid = (start + end) / 2;
    return getsum(node * 2, start, mid, left, right) + getsum(node * 2 + 1, mid + 1, end, left, right);
}



void solve(int tc) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    makeTree(1, 1, N);

    int M;
    cin >> M;
    while (M--) {
        int t, i, j;
        cin >> t >> i >> j;
        if (t == 1) {
            arr[i] = j;
            update(1, 1, N, i);
        }
        else {
            int l = getl(1, 1, N, 1, i, j);
            int r = getr(1, 1, N, i, N, j);
            cout << getsum(1, 1, N, l, r) << endl;
        }
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