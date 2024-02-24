#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<cmath>
int N;
double x[100];
double y[100];
double result;
#include<queue>
bool visited[100];

struct cmp {
	bool operator()(pair<int, double> a, pair<int, double> b) {
		return a.second > b.second;
	}
};

double dist(int a, int b) {
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

void prim() {
	int visit = 1;
	visited[0] = 1;
	priority_queue<pair<int, double>, vector<pair<int, double>>, cmp> Q;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			Q.push({ i, dist(0,i) });
		}
	}
	while (!Q.empty() && visit != N) {
		int node = Q.top().first;
		if (visited[node]) { Q.pop(); continue; }
		visited[node] = 1;
		result += Q.top().second;
		visit++;
		Q.pop();
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				Q.push({ i,dist(node,i) });
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	result = 0;
	prim();

	cout << result;


	return 0;
}