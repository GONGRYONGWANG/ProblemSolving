//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

bool board[50][50];
bool visited[50][50];

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[2] > b[2];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x;
            cin >> x;
            if (x == '0') {
                board[i][j] = 0;
            }
            else {
                board[i][j] = 1;
            }
        }
    }
    pq<vector<int>, vector<vector<int>>, cmp> q;
    q.push({ 0,0,0 });
    while (!q.empty()) {
        int x = q.top()[0];
        int y = q.top()[1];
        int b = q.top()[2];
        q.pop();
        if (x == -1 || x == N || y == -1 || y == N) continue;
        if (visited[x][y]) continue;
        visited[x][y] = 1;
        if (!board[x][y]) b += 1;
        if (x == N - 1 && y == N - 1) {
            cout << b;
            return 0;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            q.push({ nx,ny,b });
        }
    }
    return 0;
}