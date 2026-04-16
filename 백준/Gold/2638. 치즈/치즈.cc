//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


vector<vector<int>> t;
vector<vector<int>> m;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	t.resize(N);
	m.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(M);
		t[i].resize(M,maxint);
		for(int j=0; j<M;j++){
			cin >> m[i][j];
			if (i == 0 || j == 0 || i == N - 1 || j == M - 1) {
				t[i][j] = 0;
			}
		}
	}


	bool change = 1;
	while (change) {
		change = 0;
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				int ogt = t[i][j];
				if (m[i][j] == 0) {
					for (int dir = 0; dir < 4; dir++) {
						t[i][j] = min(t[i][j], t[i + dx[dir]][j + dy[dir]]);
					}
				}
				else {
					int m_f = maxint; int m_s = maxint;
					for (int dir = 0; dir < 4; dir++) {
						if (t[i + dx[dir]][j + dy[dir]] < m_f) {
							m_s = m_f;
							m_f = t[i + dx[dir]][j + dy[dir]];
						}
						else if (t[i + dx[dir]][j + dy[dir]] < m_s) {
							m_s = t[i + dx[dir]][j + dy[dir]];
						}
						if (m_s != maxint) {
							t[i][j] = m_s + 1;
						}
					}
				}
				if (t[i][j] != ogt) { change = 1; }
			}
		}
	}
	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			time = max(time, t[i][j]);
		}
	}
	cout << time;
	return 0;
}
