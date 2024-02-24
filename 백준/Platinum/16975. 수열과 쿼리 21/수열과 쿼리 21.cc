//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N, M;
vector<ll> arr;
vector<ll> tree;
vector<ll> lazy;



ll makeTree(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = makeTree(node * 2, start, mid) + makeTree(node * 2 + 1, mid + 1, end);
}

void updateLazy(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

ll get(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int left, int right, ll val) {
    updateLazy(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return;
}

void init() {
    cin >> N;
    arr.resize(N + 1);
    tree.resize(4 * N);
    lazy.resize(4 * N);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    init();
    makeTree(1, 1, N);
    int a,b,c;
    ll d;
    for (int i = 0; i < M; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(1, 1, N, b, c, d);
        }
        else {
            cin >> b;
            cout << get(1, 1, N, b, b)<<endl;
        }
    }
    return 0;
}