// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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
#define INF ll(4e18)
const int inf = 1e9 + 7;
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

int board[100][100];
int DP[100][100];
bool visited[100][100];
bool isv[100][100];

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }
};

void solve(int tc) {

    int N, M, V;
    cin >> N >> M >> V;
    int X, Y;
    cin >> X >> Y;
    X -= 1; Y -= 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            DP[i][j] = -1;
        }
    }

    pq<vector<int>, vector<vector<int>>, cmp> Q;

    for (int i = 0; i < V; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        x -= 1; y -= 1;
        Q.push({ x,y,t });
        isv[x][y] = true;
    }

    while (!Q.empty()) {
        int x = Q.top()[0];
        int y = Q.top()[1];
        int t = Q.top()[2];
        Q.pop();
        if (DP[x][y] != -1) continue;
        DP[x][y] = t;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (DP[nx][ny] != -1) continue;
            Q.push({ nx,ny,t + 1 });
        }
    }

    int ans = 0;
    int time = 0;

    queue<vector<int>> q;
    q.push({ X,Y,0 });
    visited[X][Y] = true;
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int t = q.front()[2];
        q.pop();

        if (isv[x][y] || t >= DP[x][y]) continue;

        if (board[x][y] > ans) {
            ans = board[x][y];
            time = t;
        }
        else if (board[x][y] == ans && t < time) time = t;


        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({ nx,ny,t + 1 });
        }
    }

    cout << ans << " " << time;

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