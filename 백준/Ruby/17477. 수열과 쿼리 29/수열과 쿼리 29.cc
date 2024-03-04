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
#include<complex> // complex number
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

//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

/*
int COMB[100][100];
int comb(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;
    if (COMB[n][r]) return COMB[n][r];
    return COMB[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}
*/

//////////////////////////////////////////////////////////////////////////////////////

struct treeNode {
    treeNode() {}
    treeNode(ll sz, ll mx, ll mx2, ll mxcnt, ll mn, ll mn2, ll mncnt, ll b) : sz(sz), mx(mx), mx2(mx2), mxcnt(mxcnt), mn(mn), mn2(mn2), mncnt(mncnt), b(b) {}
    ll sz;
    ll mx, mx2, mxcnt, mn, mn2, mncnt;
    ll b;
};
struct nodeLazy {
    nodeLazy() {}
    nodeLazy(ll a, ll acnt, ll L, ll Lcnt, ll R, ll Rcnt) : a(a), acnt(acnt), L(L), Lcnt(Lcnt), R(R), Rcnt(Rcnt) {}
    ll a, acnt, L, Lcnt, R, Rcnt;
};


ll arr[500001];

treeNode tree[2000000];
nodeLazy lazy[2000000];


treeNode mer(treeNode t1, treeNode t2) {
    treeNode ret;

    ret.sz = t1.sz + t2.sz;
    ret.b = t1.b + t2.b;


    if (t1.mx > t2.mx) {
        ret.mx = t1.mx;
        ret.mxcnt = t1.mxcnt;
        ret.mx2 = max(t1.mx2, t2.mx);
    }
    else if (t1.mx < t2.mx) {
        ret.mx = t2.mx;
        ret.mxcnt = t2.mxcnt;
        ret.mx2 = max(t1.mx, t2.mx2);
    }
    else {
        ret.mx = t1.mx;
        ret.mxcnt = t1.mxcnt + t2.mxcnt;
        ret.mx2 = max(t1.mx2, t2.mx2);
    }

    if (t1.mn < t2.mn) {
        ret.mn = t1.mn;
        ret.mncnt = t1.mncnt;
        ret.mn2 = min(t1.mn2, t2.mn);
    }
    else if (t1.mn > t2.mn) {
        ret.mn = t2.mn;
        ret.mncnt = t2.mncnt;
        ret.mn2 = min(t1.mn, t2.mn2);
    }
    else {
        ret.mn = t1.mn;
        ret.mncnt = t1.mncnt + t2.mncnt;
        ret.mn2 = min(t1.mn2, t2.mn2);
    }

    return ret;
}

treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = { 1,arr[start],-INF,1,arr[start],INF,1,0 };
    }
    else {
        int mid = (start + end) / 2;
        tree[node] = mer(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
    }
    lazy[node] = { 0,0,0,0,0,0 };
    return tree[node];
}

