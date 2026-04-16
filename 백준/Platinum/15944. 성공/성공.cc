#include<iostream>
#include<iomanip>
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
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;

bool board[500][500];
bool visited[500][500];
bool inq[500][500];

void solve() {
    int N, M, D;
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;
            board[i][j] = (x == '#');
        }
    }


    deque<vector<int>> q;

    q.push_back({ 0,0,0 });
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int d = q.front()[2];
        q.pop_front();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        if (x == N - 1 && y == M - 1) {
            cout << d;
            return;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny]) continue;
            q.push_front({ nx,ny,d });
            inq[nx][ny] = true;
        }

        for (int dir = 0; dir < 4; dir++) {
            for (int i = -(D - 1); i <= D - 1; i++) {
                int nx = x + dx[dir] * D + i * (dx[(dir + 2) % 4]); int ny = y + dy[dir] * D + i * (dy[(dir + 2) % 4]);
                nx = min(max(nx, 0), N - 1); ny = min(max(ny, 0), M - 1);
                if (visited[nx][ny]) continue;
                if (inq[nx][ny]) continue;
                q.push_back({ nx,ny,d + 1 });
                inq[nx][ny] = true;
            }
        }
    }


}



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }





    return 0;
}