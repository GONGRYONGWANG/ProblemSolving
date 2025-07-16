// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


bool board[1000][1000];
int dist1[1000][1000];
int dist2[1000][1000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x; cin >> x;
            board[i][j] = (x == '1');
        }
    }

    queue<pii> q;

    q.push({ 0,0 });
    dist1[0][0] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist1[nx][ny]) continue;
            dist1[nx][ny] = dist1[x][y] + 1;
            if (!board[nx][ny]) q.push({ nx,ny });
        }
    }

    q.push({ N - 1,M - 1 });
    dist2[N - 1][M - 1] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist2[nx][ny]) continue;
            dist2[nx][ny] = dist2[x][y] + 1;
            if (!board[nx][ny]) q.push({ nx,ny });
        }
    }

    int ans = inf;

    for (int i = 0; i < N; i++) {
        int dist1mn = inf;
        int dist2mn = inf;
        for (int j = 0; j < M; j++) {
            if (dist1[i][j] == 0) dist1[i][j] = inf;
            if (dist2[i][j] == 0) dist2[i][j] = inf;
            dist1mn += 1; dist2mn += 1;
            dist1mn = min(dist1mn, dist1[i][j]);
            dist2mn = min(dist2mn, dist2[i][j]);
            if (board[i][j]) continue;
            ans = min(ans, dist1mn + dist2[i][j]);
            ans = min(ans, dist2mn + dist1[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        int dist1mn = inf;
        int dist2mn = inf;
        for (int j = M - 1; j >= 0; j--) {
            if (dist1[i][j] == 0) dist1[i][j] = inf;
            if (dist2[i][j] == 0) dist2[i][j] = inf;
            dist1mn += 1; dist2mn += 1;
            dist1mn = min(dist1mn, dist1[i][j]);
            dist2mn = min(dist2mn, dist2[i][j]);
            if (board[i][j]) continue;
            ans = min(ans, dist1mn + dist2[i][j]);
            ans = min(ans, dist2mn + dist1[i][j]);
        }
    }

    for (int j = 0; j < M; j++) {
        int dist1mn = inf;
        int dist2mn = inf;
        for (int i = 0; i < N; i++) {
            dist1mn += 1; dist2mn += 1;
            dist1mn = min(dist1mn, dist1[i][j]);
            dist2mn = min(dist2mn, dist2[i][j]);
            if (board[i][j]) continue;
            ans = min(ans, dist1mn + dist2[i][j]);
            ans = min(ans, dist2mn + dist1[i][j]);
        }
    }

    for (int j = 0; j < M; j++) {
        int dist1mn = inf;
        int dist2mn = inf;
        for (int i = N - 1; i >= 0; i--) {
            dist1mn += 1; dist2mn += 1;
            dist1mn = min(dist1mn, dist1[i][j]);
            dist2mn = min(dist2mn, dist2[i][j]);
            if (board[i][j]) continue;
            ans = min(ans, dist1mn + dist2[i][j]);
            ans = min(ans, dist2mn + dist1[i][j]);
        }
    }

    if (ans == inf) cout << -1;
    else cout << ans - 2;

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}