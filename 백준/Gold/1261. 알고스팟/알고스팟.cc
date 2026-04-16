//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

char board[100][100];
int BW[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct cmp {
    bool operator()(vector<int>a, vector<int> b) {
        return a[0] > b[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int M, N;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            BW[i][j] = -1;
        }
    }
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    q.push({ 0,0,0 });
    while (!q.empty()) {
        int bw = q.top()[0]; int x = q.top()[1]; int y = q.top()[2];
        q.pop();
        if (x == N - 1 && y == M - 1) {
            cout << bw; return 0;
        }
        if (BW[x][y] != -1) continue;
        BW[x][y] = bw;
        int nx, ny;
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx == -1 || nx == N || ny == -1 || ny == M) continue;
            if (BW[nx][ny] == -1) {
                if (board[nx][ny] == '0') {
                    q.push({ bw,nx,ny });
                }
                else {
                    q.push({ bw+1,nx,ny });
                }
            }
        }
    }
    return 0;
}
