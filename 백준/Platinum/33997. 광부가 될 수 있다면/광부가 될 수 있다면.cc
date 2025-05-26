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

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


int N, M;
ll psum[1001][1001];
ll to_left[1001][1001];
ll to_right[1001][1001];

struct cmp {
    bool operator()(vector<ll>& a, vector<ll>& b) {
        return a[3] < b[3];
    }
};

ll DP[1001][1001][3];

ll dp(int x, int y, int dir) {
    if (DP[x][y][dir] != INF) return DP[x][y][dir];
    if (dir == 0) {
        if (x == 1) return DP[x][y][dir] = psum[x][y] - psum[x][y - 1];
        DP[x][y][dir] = max(max(dp(x - 1, y, 0), dp(x - 1, y, 1) + to_left[x - 1][y]), dp(x - 1, y, 2) + to_right[x - 1][y]) + psum[x][y] - psum[x][y - 1];
    }
    else if (dir == 1) {
        DP[x][y][dir] = dp(x, y, 0) + to_right[x][y];
        if (y != 1) DP[x][y][dir] = max(DP[x][y][dir], dp(x, y - 1, dir) + psum[x][y] - psum[x][y - 1]);
    }
    else {
        DP[x][y][dir] = dp(x, y, 0) + to_left[x][y];
        if (y != M) DP[x][y][dir] = max(DP[x][y][dir], dp(x, y + 1, dir) + psum[x][y] - psum[x][y - 1]);
    }
    return DP[x][y][dir];
}

void solve(int tc) {
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> psum[i][j];
            psum[i][j] += psum[i][j - 1];
            for (int dir = 0; dir < 3; dir++) DP[i][j][dir] = INF;
        }
    }

    for (int i = 1; i <= N; i++) {
        ll mn = 0;
        for (int j = 1; j <= M; j++) {
            to_right[i][j] = psum[i][j - 1] - mn;
            mn = min(mn, psum[i][j]);
        }
        ll mx = -INF;
        for (int j = M; j >= 1; j--) {
            mx = max(mx, psum[i][j]);
            to_left[i][j] = mx - psum[i][j];
        }
    }

    ll ans = -INF;
    for (int j = 1; j <= M; j++) {
        for (int dir = 0; dir < 3; dir++) {
            ans = max(ans, dp(N, j, dir));
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