//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

vector<vector<int>> board_idx;
vector<pair<int, int>> idx_board;
vector<int> idx_val;

int dx[4] = { 0,1,0,-1 }; // left, down, right, up
int dy[4] = { -1,0,1,0 }; // left, down, right, up


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	// index initialization
	board_idx.resize(N);
	for (int i = 0; i < N; i++) {
		board_idx[i].resize(N);
	}
	idx_board.resize(N * N);
	idx_val.resize(N * N);
	int dir = 0;
	int x = N / 2;
	int y = N / 2;
	int idx = 0;
	for (int i = 1; i <= N-1; i++) {
		for (int j = 0; j < i; j++) {
			x = x + dx[dir];
			y = y + dy[dir];
			board_idx[x][y] = ++idx;
			idx_board[idx] = make_pair(x, y);
		}
		dir = (dir + 1) % 4;
		for (int j = 0; j < i; j++) {
			x = x + dx[dir];
			y = y + dy[dir];
			board_idx[x][y] = ++idx;
			idx_board[idx] = make_pair(x, y);
		}
		dir = (dir + 1) % 4;
	}
	for (int j = 0; j < N-1; j++) {
		x = x + dx[dir];
		y = y + dy[dir];
		board_idx[x][y] = ++idx;
		idx_board[idx] = make_pair(x, y);
	}
	

	// value initialization
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> idx_val[board_idx[i][j]];
		}
	}

	// test
	/*cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << idx_val[board_idx[i][j]] << " ";
		}
		cout << endl;
	}*/
	//


	vector<int> q;
	int score = 0;

	while (M--) {

		//blizzard

		int d, s;
		cin >> d >> s;

		switch (d) 
		{
		case 1:
			dir = 3;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		case 4:
			dir = 2;
			break;
		}

		x = N / 2; y = N / 2;
		x = x + dx[dir];
		y = y + dy[dir];
		int prev_x = x, prev_y = y;
		for (int i = 1; i < s; i++) {
			x = x + dx[dir];
			y = y + dy[dir];
			for (int j = board_idx[prev_x][prev_y]+1; j <= board_idx[x][y]; j++) {
				idx_val[j-i] = idx_val[j];
			}
			prev_x = x;
			prev_y = y;
		}
		for (int j = board_idx[x][y] + 1; j <= board_idx[0][0]; j++) {
			idx_val[j - s] = idx_val[j];
		}
		for (int j = N * N - s; j < N * N; j++) {
			idx_val[j] = 0;
		}


		// test
		/*cout << "Blizzard";
		cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << idx_val[board_idx[i][j]] << " ";
			}
			cout << endl;
		}*/
		//

		// explposion

		int cnt = 0;

		bool change = 1;
		while (change) {
			change = 0;
			q.clear();
			q.push_back(0);
			for (int i = 1; i < N * N; i++) {
				if (q.back() == 0) {
					q.push_back(idx_val[i]);
					cnt = 1;
				}
				else if (idx_val[i] == q.back()) {
					q.push_back(idx_val[i]);
					cnt++;
				}
				else {
					if (cnt >= 4) {
						score += q.back() * cnt;
						for (int j = 0; j < cnt; j++) {
							q.pop_back();
						}
						change = 1;
					}
					q.push_back(idx_val[i]);
					cnt = 1;
				}
				if (idx_val[i] == 0) {
					break;
				}
			}
			idx_val = q;
		}
		for (int i = idx_val.size(); i < N * N; i++) {
			idx_val.push_back(0);
		}

		// test
		/*cout << "Explosion";
		cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << idx_val[board_idx[i][j]] << " ";
			}
			cout << endl;
		}*/
		//

		//group
		int val=0;
		cnt = 1;
		q.clear();
		q.push_back(0);
		for (int i = 1; i < N * N; i++) {
			if (val == 0) {
				val = idx_val[i];
				cnt = 1;
			}
			else  if (idx_val[i] == val) {
				cnt++;
			}
			else {
				q.push_back(cnt);
				q.push_back(val);
				val = idx_val[i];
				cnt = 1;
			}
			if (idx_val[i] == 0) {
				break;
			}
		}
		idx_val = q;
		for (int i = idx_val.size(); i < N * N; i++) {
			idx_val.push_back(0);
		}

		// test
		/*cout << "Group";
		cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << idx_val[board_idx[i][j]] << " ";
			}
			cout << endl;
		}*/
		//

	}
	cout << score;


	return 0;
}