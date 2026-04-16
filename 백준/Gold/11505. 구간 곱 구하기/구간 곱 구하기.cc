//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9
#define moder 1000000007
#include<cmath>

int N, M, K;
#include<vector>
vector<long long> tree;
vector<long long> arr;
vector<long long> arr_position;
long long make_tree(int node, int start, int end) {
    if (start == end) {
        arr_position[start] = node;
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = (make_tree(node * 2, start, mid) * make_tree(node * 2 + 1, mid + 1, end))%moder;
}
long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) { return 1; }
    if (left <= start && right >= end) { return tree[node]; }
    int mid = (start + end) / 2;
    return (sum(node * 2, start, mid, left, right) * sum(node * 2 + 1, mid + 1, end, left, right))%moder;
}
void update(long long idx, long long diff) {
    long long node = arr_position[idx];
    tree[node] = diff;
    arr[idx] = diff;
    node /= 2;
    while (node != 0) {
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % moder;
        node /= 2;
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M >> K;
    long long x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        arr.push_back(x);
    }
    arr_position.resize(arr.size());
    long long tree_height = (int)ceil(log2(N));
    long long tree_size = (1 << (tree_height + 1));
    tree.resize(tree_size);
    make_tree(1, 0, N - 1);
    long long a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b-1, c);
        }
        else {
            cout << sum(1, 0, N - 1, b - 1, c - 1) << endl;
        }
    }
    return 0;
}

