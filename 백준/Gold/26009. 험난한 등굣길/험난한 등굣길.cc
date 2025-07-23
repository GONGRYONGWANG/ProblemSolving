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
#include<chrono>
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

int DP[3002][3002];
int dist[3002][3002];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    int K; cin >> K;
    while (K--) {
        int r, c, d;
        cin >> r >> c >> d;
        d += 1;
        DP[r][c] = max(DP[r][c], d);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            DP[i][j] = max(DP[i][j], max(DP[i - 1][j], DP[i][j - 1]) - 1);
        }
    }

    for (int i = N; i >= 1; i--) {
        for (int j = M; j >= 1; j--) {
            DP[i][j] = max(DP[i][j], max(DP[i + 1][j], DP[i][j + 1]) - 1);
        }
    }

    queue<pii> q;
    q.push({ 1,1 });
    dist[1][1] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == N && y == M) {
            cout << "YES" << endl << dist[x][y] - 1;
            return;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if (dist[nx][ny] || DP[x][y]) continue;
            q.push({ nx,ny });
            dist[nx][ny] = dist[x][y] + 1;
        }
    }

    cout << "NO";




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