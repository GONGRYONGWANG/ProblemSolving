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
		if (Size == -1) { return; }
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
	void total() {
		int total=0;
		for (int i = 0; i < Size + 1; i++) {
			total += A[i];
		}
		cout << total;
	}
private:
	vector<int> A;
	int Size = -1;
};

int main() {
	int K;
	cin >> K;
	stack ST;
	int a;
	for (int i = 0; i < K; i++) {
		cin >> a;
		if (a == 0) { ST.pop(); }
		else ST.push(a);
	}
	ST.total();
}