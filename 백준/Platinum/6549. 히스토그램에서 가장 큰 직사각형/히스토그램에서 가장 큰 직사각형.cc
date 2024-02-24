#include<iostream>
using namespace std;
#define endl "\n"

#include<stack>

int n;                     //      i
long long height[100001];  //0 2 2 1 2 2
						   //0 1 
long long HG() {
	long long h;
	height[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		height[i] = h;
	}
	stack<int> S;
	S.push(0);
	long long weight;
	long long result = 0;
	for (int i = 1; i <= n; i++) {
		while (height[i] < height[S.top()]) {
			h = height[S.top()];
			S.pop();
			weight = h * (i - S.top() - 1);
			if (weight > result) { result = weight; }
		}
		S.push(i);
	}
	while (S.top() != 0) {
		h = height[S.top()];
		S.pop();
		weight = h * (n - S.top());
		if (weight > result) { result = weight; }
	}

	return result;
}
int main() {
	while (1) {
		cin >> n;
		if (n == 0) { return 0; }
		cout << HG() << endl;
	}
	return 0;
}