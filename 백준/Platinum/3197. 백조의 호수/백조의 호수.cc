#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);



#include<vector>
#include<utility>
#include<queue>

pair<int,int> parent[1500][1500];

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

int R, C;
vector<pair<int, int>> swan; 
queue<pair<int, int>> water;
bool ice[1500][1500];

void wwmergesur(pair<int, int> I) {
	int x = I.first;
	int y = I.second;
	if (x != 0 && find(I) != find({ x - 1,y })&&!ice[x-1][y]) {
		merge(I, { x - 1,y });
	}
	if (x != R - 1 && find(I) != find({ x + 1,y }) && !ice[x+1][y]) {
		merge(I, { x + 1,y });
	}
	if (y != 0 && find(I) != find({ x ,y - 1 })&& !ice[x][y-1]) {
		merge(I, { x ,y - 1 });
	}
	if (y != C - 1 && find(I) != find({ x ,y + 1 })&& !ice[x][y+1]) {
		merge(I, { x ,y + 1 });
	}
}


void mergesur(pair<int, int> I) {
	int x = I.first;
	int y = I.second;
	if (x != 0 && find(I) != find({ x - 1,y })) {
		ice[x - 1][y] = 0;
		merge(I, { x - 1,y });
		wwmergesur({ x - 1 , y });
		water.push({ x - 1,y });
	}
	if (x != R-1 && find(I) != find({ x + 1,y })) {
		ice[x + 1][y] =0;
		merge(I, { x + 1,y });
		wwmergesur({ x + 1 , y });
		water.push({ x + 1,y });
	}
	if (y != 0 && find(I) != find({ x ,y - 1 })) {
		ice[x][y - 1] = 0;
		merge(I, { x ,y - 1 });
		wwmergesur({ x , y - 1 });
		water.push({ x ,y - 1 });
	}
	if (y != C-1 && find(I) != find({ x ,y + 1 })) {
		ice[x][y + 1] = 0;
		merge(I, { x ,y + 1 });
		wwmergesur({ x , y + 1});
		water.push({ x ,y + 1 });
	}
	water.pop();
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> R >> C;
	char tmp;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> tmp;
			if (tmp == '.') { water.push({i,j}); }
			else if (tmp == 'L') { water.push({ i,j }); swan.push_back({ i,j }); }
			else { ice[i][j] = 1; }
			parent[i][j] = { i,j };
		}
	}
	int cnt = 0;
	while (find(swan[0]) != find(swan[1])) {
		int S = water.size();
		for (int i = 0; i < S; i++) {
			mergesur(water.front());
		}
		cnt++;
	}
	cout << cnt;

	return 0;
}
