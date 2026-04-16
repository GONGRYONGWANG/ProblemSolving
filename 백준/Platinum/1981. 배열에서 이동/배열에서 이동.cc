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
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

int N;
int board[100][100];

bool bfs(int mn, int mx) {
    if (board[0][0]<mn || board[0][0]>mx || board[N-1][N-1]<mn || board[N-1][N-1]>mx) return false;

    bool visited[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    queue<pii> q;
    q.push({ 0,0 });
    visited[0][0] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] || board[nx][ny]<mn || board[nx][ny]>mx) continue;
            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
    if (visited[N - 1][N - 1]) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= 200; i++) {
        if (!bfs(i, 200)) break;
        int l = i;
        int r = 200;
        while (l < r){
            int m = (l + r) / 2;
            if (bfs(i, m)) r = m;
            else l = m + 1;
        }
        ans = min(ans, l - i);
    }
    cout << ans;

    return 0;
}