void lazyProp(int node, int start, int end) {
    if (tree[node].mx == tree[node].mn) {
        lazy[node].a += lazy[node].R + lazy[node].L;
        lazy[node].acnt += lazy[node].Rcnt + lazy[node].Lcnt;
        lazy[node].R = lazy[node].L = lazy[node].Rcnt = lazy[node].Lcnt = 0;
    }
    if (tree[node].mx2 == tree[node].mn) {
        tree[node].mx2 += lazy[node].L;
    }
    if (tree[node].mn2 == tree[node].mx) {
        tree[node].mn2 += lazy[node].R;
    }
    tree[node].mx += lazy[node].R + lazy[node].a;
    tree[node].mn += lazy[node].L + lazy[node].a;
    tree[node].mx2 += lazy[node].a;
    tree[node].mn2 += lazy[node].a;
    tree[node].b += lazy[node].Rcnt * tree[node].mxcnt + lazy[node].Lcnt * tree[node].mncnt + tree[node].sz * lazy[node].acnt;


    if (start != end) {

        if (tree[node * 2].mx == tree[node * 2].mn) {
            lazy[node * 2].a += lazy[node * 2].R + lazy[node * 2].L;
            lazy[node * 2].R = lazy[node * 2].L = 0;
            lazy[node * 2].acnt += lazy[node * 2].Lcnt + lazy[node * 2].Rcnt;
            lazy[node * 2].Rcnt = lazy[node * 2].Lcnt = 0;
        }
        if (tree[node * 2 + 1].mx == tree[node * 2 + 1].mn) {
            lazy[node * 2 + 1].a += lazy[node * 2 + 1].R + lazy[node * 2 + 1].L;
            lazy[node * 2 + 1].R = lazy[node * 2 + 1].L = 0; 
            lazy[node * 2 + 1].acnt += lazy[node * 2 + 1].Lcnt + lazy[node * 2 + 1].Rcnt;
            lazy[node * 2 + 1].Rcnt = lazy[node * 2 + 1].Lcnt = 0;
        }

        if (tree[node * 2].mx + lazy[node * 2].R + lazy[node * 2].a + lazy[node].R + lazy[node].a == tree[node].mx) {
            lazy[node * 2].R += lazy[node].R;
            lazy[node * 2].Rcnt += lazy[node].Rcnt;
        }
        if (tree[node * 2 + 1].mx + lazy[node * 2 + 1].R + lazy[node * 2 + 1].a + lazy[node].R + lazy[node].a == tree[node].mx) {
            lazy[node * 2 + 1].R += lazy[node].R;
            lazy[node * 2 + 1].Rcnt += lazy[node].Rcnt;
        }
        if (tree[node * 2].mn + lazy[node * 2].L + lazy[node * 2].a + lazy[node].L + lazy[node].a == tree[node].mn) {
            lazy[node * 2].L += lazy[node].L;
            lazy[node * 2].Lcnt += lazy[node].Lcnt;
        }
        if (tree[node * 2 + 1].mn + lazy[node * 2 + 1].L + lazy[node * 2 + 1].a + lazy[node].L + lazy[node].a == tree[node].mn) {
            lazy[node * 2 + 1].L += lazy[node].L;
            lazy[node * 2 + 1].Lcnt += lazy[node].Lcnt;
        }

        lazy[node * 2].a += lazy[node].a;
        lazy[node * 2].acnt += lazy[node].acnt;
        lazy[node * 2 + 1].a += lazy[node].a;
        lazy[node * 2 + 1].acnt += lazy[node].acnt;
    }
    lazy[node] = { 0,0,0,0,0,0 };
}


void add(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node].a = val;
        lazy[node].acnt = 1;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    add(node * 2, start, mid, left, right, val);
    add(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void maximize(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start || tree[node].mn >= val) return;
    if (left <= start && right >= end && tree[node].mn2 > val) {
        lazy[node].L = val - tree[node].mn;
        lazy[node].Lcnt = 1;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    maximize(node * 2, start, mid, left, right, val);
    maximize(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void minimize(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start || tree[node].mx <= val) return;
    if (left <= start && right >= end && tree[node].mx2 < val) {
        lazy[node].R = val - tree[node].mx;
        lazy[node].Rcnt = 1;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    minimize(node * 2, start, mid, left, right, val);
    minimize(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

treeNode get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return {0, -INF, -INF, 0, INF, INF, 0, 0};
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void solve() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    makeTree(1, 1, N);
    int M;
    cin >> M;
    while (M--) {
        int a, l, r;
        ll x, y;
        cin >> a;
        if (a == 1) {
            cin >> l >> r >> x;
            if (x == 0) continue;
            add(1, 1, N, l, r, x);
        }
        else if (a == 2) {
            cin >> l >> r >> y;
            maximize(1, 1, N, l, r, y);
        }
        else if (a == 3) {
            cin >> l >> r >> y;
            minimize(1, 1, N, l, r, y);
        }
        else {
            cin >> l >> r;
            cout << get(1, 1, N, l, r).b << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }

    return 0;
}