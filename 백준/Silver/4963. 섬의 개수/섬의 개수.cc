//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int W, H; 
int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

void solve() {
    vector<vector<bool>> visited(H);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int x;
            cin >> x;
            visited[i].push_back(!x);
        }
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j]) {
                visited[i][j] = 1;
                ans += 1;
                queue<pii> q;
                q.push({ i,j });
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int dir = 0; dir < 8; dir++) {
                        int nx = x + dx[dir]; int ny = y + dy[dir];
                        if (nx == -1 || nx == H || ny == -1 || ny == W ||visited[nx][ny]) continue;
                        q.push({ nx,ny });
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }
    cout << ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    while (1) {
        cin >> W >> H;
        if (W == 0 && H == 0) return 0;
        solve();
    }


    return 0;
}
