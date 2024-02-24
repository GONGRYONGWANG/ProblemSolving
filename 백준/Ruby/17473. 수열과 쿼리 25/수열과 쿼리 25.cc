#pragma warning(disable:4996) 
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
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
#include<ctime>
#include<regex>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };


struct treeNode {
    treeNode() {}
    treeNode(ll mx, ll ands, ll ors) : mx(mx), ands(ands), ors(ors) {}
    ll mx, ands, ors;
};

int N, M;
ll arr[200001];
treeNode tree[800000];
ll lazy1[800000];
ll lazy2[800000];


treeNode merge(treeNode t1, treeNode t2) {
    return { max(t1.mx,t2.mx), (t1.ands & t2.ands), (t1.ors | t2.ors) };
}


treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = { arr[start], arr[start], arr[start] };
    }
    else {
        int mid = (start + end) / 2;
        return tree[node] = merge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
    }
}

void lazyProp(int node, int start, int end) {
    if (lazy1[node] == (1 << 20) - 1 && lazy2[node] == 0) { return; }
    tree[node].mx &= lazy1[node];
    tree[node].mx |= lazy2[node];
    tree[node].ands &= lazy1[node];
    tree[node].ands |= lazy2[node];
    tree[node].ors &= lazy1[node];
    tree[node].ors |= lazy2[node];
    if (start != end) {
        lazy1[node * 2] &= lazy1[node];
        lazy1[node * 2] |= lazy2[node];
        lazy2[node * 2] &= lazy1[node];
        lazy2[node * 2] |= lazy2[node];
        lazy1[node * 2 + 1] &= lazy1[node];
        lazy1[node * 2 + 1] |= lazy2[node];
        lazy2[node * 2 + 1] &= lazy1[node];
        lazy2[node * 2 + 1] |= lazy2[node];
    }
    lazy1[node] = (1 << 20) - 1; lazy2[node] = 0;
    return;
}

void bitAnd(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start || (tree[node].ors & val) == 0) return;
    else if (left <= start && right >= end && (tree[node].ands & val) == val) {
        lazy1[node] -= val;
        lazyProp(node, start, end);
        return;
    }
    else {
        int mid = (start + end) / 2;
        bitAnd(node * 2, start, mid, left, right, val);
        bitAnd(node * 2 + 1, mid + 1, end, left, right, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        return;
    }
}

void bitOr(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start || (tree[node].ands & val) == val) return;
    else if (left <= start && right >= end && (tree[node].ors & val) == 0) {
        lazy2[node] = val;
        lazyProp(node, start, end);
        return;
    }
    else {
        int mid = (start + end) / 2;
        bitOr(node * 2, start, mid, left, right, val);
        bitOr(node * 2 + 1, mid + 1, end, left, right, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        return;
    }
}


treeNode get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return { 0,(1 << 20) - 1 ,0 };
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return merge(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void init() {
    cin >> N;
    fill(lazy1, lazy1 + 800001, (1 << 20) - 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    init();
    makeTree(1, 1, N);
    char a;
    ll l, r, x;
    while (M--) {
        cin >> a >> l >> r;
        if (a == '1') {
            cin >> x;
            for (ll i = 1; i < (1 << 20); i = (i << 1)) {
                if ((x & i) == 0) {
                    bitAnd(1, 1, N, l, r, i);
                }
            }
        }
        else if (a == '2') {
            cin >> x;
            for (ll i = 1; i < (1 << 20); i = (i << 1)) {
                if ((x & i) == i) {
                    bitOr(1, 1, N, l, r, i);
                }
            }
        }
        else {
            cout << get(1, 1, N, l, r).mx << endl;
        }
    }
    return 0;
}