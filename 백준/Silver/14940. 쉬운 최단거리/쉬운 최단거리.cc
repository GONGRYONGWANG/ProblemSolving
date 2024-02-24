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

int board[1000][1000];
int ans[1000][1000];
bool visited[1000][1000];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    pii s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) s = { i,j };
            if (board[i][j] != 0) ans[i][j] = -1;
            else visited[i][j] = 1;
        }
    }
    queue<vector<int>> q;
    q.push({ s.first,s.second,0 });
    visited[s.first][s.second] = 1;
    ans[s.first][s.second] = 0;
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int t = q.front()[2];
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
            q.push({ nx,ny,t + 1 });
            visited[nx][ny] = 1;
            ans[nx][ny] = t + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j]<<" ";
        }
        cout << endl;
    }

    return 0;
}

