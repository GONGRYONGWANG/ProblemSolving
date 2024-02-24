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
    treeNode(ll sum, ll len) : sum(sum), len(len) {}
    ll sum, len;
};

int N, M;
ll arr[100001];
treeNode tree[400000];
ll lazya[400000];
ll lazyd[400000];

treeNode merge(treeNode t1, treeNode t2) {
    return { t1.sum + t2.sum, t1.len + t2.len };
}

treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = { arr[start], 1};
    }
    else {
        int mid = (start + end) / 2;
        return tree[node] = merge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
    }
}

void lazyProp(int node, int start, int end) {
    if (lazya[node] == 0 && lazyd[node] == 0) return;
    tree[node].sum += lazya[node] * tree[node].len + (tree[node].len - 1) * lazyd[node] * tree[node].len / 2;
    if (start != end) {
        lazya[node * 2] += lazya[node];
        lazyd[node * 2] += lazyd[node];
        lazya[node * 2 + 1] += lazya[node] + lazyd[node] * tree[node * 2].len;
        lazyd[node * 2 + 1] += lazyd[node];
    }
    lazya[node] = 0; lazyd[node] = 0;
}

void sumSeq(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    else if (left <= start && right >= end) {
        lazya[node] += start-left + 1;
        lazyd[node] += 1;
        lazyProp(node, start, end);
        return;
    }
    else {
        int mid = (start + end) / 2;
        sumSeq(node * 2, start, mid, left, right);
        sumSeq(node * 2 + 1, mid + 1, end, left, right);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        return;
    }
    
}

treeNode get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return { 0,0 };
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
    int q, l, r, x;
    while (M--) {
        cin >> q;
        if (q == 1) {
            cin >> l >> r;
            sumSeq(1, 1, N, l, r);
        }
        else {
            cin >> x;
            cout << get(1, 1, N, x, x).sum << endl;
        }
    }
    return 0;
}