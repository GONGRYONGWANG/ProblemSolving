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

int N, K;
ll DP[100001][10][2][2];
ll mod = 1e9 + 7;
ll dp(int n, int a , bool b, bool c) {
    if (n < 0) return 0;
    if (n == 0) {
        if (a == 0 && c) return 1;
        else return 0;
    }

    if (DP[n][a][b][c] != -1) return DP[n][a][b][c];

    ll ret = dp(n - 1, a, false, true);
    if (K != 0) ret += dp(n - 1, (a + 1) % K, false, c);
    if (!b) ret += dp(n - 1, a, true, c);

    return DP[n][a][b][c] = ret % mod;
}

void solve(int tc) {
    
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= max(0, K - 1); j++) {
            DP[i][j][0][0] = DP[i][j][0][1] = DP[i][j][1][0] = DP[i][j][1][1] = -1;
        }
    }

    cout << dp(N, 0, false, false);


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