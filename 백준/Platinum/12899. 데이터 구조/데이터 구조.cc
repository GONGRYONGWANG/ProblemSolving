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
vector<int> arr(2000001, 0);

/*
int make_tree(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	int left_result = make_tree(node * 2, start, mid);
	int right_result = make_tree(node * 2 + 1, mid + 1, end);
	return tree[node] = left_result + right_result;
}
*/

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
	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
	return;
}
void update_2(int x) {
	int node = 1;
	int start = 0;
	int end = 2000000;
	while (start!=end) {
		tree[node] -= 1;
		int mid = (start + end) / 2;
		if (tree[2 * node] >= x) {
			node *= 2;
			end = mid;
		}
		else {
			x -= tree[node * 2];
			node = node * 2 + 1;
			start = mid + 1;
		}
	}
	tree[node] -= 1;
	cout << start<<endl;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int tree_height = (int)ceil(log2(2000001));
	int tree_size = (1 << (tree_height + 1));
	tree.resize(tree_size,0);
	int N, T, X;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T >> X;
		if (T == 1) {
			update(1, 0, 2000000, X, 1);
		}
		else { // T == 2
			update_2(X);
		}
	}
	return 0;
}



