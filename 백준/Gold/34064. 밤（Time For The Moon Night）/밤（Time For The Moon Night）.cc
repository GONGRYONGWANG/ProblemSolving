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


bool board[501][501];
ll sz1[501][501];
ll sz2[501][501];
pii parent[501][501];
pii findp(pii p) {
    auto [x, y] = p;
    if (parent[x][y] == p) return p;
    return parent[x][y] = findp(parent[x][y]);
}

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    while (K--) {
        int x, y;
        cin >> x >> y;
        board[x][y] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            parent[i][j] = { i,j };
            if (board[i][j]) continue;
            for (int dir = 0; dir < 2; dir++) {
                int nx = i + dx[dir]; int ny = j + dy[dir];
                if (nx <= 0 || ny <= 0) continue;
                if (board[nx][ny]) continue;
                parent[findp({ nx,ny }).first][findp({ nx,ny }).second] = findp({ i,j });
            }
        }
    }
    
    int a1, b1, a2, b2, a3, b3, a4, b4;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j]) continue;
            auto [x,y] = findp({ i,j });
            if (a1 <= i && i <= a2 && b1 <= j && j <= b2) sz1[x][y] += 1;
            if (a3 <= i && i <= a4 && b3 <= j && j <= b4) sz2[x][y] += 1;
        }
    }

    ll ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans += sz1[i][j] * sz2[i][j];
        }
    }

    cout << ans;

    




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