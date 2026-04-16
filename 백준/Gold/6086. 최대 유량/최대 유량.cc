#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

int N;
int capacity[52][52];
int flow[52][52];

int MaximumFlow(int source, int sink) {
	memset(flow, 0, sizeof(flow));
	int total_flow = 0;

	while (1) {
		vector<int> parent(52, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);

		while (!q.empty() && parent[sink] == -1) {
			int here = q.front();
			q.pop();

			for (int i = 0; i < 52; i++) {
				if (capacity[here][i] - flow[here][i] > 0 && parent[i] == -1) {
					q.push(i);
					parent[i] = here;
				}
			}
		}

		if (parent[sink] == -1) break;

		int amount = 1e9;

		for (int p = sink; p != source; p = parent[p]) {
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		}

		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}

		total_flow += amount;

	}

	return total_flow;
}


int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	char p1, p2;
	int _p1, _p2;
	int _capacity;

	memset(capacity, 0, sizeof(capacity));

	for (int i = 0; i < N; i++) {
		cin >> p1 >> p2 >> _capacity;
		if ((int)p1 < 97) { _p1 = (int)p1 - 65; }
		else { _p1 = (int)p1 - 71; }
		if ((int)p2 < 97) { _p2 = (int)p2 - 65; }
		else { _p2 = (int)p2 - 71; }
		capacity[_p1][_p2] += _capacity;
		capacity[_p2][_p1] += _capacity;
	}

	cout << MaximumFlow(0, 25);

	return 0;
}