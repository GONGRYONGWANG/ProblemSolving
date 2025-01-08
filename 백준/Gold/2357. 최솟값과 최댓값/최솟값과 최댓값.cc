//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

int N, M;
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
vector<pair<int, int>> tree;
vector<int> arr;

pair<int,int> make_tree(int node, int start, int end) {
	if (start == end) {
		return tree[node] = { arr[start],arr[start] };
	}
	int mid = (start + end) / 2;
	pair<int, int> left_result = make_tree(node * 2, start, mid);
	pair<int, int> right_result = make_tree(node * 2 + 1, mid + 1, end);
	tree[node].first = min(left_result.first, right_result.first);
	tree[node].second = max(left_result.second, right_result.second);
	return tree[node];
}

pair<int, int> calc(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return { maxint, 0 };
	if (left <= start && right >= end) return tree[node];

	int mid = (start + end) / 2;
	pair<int, int> left_result = calc(node * 2, start, mid, left, right);
	pair<int, int> right_result = calc(node * 2 + 1, mid + 1, end, left, right);
	return { min(left_result.first, right_result.first), max(left_result.second, right_result.second) };
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		arr.push_back(tmp);
	}

	int tree_height = (int)ceil(log2(N));
	int tree_size = (1 << (tree_height + 1));
	tree.resize(tree_size);
	make_tree(1, 0, N - 1);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		pair<int, int> ans = calc(1, 0, N-1, a - 1, b - 1);
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}



