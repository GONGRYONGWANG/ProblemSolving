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
#include<complex> // complex number
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

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

/*
int COMB[100][100];
int comb(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;
    if (COMB[n][r]) return COMB[n][r];
    return COMB[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
} 
*/

//////////////////////////////////////////////////////////////////////////////////////


int board[100][100];
int visited[100][100];

void solve() {
    int N, M, T;
    cin >> N >> M >> T;

    pii sword;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                sword = { i,j };
            }
            visited[i][j] = inf;
        }
    }

    queue<pii> q;
    q.push({ 0,0 });
    visited[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 1 || visited[nx][ny]!=inf) continue;
            q.push({ nx,ny });
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    
    int ans = min(visited[N - 1][M - 1], visited[sword.first][sword.second] + (N - 1 - sword.first + M - 1 - sword.second));
    if (ans > T) cout << "Fail";
    else cout << ans;

}



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}