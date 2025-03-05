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

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

ll DP[401][401][401];
ll board[401][401];
ll rsum[401][401];
ll csum[401][401];

ll O[401];
ll U[401];
ll L[401];
ll R[401];

void solve(int tc) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        O[i] = U[i] = L[i] = R[i] = -INF;
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            rsum[i][j] = rsum[i][j - 1] + board[i][j];
            csum[i][j] = csum[i - 1][j] + board[i][j];
        }
    }

    for (ll k = 1; k <= N; k++) {
        for (int i = 1; i <= k; i++) {
            DP[1][1][k] += rsum[i][k];
        }
        DP[1][1][k] -= k * k * k * k;

        for (ll i = 1; i <= N; i++) {
            if (i + k - 1 > N) break;

            if (i != 1) DP[i][1][k] = DP[i - 1][1][k] - rsum[i - 1][k] + rsum[i + k - 1][k];

            for (ll j = 1; j <= N; j++) {
                if (j + k - 1 > N) break;
                if (j != 1) DP[i][j][k] = DP[i][j - 1][k] - (csum[i + k - 1][j - 1] - csum[i - 1][j - 1]) + (csum[i + k - 1][j + k - 1] - csum[i - 1][j + k - 1]);
                U[i] = max(U[i], DP[i][j][k]); O[i + k - 1] = max(O[i + k - 1], DP[i][j][k]);
                R[j] = max(R[j], DP[i][j][k]); L[j + k - 1] = max(L[j + k - 1], DP[i][j][k]);
            }
        }
    }

    ll ans = -INF;

    for (int i = 2; i <= N; i++) {
        O[i] = max(O[i], O[i - 1]);
        L[i] = max(L[i], L[i - 1]);
    }
    for (int i = N - 1; i >= 1; i--) {
        U[i] = max(U[i], U[i + 1]);
        R[i] = max(R[i], R[i + 1]);
    }

    for (int i = 1; i < N; i++) {
        ans = max(ans, O[i] + U[i + 1]);
        ans = max(ans, L[i] + R[i + 1]);
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