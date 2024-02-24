//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;


vector<vector<char>> board;
pair<int, int> o;

int solve(pair<int, int> r, pair<int, int> b, int it);

int up(pair<int,int> r, pair<int,int> b, int it) {
	if (r.second == b.second && b.first < r.first) {
		while (board[b.first - 1][b.second] != '#'&& b!=o) {
			b.first--;
		}

		if (b == o) {
			return 11;
		}
		while (board[r.first - 1][r.second] != '#'&& r.first-1 != b.first && r!=o) {
			r.first--;
		}
		if (r == o) {
			return 1;
		}
		else return 1 + solve(r, b, it+1);
	}

	else if (r.second == b.second && r.first<b.first) {
		while (board[r.first - 1][r.second] != '#' && r!=o) {
			r.first--;
		}
		while (board[b.first - 1][b.second] != '#' && b != o && b.first-1 !=r.first) {
			b.first--;
		}

		if (r == o) {
			if (b.first - 1 == r.first) {
				return 11;
			}
			else return 1;
		}
		else return 1 + solve(r, b, it+1 );
	}

	while (board[r.first - 1][r.second] != '#' && r != o) {
		r.first--;
	}
	while (board[b.first - 1][b.second] != '#' && b != o) {
		b.first--;
	}
	if (b == o) { return 11; }
	if (r == o) { return 1; }
	else return 1 + solve(r, b,it+1);
}

int down(pair<int, int> r, pair<int, int> b, int it) {
	if (r.second == b.second && b.first > r.first) {
		while (board[b.first + 1][b.second] != '#' && b != o) {
			b.first++;
		}

		if (b == o) {
			return 11;
		}
		while (board[r.first + 1][r.second] != '#' && r.first + 1 != b.first && r != o) {
			r.first++;
		}
		if (r == o) {
			return 1;
		}
		else return 1 + solve(r, b, it + 1);
	}

	else if (r.second == b.second && r.first > b.first) {
		while (board[r.first + 1][r.second] != '#' && r != o) {
			r.first++;
		}
		while (board[b.first + 1][b.second] != '#' && b != o && b.first + 1 != r.first) {
			b.first++;
		}

		if (r == o) {
			if (b.first + 1 == r.first) {
				return 11;
			}
			else return 1;
		}
		else return 1 + solve(r, b, it + 1);
	}

	while (board[r.first + 1][r.second] != '#' && r != o) {
		r.first++;
	}
	while (board[b.first + 1][b.second] != '#' && b != o) {
		b.first++;
	}
	if (b == o) { return 11; }
	if (r == o) { return 1; }
	else return 1 + solve(r, b, it + 1);
}

int right(pair<int, int> r, pair<int, int> b, int it) {
	if (r.first == b.first && b.second > r.second) {
		while (board[b.first][b.second+1] != '#' && b != o) {
			b.second++;
		}

		if (b == o) {
			return 11;
		}
		while (board[r.first][r.second+1] != '#' && r.second + 1 != b.second && r != o) {
			r.second++;
		}
		if (r == o) {
			return 1;
		}
		else return 1 + solve(r, b, it + 1);
	}

	else if (r.first == b.first && r.second > b.second) {
		while (board[r.first][r.second+1] != '#' && r != o) {
			r.second++;
		}
		while (board[b.first][b.second+1] != '#' && b != o && b.second + 1 != r.second) {
			b.second++;
		}

		if (r == o) {
			if (b.second + 1 == r.second) {
				return 11;
			}
			else return 1;
		}
		else return 1 + solve(r, b, it + 1);
	}

	while (board[r.first][r.second+1] != '#' && r != o) {
		r.second++;
	}
	while (board[b.first][b.second+1] != '#' && b != o) {
		b.second++;
	}
	if (b == o) { return 11; }
	if (r == o) { return 1; }
	else return 1 + solve(r, b, it + 1);
}

int left(pair<int, int> r, pair<int, int> b, int it) {
	if (r.first == b.first && b.second < r.second) {
		while (board[b.first][b.second - 1] != '#' && b != o) {
			b.second--;
		}

		if (b == o) {
			return 11;
		}
		while (board[r.first][r.second - 1] != '#' && r.second - 1 != b.second && r != o) {
			r.second--;
		}
		if (r == o) {
			return 1;
		}
		else return 1 + solve(r, b, it + 1);
	}

	else if (r.first == b.first && r.second < b.second) {
		while (board[r.first][r.second - 1] != '#' && r != o) {
			r.second--;
		}
		while (board[b.first][b.second - 1] != '#' && b != o && b.second - 1 != r.second) {
			b.second--;
		}

		if (r == o) {
			if (b.second - 1 == r.second) {
				return 11;
			}
			else return 1;
		}
		else return 1 + solve(r, b, it + 1);
	}

	while (board[r.first][r.second - 1] != '#' && r != o) {
		r.second--;
	}
	while (board[b.first][b.second - 1] != '#' && b != o) {
		b.second--;
	}
	if (b == o) { return 11; }
	if (r == o) { return 1; }
	else return 1 + solve(r, b, it + 1);
}


int solve(pair<int,int> r, pair<int,int> b,int it) {
	if (it > 10) { return 11; }
	int result = min(up(r, b, it),down(r,b,it));
	result = min(result, right(r, b, it));
	result = min(result, left(r, b, it));
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	board.resize(N);
	char x;
	pair<int, int> r, b;
	for (int i = 0; i < N; i++ ){
		for (int j = 0; j < M; j++) {
			cin >> x;
			if (x == 'R') {
				r = { i,j };
				x = '.';
			}
			else if (x == 'B') {
				b = { i,j };
				x = '.';
			}
			else if (x == 'O') {
				o = { i,j };
				x = '.';
			}
			board[i].push_back(x);
		}
	}
	int ans = solve(r, b, 1);
	if (ans > 10) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}
