#pragma warning(disable:4996) 
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
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

struct ap {
    ap() {}
    ap(ll a, ll d, ll len) : a(a), d(d), len(len) {}
    ll a, d, len;
};

struct treeNode {
    treeNode() {}
    treeNode(ll len, ll mxlen, ap lap, ap rap) : len(len), mxlen(mxlen), lap(lap), rap(rap) {}
    ll len, mxlen;
    ap lap, rap;
};

int N, M;
ll arr[100001];
treeNode tree[400000];
ll lazya[400000];
ll lazyd[400000];

treeNode merge(treeNode t1, treeNode t2) {
    if (t1.len == 0) return t2;
    if (t2.len == 0) return t1;

    if (t1.len == 1) {
        t1.rap.d = t2.lap.a - t1.rap.a;
    }
    if (t2.len == 1) {
        t2.lap.d = t2.lap.a - (t1.rap.a + t1.rap.d * (t1.rap.len - 1));
    }

    ap left, mid, right;
    if (t1.rap.d == t2.lap.d && t1.rap.a + t1.rap.d * t1.rap.len == t2.lap.a) {
        mid = { t1.rap.a,t1.rap.d,t1.rap.len + t2.lap.len };
    }
    else if (t1.rap.a + t1.rap.d * t1.rap.len == t2.lap.a && t1.rap.len + 1 > t2.lap.len) {
        mid = { t1.rap.a,t1.rap.d,t1.rap.len + 1 };
    }
    else if (t1.rap.a + t1.rap.d * (t1.rap.len - 1) == t2.lap.a - t2.lap.d && t1.rap.len < t2.lap.len + 1) {
        mid = { t2.lap.a - t2.lap.d, t2.lap.d,t2.lap.len + 1 };
    }
    else if (t1.rap.len > t2.lap.len) {
        mid = t1.rap;
    }
    else mid = t2.lap;

    if (t1.len == t1.mxlen) {
        if (t1.rap.d == t2.lap.d && t1.rap.a + t1.rap.d * t1.rap.len == t2.lap.a) {
            left = { t1.rap.a,t1.rap.d,t1.rap.len + t2.lap.len };
        }
        else if (t1.rap.a + t1.rap.d * t1.rap.len == t2.lap.a) {
            left = { t1.rap.a,t1.rap.d, t1.rap.len + 1 };
        }
        else left = t1.lap;
    }
    else left = t1.lap;

    if (t2.len == t2.mxlen) {
        if (t1.rap.d == t2.lap.d && t1.rap.a + t1.rap.d * t1.rap.len == t2.lap.a) {
            right = { t1.rap.a,t1.rap.d,t1.rap.len + t2.lap.len };
        }
        else if (t1.rap.a + t1.rap.d * (t1.rap.len - 1) == t2.lap.a - t2.lap.d) {
            right = { t2.lap.a - t2.lap.d, t2.lap.d,t2.lap.len + 1 };
        }
        else right = t2.rap;
    }
    else right = t2.rap;

    return { t1.len + t2.len, max(max(max(left.len,right.len),mid.len), max(t1.mxlen,t2.mxlen)), left, right };
}

treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = { 1,1, { arr[start], 0,1 }, { arr[start], 0,1 } };
    }
    else {
        int mid = (start + end) / 2;
        return tree[node] = merge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
    }
}

void lazyProp(int node, int start, int end) {
    if (lazya[node] == 0 && lazyd[node] == 0) return;
    tree[node].lap.a += lazya[node];
    tree[node].lap.d += lazyd[node];
    tree[node].rap.a += lazya[node] + lazyd[node] * (tree[node].len - tree[node].rap.len);
    tree[node].rap.d += lazyd[node];
    if (start != end) {
        lazya[node * 2] += lazya[node];
        lazyd[node * 2] += lazyd[node];
        lazya[node * 2 + 1] += lazya[node] + lazyd[node] * tree[node * 2].len;
        lazyd[node * 2 + 1] += lazyd[node];
    }
    lazya[node] = 0; lazyd[node] = 0;
}

void sumSeq(int node, int start, int end, int left, int right, ll x, ll y) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    else if (left <= start && right >= end) {
        lazya[node] += x + y * (start - left);
        lazyd[node] += y;
        lazyProp(node, start, end);
        return;
    }
    else {
        int mid = (start + end) / 2;
        sumSeq(node * 2, start, mid, left, right, x, y);
        sumSeq(node * 2 + 1, mid + 1, end, left, right, x, y);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        return;
    }

}

treeNode get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return { 0,0,{0,0,0},{0,0,0} };
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return merge(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    init();
    makeTree(1, 1, N);
    int q, l, r;
    ll x, y;
    while (M--) {
        cin >> q;
        if (q == 1) {
            cin >> l >> r >> x >> y;
            sumSeq(1, 1, N, l, r, x ,y);
        }
        else {
            cin >> l >> r;
            cout << get(1, 1, N, l, r).mxlen << endl;
        }
    }
    return 0;
}