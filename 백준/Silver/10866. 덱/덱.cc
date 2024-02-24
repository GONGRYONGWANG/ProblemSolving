#pragma warning(disable: 4996)
#include<iostream>
using namespace std;
#define endl "\n"

#include<cstring>

template <typename T>
class dequeue {
private:
public:
	T arr[20000];
	int _size = 0;
	int _front = 10000;

	void push_back(int x) {
		arr[_front + _size] = x;
		_size++;
		return;
	}
	void push_front(int x) {
		_front -= 1;
		arr[_front] = x;
		_size++;
		return;
	}
	T pop_front() {
		if (_size == 0) { return -1; }
		auto tmp = arr[_front];
		_size--;
		_front++;
		return tmp;
	}
	T pop_back() {
		if (_size == 0) { return -1; }
		auto tmp = arr[_front+_size-1];
		_size--;
		return tmp;
	}
	int size() {
		return _size;
	}
	bool empty() {
		if (_size == 0) {
			return 1;
		}
		return 0;
	}
	T front() {
		if (_size == 0) { return -1; }
		return arr[_front];
	}
	T back() {
		if (_size == 0) { return -1; }
		else return arr[_front + _size - 1];
	}

};

int main() {
	dequeue<int> Q;
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		char a[11];
		scanf("%s", a);
		if (!strcmp(a, "push_front")) {
			int x;
			scanf("%d", &x);
			Q.push_front(x);
		}
		if (!strcmp(a, "push_back")) {
			int x;
			scanf("%d", &x);
			Q.push_back(x);
		}
		else if (!strcmp(a, "pop_front")) {
			printf("%d\n", Q.pop_front());
		}
		else if (!strcmp(a, "pop_back")) {
			printf("%d\n", Q.pop_back());
		}
		else if (!strcmp(a, "size")) {
			printf("%d\n", Q.size());
		}
		else if (!strcmp(a, "empty")) {
			printf("%d\n", Q.empty());
		}
		else if (!strcmp(a, "front")) {
			printf("%d\n", Q.front());
		}
		else if (!strcmp(a, "back")) {
			printf("%d\n", Q.back());
		}
	}
}
