#include<iostream>
using namespace std;
#define endl "\n"

#include<stack>

long long NGE[1000001];

long long N;
int main() {
	cin >> N;
	stack<long long> S;
	stack<long long> idx;
	long long tmp;
	for (long long i = 0; i < N; i++) {
		cin >> tmp;
		while (!S.empty() && tmp > S.top()) {
			NGE[idx.top()] = tmp;
			S.pop();
			idx.pop();
		}
		S.push(tmp);
		idx.push(i);
	}
	while (!S.empty()) {
		NGE[idx.top()] = -1;
		S.pop();
		idx.pop();
	}
	for (long long i = 0; i < N; i++) {
		cout << NGE[i]<<" ";
	}
	return 0;
}