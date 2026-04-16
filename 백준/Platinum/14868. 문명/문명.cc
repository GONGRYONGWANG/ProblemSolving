#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);



#include<vector>
#include<utility>
#include<queue>

pair<int, int> parent[2001][2001];

pair<int, int >find(pair<int, int> x) {
	if (parent[x.first][x.second] == x) { return x; }
	return parent[x.first][x.second] = find(parent[x.first][x.second]);
}

void merge(pair<int, int> a, pair<int, int> b) {
	if (find(a) == find(b)) { return; }
	a = find(a);
	b = find(b);
	parent[b.first][b.second] = a;
}

int N, K;
queue<pair<int, int>> civil;
vector<pair<int, int>> starting;
bool city[2001][2001];

void wwmergesur(pair<int, int> I) {
	int x = I.first;
	int y = I.second;
	if (x != 1 && find(I) != find({ x - 1,y }) && city[x - 1][y]) {
		merge(I, { x - 1,y });
	}
	if (x != N && find(I) != find({ x + 1,y }) && city[x + 1][y]) {
		merge(I, { x + 1,y });
	}
	if (y != 1 && find(I) != find({ x ,y - 1 }) && city[x][y - 1]) {
		merge(I, { x ,y - 1 });
	}
	if (y != N  && find(I) != find({ x ,y + 1 }) && city[x][y + 1]) {
		merge(I, { x ,y + 1 });
	}
}


void mergesur(pair<int, int> I) {
	int x = I.first;
	int y = I.second;
	if (x != 1 && find(I) != find({ x - 1,y })) {
		city[x - 1][y] = 1;
		merge(I, { x - 1,y });
		wwmergesur({ x - 1 , y });
		civil.push({ x - 1,y });
	}
	if (x != N && find(I) != find({ x + 1,y })) {
		city[x + 1][y] = 1;
		merge(I, { x + 1,y });
		wwmergesur({ x + 1 , y });
		civil.push({ x + 1,y });
	}
	if (y != 1 && find(I) != find({ x ,y - 1 })) {
		city[x][y - 1] = 1;
		merge(I, { x ,y - 1 });
		wwmergesur({ x , y - 1 });
		civil.push({ x ,y - 1 });
	}
	if (y != N && find(I) != find({ x ,y + 1 })) {
		city[x][y + 1] = 1;
		merge(I, { x ,y + 1 });
		wwmergesur({ x , y + 1 });
		civil.push({ x ,y + 1 });
	}
	civil.pop();
	return;
}

bool integrated() {
	for (int i = 1; i < K; i++) {
		if (find(starting[i]) != find(starting[0])) { return 0; }
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			parent[i][j] = { i,j };
		}
	}

	int a, b;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		civil.push({ a,b });
		starting.push_back({ a,b });
		city[a][b] = 1;
		wwmergesur({ a,b });
	}
	int cnt = 0;
	while (!integrated()) {
		int S = civil.size();
		for (int i = 0; i < S; i++) {
			mergesur(civil.front());
		}
		cnt++;
	}
	cout << cnt;

	return 0;
}
