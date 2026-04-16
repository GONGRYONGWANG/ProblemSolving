#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

// #11729


int N;

int heap[100000];
int heapsize;

void swap(int a, int b) {
	int tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
	return;
}

void push(int x) {
	heap[++heapsize] = x;
	int child = heapsize;
	int parent = child / 2;

	while (child > 1 && heap[child] > heap[parent]) {
		swap(child, parent);
		child = parent;
		parent = child / 2;
	}
}

int pop() {
	if (heapsize == 0) { return 0; }
	int result = heap[1];
	swap(1, heapsize);
	heapsize--;
	int parent = 1;
	int child = 2;
	if (child + 1 <= heapsize && heap[child + 1] > heap[child]) { child++; }
	while (child <= heapsize && heap[parent] < heap[child]) {
		swap(parent, child);
		parent = child;
		child *= 2;
		if (child + 1 <= heapsize && heap[child + 1] > heap[child]) { child++; }
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int x;
	cin >> N;
	heapsize = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			cout << pop()<<endl;
		}
		else {
			push(x);
		}
	}
	return 0;
}