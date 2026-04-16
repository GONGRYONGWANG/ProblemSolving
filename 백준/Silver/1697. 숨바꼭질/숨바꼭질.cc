#include<iostream>
#include<utility>
#include<vector>
using namespace std;
#define endl "\n"

int N, K;
int Time;
bool position[100001];
vector<int> BFS(vector<int> v);
int main() {
	cin >> N >> K;
	Time = 0;
	if (N == K) { cout << Time; return 0; }
	position[N] = 1;
	BFS({ N });
	cout << Time;
	return 0;
}
vector<int> BFS(vector<int> v) {
	vector<int> result;
	if (position[K]) {
		return result;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0 && position[v[i]-1]==0) {
			result.push_back(v[i] - 1);
			position[v[i] - 1] = 1;
		}
		if (v[i] < K && position[v[i]+1] == 0) {
			result.push_back(v[i] + 1);
			position[v[i] + 1] = 1;
		}
		if (v[i] * 2 < 100001 && position[v[i]*2] == 0) {
			result.push_back(v[i] * 2);
			position[v[i] * 2] = 1;
		}
	}
	Time++;
	return BFS(result);
}
