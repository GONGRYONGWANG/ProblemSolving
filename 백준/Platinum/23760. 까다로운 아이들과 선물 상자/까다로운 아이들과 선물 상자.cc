//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

#include<vector>
#include<cmath>

vector<int> tree;
vector<int> arr(100001, 0);


int make_tree(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	int left_result = make_tree(node * 2, start, mid);
	int right_result = make_tree(node * 2 + 1, mid + 1, end);
	return tree[node] = left_result + right_result;
}


int calc(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	int left_result = calc(node * 2, start, mid,left,right);
	int right_result = calc(node * 2 + 1, mid + 1, end,left, right);
	return left_result + right_result;
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx < start || idx > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
	return;
}

bool update_2(int bi, int wi) {
	int node = 1;
	int start = 0;
	int end = 100000;
	while (start != end) {
		tree[node] -= 1;
		int mid = (start + end) / 2;
		if (tree[node * 2+1] >= bi) {
			node = node * 2 + 1;
			start = mid + 1;
		}
		else {
			bi -= tree[node * 2 + 1];
			node = node * 2;
			end = mid;
		}
	}
	tree[node] -= 1;
	if (start < wi) {
		return 0;
	}
	update(1, 0, 100000, start - wi, 1);
	return 1;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int c;

	for (int i = 0; i < N; i++) {
		cin >> c;
		arr[c] += 1;
	}

	int tree_height = (int)ceil(log2(100001));
	int tree_size = (1 << (tree_height + 1));
	tree.resize(tree_size,0);
	make_tree(1, 0, 100000);
	vector<int> w, b;

	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		w.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		if (!update_2(b[i], w[i])) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;

	return 0;
}



