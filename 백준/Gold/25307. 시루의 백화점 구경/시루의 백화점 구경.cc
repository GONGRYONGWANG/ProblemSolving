// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
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
const ll INF = 1e18 + 7;
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

int board[2001][2001];

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;
    pii s;
    queue<vector<int>> q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 4) s = { i,j };
            else if (board[i][j] == 3) q.push({ i,j,K });
        }
    }

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int k = q.front()[2];
        q.pop();
        if (k == 0) continue;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if (board[nx][ny] == 3) continue;
            board[nx][ny] = 3;
            q.push({ nx,ny,k-1 });
        }
    }

    q.push({ s.first,s.second,0 });
    board[s.first][s.second] = -1;
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int d = q.front()[2];
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if (board[nx][ny] == -1 || board[nx][ny] == 3 || board[nx][ny] == 1) continue;
            if (board[nx][ny] == 2) {
                cout << d + 1;
                return;
            }
            board[nx][ny] = -1;
            q.push({ nx,ny,d + 1 });
        }
    }
    
    cout << -1;




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