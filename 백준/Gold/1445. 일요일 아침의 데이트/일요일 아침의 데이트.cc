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


struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[2] == b[2]) return a[3] > b[3];
        return a[2] > b[2];
    }
};


bool board[50][50];
bool visited[50][50];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    pii s, f;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            char x; cin >> x;
            if (x == 'S') s = { i,j };
            else if (x == 'F') f = { i,j };

            if (x == 'g') board[i][j] = true;

        }
    }

    pq<vector<int>, vector<vector<int>>, cmp> q;
    q.push({ s.first,s.second,0,0 });
    while (!q.empty()) {
        int x = q.top()[0]; int y = q.top()[1];
        int a = q.top()[2]; int b = q.top()[3];
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        if (f == make_pair(x, y)) {
            cout << a << " " << b;
            return;
        }
        if (x != s.first || y != s.second) {
            if (board[x][y]) a += 1;
            else {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir]; int ny = y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (board[nx][ny]) {
                        b += 1;
                        break;
                    }
                }
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            q.push({ nx,ny,a,b });
        }
    }




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