#include<iostream>
using namespace std;
#define endl "\n"

#include<vector>
#define MAX 10001


vector<int> preorder;

void postorder(int begin, int end) {
	if (begin > end) {return;}
	int root = preorder[begin];
	if (begin == end) { cout << root<<endl; return; }
	int i;
	for (i = begin + 1; i <= end;i++) {
		if (preorder[i] > root) {
			break;
		}
	}
	postorder(begin + 1, i - 1);
	postorder(i, end);
	cout << root<<endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int value;
	int n = 0;
	while (cin >> value) {
		if (value == EOF) { break; }
		n++;
		preorder.push_back(value);
	}
	
	postorder(0, n - 1);

	return 0;
}