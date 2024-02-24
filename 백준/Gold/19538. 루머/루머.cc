#include<iostream>
using namespace std;
#define endl "\n"
#define INF 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
int N;
int M;
vector<int> line[200001];
int time[200001];
bool isinfected[200001];
int clock = 0;

bool contage(int x) {
	int count = 0;
	for (int i = 0; i < line[x].size(); i++) {
		if (time[line[x][i]] != -1) {
			count++;
		}
	}
	if (count * 2 >= line[x].size()) {
		return 1;
	}
	return 0;
}

void infection(vector<int> infected) {
	clock++;
	vector<int> inf;
	for (int i = 0; i < infected.size(); i++) {
		for (int j = 0; j < line[infected[i]].size(); j++) {
			if (!isinfected[line[infected[i]][j]] && contage(line[infected[i]][j])) {
				inf.push_back(line[infected[i]][j]);
				isinfected[line[infected[i]][j]] = 1;
			}
		}
	}
	if (inf.empty()) { return; }
	for (int i = 0; i < inf.size(); i++) {
		time[inf[i]] = clock;
		infected.push_back(inf[i]);
	}
	infection(inf);
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	int tmp;
	vector<int> infected;
	for (int i = 1; i <= N; i++) {
		time[i] = -1;
		cin >> tmp;
		while(tmp != 0) {
			line[i].push_back(tmp);
			cin >> tmp;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		infected.push_back(tmp);
		time[tmp]=0;
		isinfected[tmp] = 1;
	}
	infection(infected);

	for (int i = 1; i <= N; i++) {
		cout << time[i] << " ";
	}

	return 0;
}

