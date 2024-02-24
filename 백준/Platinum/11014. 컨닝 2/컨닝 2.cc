#pragma warning(disable:4996) 
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

char board[81][81];
int dx[6] = { -1,-1, 0, 0,1,1 };
int dy[6] = { -1,1,-1,1,-1,1 };

unordered_map<int, vector<int>> E;
unordered_map<int, int> assign;
unordered_map<int, bool > done;

bool dfs(int x) {
    for (int i = 0; i < E[x].size(); i++) {
        int target = E[x][i];
        if (done[target]) continue;
        done[target] = 1;
        if (assign[target] == 0 || dfs(assign[target])) {
            assign[target] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        E.clear();
        assign.clear();
        done.clear();

        int N, M;
        cin >> N >> M;

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> board[i][j];
                if (board[i][j] == '.') ans += 1;
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j += 2) {
                if (board[i][j] == 'x')continue;
                for (int dir = 0; dir < 6; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx <= 0 || nx > N || ny <= 0 || ny > M || board[nx][ny] == 'x') continue;
                    E[i * 80 + j].push_back(nx * 80 + ny);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j += 2) {
                done.clear();
                if (dfs(i * 80 + j)) ans -= 1;
            }
        }
        cout << ans << endl;
    }
    

    return 0;
}