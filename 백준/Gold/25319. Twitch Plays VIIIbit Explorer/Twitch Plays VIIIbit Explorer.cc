//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

char map[50][50];



#include<string>
#include<utility>
#include<vector>

int N, M, S, C, L;
vector<char> path;
pair<int, int> find_n_p(pair<int, int> c_p, char target) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == target) {
				map[i][j] = '0';
				return { i,j };
			}
		}
	}
	return{ -1,-1 };
}

void move(pair<int, int> c_p, pair<int, int> n_p) {
	int cx, cy, nx, ny;
	cy = c_p.first;
	cx = c_p.second;
	ny = n_p.first;
	nx = n_p.second;
	if (cx < nx) {
		for (int i = 0; i < nx - cx; i++) {
			path.push_back('R');
		}
	}
	else{
		for (int i = 0; i < cx - nx; i++) {
			path.push_back('L');
		}
	}

	if (cy < ny) {
		for (int i = 0; i < ny - cy; i++) {
			path.push_back('D');
		}
	}
	else {
		for (int i = 0; i < cy - ny; i++) {
			path.push_back('U');
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M >> S;
	C = 0;
	L = 0;
	pair<int, int> c_p = {0,0};
	pair<int, int> n_p;
	pair<int, int> f_p;
	string id;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> id;
	int idx = 0;
	while (1) {
		char x = id[idx];
		n_p = find_n_p(c_p, x);
		if (n_p.first == -1) {
			break;
		}
		move(c_p, n_p);
		path.push_back('P');
		idx++;
		if (idx == S) {
			idx = 0;
			C++;
			L = path.size();
			f_p = n_p;
		}
		c_p = n_p;
	}
	c_p = f_p;
	cout << C << " " << L+ M - 1 - c_p.second+ N - 1 - c_p.first <<endl;
	for (int i = 0; i < L; i++) {
		cout << path[i];
	}
	for (int i = 0; i < M - 1 - c_p.second; i++) {
		cout << "R";
	}
	for (int i = 0; i < N - 1 - c_p.first; i++) {
		cout << "D";
	}
	return 0;
}

