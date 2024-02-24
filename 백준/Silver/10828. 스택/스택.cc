#include <iostream>
#include<vector>
#include<string>
using namespace std;

#define endl "\n"

class stack {
public:
	void push(int a) {
		A.push_back(a);
		Size++;
	}
	void pop() {
		if (Size == -1) { cout << -1; return; }
		cout << A[Size];
		A.resize(Size);
		Size--;
	}
	void size() {
		cout << Size + 1;
	}
	void empty() {
		if (Size == -1) { cout << 1; }
		else cout << 0;
	}
	void top() {
		if (Size == -1) { cout << -1; }
		else cout << A[Size];
	}
private:
	vector<int> A;
	int Size = -1;
};

int main() {
	int N;
	cin >> N;
	stack ST;
	string S;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> S;
		if (S == "push") {
			cin >> a;
			ST.push(a);
			continue;
		}
		if (S == "pop") {
			ST.pop();
		}
		if (S == "size") {
			ST.size();
		}
		if (S == "empty") {
			ST.empty();
		}
		if (S == "top") {
			ST.top();
		}
		cout << endl;
	}
}