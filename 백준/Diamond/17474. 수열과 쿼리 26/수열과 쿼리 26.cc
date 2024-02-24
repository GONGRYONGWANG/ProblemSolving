//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF pow(2,31)

struct treeNode {
    ll sum = 0;
    ll mx, mx2, mxcnt;
};

int N, M;
vector<ll> arr;
vector<treeNode> tree;
vector<ll> lazy;

treeNode merge(treeNode t1, treeNode t2) {
    treeNode t;
    if (t1.mx < t2.mx) {
        t = t2;
        t2 = t1;
        t1 = t;
    }
    t.sum = t1.sum + t2.sum;
    t.mx = t1.mx;
    if (t1.mx == t2.mx) {
        t.mxcnt = t1.mxcnt + t2.mxcnt;
        t.mx2 = max(t1.mx2, t2.mx2);
    }
    else if (t2.mx > t1.mx2) {
        t.mxcnt = t1.mxcnt;
        t.mx2 = t2.mx;
    }
    else {
        t.mxcnt = t1.mxcnt;
        t.mx2 = t1.mx2;
    }
    return t;
}


treeNode makeTree(int node, int start, int end) {
    treeNode t, tl, tr;
    if (start == end) {
        t.sum = arr[start];
        t.mx = arr[start];
        t.mx2 = -INF;
        t.mxcnt = 1;
        return tree[node] = t;
    }
    int mid = (start + end) / 2;
    return tree[node] = merge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
}

void lazyProp(int node, int start, int end) {
    if (lazy[node] == INF) return;
    if (start == end) {
        if (lazy[node] < tree[node].mx) {
            tree[node].mx = lazy[node];
            tree[node].sum = lazy[node];
        }
        lazy[node] = INF; return;
    }

    if (lazy[node] >= tree[node].mx) {
        lazy[node] = INF; return;
    }
    else if (lazy[node] > tree[node].mx2) {
        tree[node].sum -= tree[node].mxcnt * (tree[node].mx - lazy[node]);
        lazy[node * 2] = min(lazy[node], lazy[node * 2]);
        lazy[node * 2 + 1] = min(lazy[node], lazy[node * 2]);
        tree[node].mx = lazy[node];
        lazy[node] = INF; return;
    }
    else {
        lazy[node * 2] = min(lazy[node * 2], lazy[node]);
        lazy[node * +1] = min(lazy[node * 2 + 1], lazy[node]);
        lazyProp(node * 2, start, end);
        lazyProp(node * 2 + 1, start, end);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        lazy[node] = INF; return;
    }
}

ll getSum(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node].sum;
    int mid = (start + end) / 2;
    return getSum(node * 2, start, mid, left, right) + getSum(node * 2 + 1, mid + 1, end, left, right);
}

ll getMax(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return -INF;
    if (left <= start && right >= end) return tree[node].mx;
    int mid = (start + end) / 2;
    return max(getMax(node * 2, start, mid, left, right), getMax(node * 2 + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    ll ogmx = tree[node].mx;
    if (left > end || right < start) return;

    if (val >= tree[node].mx) return;
    else if (val > tree[node].mx2) {
        tree[node].mx = val;
        if (left <= start && right >= end) {
            tree[node].sum -= tree[node].mxcnt * (ogmx - tree[node].mx);
            if (start != end) {
                lazy[node * 2] = min(lazy[node * 2], val);
                lazy[node * 2 + 1] = min(lazy[node * 2 + 1], val);
            }
            return;
        }
        else {
            int mid = (start + end) / 2;
            update(node * 2, start, mid, left, right, val);
            update(node * 2 + 1, mid + 1, end, left, right, val);
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
            return;
        }
    }
    else {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, left, right, val);
        update(node * 2 + 1, mid + 1, end, left, right, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
    return;
}

void init() {
    cin >> N;
    arr.resize(N + 1);
    tree.resize(4 * N);
    lazy.resize(4 * N, INF);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;
}



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    init();
    makeTree(1, 1, N);
    int a, l, r;
    ll x;
    while (M--) {
        cin >> a >> l >> r;
        switch (a) {
        case 1:
            cin >> x;
            update(1, 1, N, l, r, x);
            break;
        case 2:
            cout << getMax(1, 1, N, l, r) << endl;
            break;
        case 3:
            cout << getSum(1, 1, N, l, r) << endl;
            break;
        }
    }
    return 0;
}