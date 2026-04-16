//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int N;
int board[127][127];
bool visited[127][127];
int problemnum;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a[2] > b[2];
    }
};

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            visited[i][j] = 0;
        }
    }
    int br, x, y;
    priority_queue<vector<int>,vector<vector<int>>, compare> q;
    q.push({ 1,1,0 });
    while (!q.empty()) {
        br = q.top()[2]; x = q.top()[0]; y = q.top()[1];
        q.pop();
        visited[x][y] = 1;

        br = br + board[x][y];
        if (x == N && y == N) {
            cout << "Problem " << problemnum << ": " << br << endl;
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (x+dx[i] == 0 || y+dy[i] == 0 || x+dx[i] == N + 1 || y+dy[i] == N + 1 || visited[x + dx[i]][y + dy[i]]) {
                continue;
            }
            q.push({ x + dx[i],y + dy[i], br });
        }
    }
    return;
}



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    problemnum = 0;
    while (N != 0) {
        problemnum += 1;
        solve();
        cin >> N;
    }
    return 0;
}