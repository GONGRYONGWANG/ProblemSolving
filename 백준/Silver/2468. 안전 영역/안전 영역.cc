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

pii parent[101][101];
pii findp(pii p) {
    if (parent[p.first][p.second] == p) return p;
    return parent[p.first][p.second] = findp(parent[p.first][p.second]);
}

int board[101][101];
vector<pii> arr[101];

void solve() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            parent[i][j] = { i,j };
            int h;
            cin >> h;
            arr[h].push_back({ i,j });
            board[i][j] = h;
        }
    }


    int ans = 0;
    int ret = 0;
    for (int h = 100; h >= 1; h--) {
        for (pii p : arr[h]) {
            ret += 1;
            int x = p.first; int y = p.second;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                if (nx<1 || nx>N || ny<1 || ny>N) continue;
                if (board[nx][ny] < h) continue;
                if (findp({ x,y }) == findp({ nx,ny })) continue;
                ret -= 1;
                parent[findp(p).first][findp(p).second] = findp({ nx,ny });
            }
        }
        ans = max(ans, ret);
    }

    cout << ans;




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