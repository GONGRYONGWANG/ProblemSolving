//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF pow(2,31)

struct treeNode {
    treeNode(){}
    treeNode(ll sum, ll mn, ll mx) : sum(sum), mn(mn), mx(mx) {}
    ll sum, mn, mx;
};

int N, M;
vector<ll> arr;
vector<treeNode> tree;
vector<ll> lazy1,lazy2;

ll divFloor(ll A, ll D) {
    return A / D - (A % D < 0);
}

treeNode merge(treeNode t1, treeNode t2) {
    return { t1.sum + t2.sum, min(t1.mn, t2.mn), max(t1.mx, t2.mx) };
}


treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = {arr[start],arr[start],arr[start]};
    }
    else {
        int mid = (start + end) / 2;
        return tree[node] = merge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
    }
}

void lazyProp(int node, int start, int end) {
    if (lazy2[node] == INF) {
        tree[node].mx += lazy1[node];
        tree[node].mn += lazy1[node];
        tree[node].sum += (end - start + 1) * lazy1[node];
        if (start != end) {
            lazy1[node * 2] += lazy1[node];
            lazy1[node * 2 + 1] += lazy1[node];
        }
    }
    else {
        tree[node].mn = tree[node].mx = lazy1[node] + lazy2[node];
        tree[node].sum = (end - start + 1) * tree[node].mn;
        if (start != end) {
            lazy1[node * 2] = lazy1[node];
            lazy2[node * 2] = lazy2[node];
            lazy1[node * 2 + 1] = lazy1[node];
            lazy2[node * 2 + 1] = lazy2[node];
        }
    }
    lazy1[node] = 0; lazy2[node] = INF; return;
}

void add(int node, int start, int end, int left, int right, int val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    else if (left <= start && right >= end) {
        lazy1[node] = val;
        lazyProp(node, start, end);
        return;
    }
    else {
        int mid = (start + end) / 2;
        add(node * 2, start, mid, left, right, val);
        add(node * 2 + 1, mid + 1, end, left, right, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        return;
    }
}

void div(int node, int start, int end, int left, int right, int val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    else if (left <= start && right >= end) {
        if (divFloor(tree[node].mn, val) == divFloor(tree[node].mx, val)) {
            lazy2[node] = divFloor(tree[node].mn, val); 
            lazyProp(node, start, end);
            return;
        }
        if (tree[node].mn + 1 == tree[node].mx) {
            lazy1[node] = divFloor(tree[node].mn, val) - tree[node].mn; 
            lazyProp(node, start, end);
            return;
        }
    }
    int mid = (start + end) / 2;
    div(node * 2, start, mid, left, right, val);
    div(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    return;
}

ll getMin(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return INF;
    if (left <= start && right >= end) return tree[node].mn;
    int mid = (start + end) / 2;
    return min(getMin(node * 2, start, mid, left, right), getMin(node * 2 + 1, mid + 1, end, left, right));
}

ll getSum(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end)return tree[node].sum;
    int mid = (start + end) / 2;
    return getSum(node * 2, start, mid, left, right) + getSum(node * 2 + 1, mid + 1, end, left, right);
}

void init() {
    cin >> N >> M;
    arr.resize(N + 1);
    tree.resize(4 * N);
    lazy1.resize(4 * N, 0);
    lazy2.resize(4 * N, INF);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    init();
    makeTree(1, 1, N);
    int a, l, r;
    ll c, d;
    while (M--) {
        cin >> a>>l>>r;
        switch (a) {
        case 1:
            cin >> c;
            add(1, 1, N, l + 1, r + 1, c);
            break;
        case 2:
            cin >> d;
            div(1, 1, N, l + 1, r + 1, d);
            break;
        case 3:
            cout << getMin(1, 1, N, l + 1, r + 1) << endl;
            break;
        case 4:
            cout << getSum(1, 1, N, l + 1, r + 1) << endl;
            break;
        }
    }
    return 0;
}