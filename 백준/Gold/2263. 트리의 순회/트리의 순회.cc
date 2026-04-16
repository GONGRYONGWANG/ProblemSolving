#include<iostream>
using namespace std;
#define endl "\n"

#define MAX 100001


int n;
int inorder[MAX];
int postorder[MAX];

void preorder(int inbegin, int inend, int postbegin, int postend) {
	if (inbegin > inend) {
		return;
	}
	cout << postorder[postend] << " ";
	int i;
	for (i = inbegin; i < inend; i++) {
		if (inorder[i] == postorder[postend]) { break; }
	}
	preorder(inbegin, i-1, postbegin, postbegin + i - inbegin - 1);
	preorder(i + 1, inend, postbegin + i - inbegin, postend - 1);


	return;
}


int main() {
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		inorder[i] = tmp;
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		postorder[i] = tmp;
	}
	preorder(0, n - 1, 0, n-1);




	return 0;
}