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



void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> dp(K + 1, vector<int>(1 << M, -inf));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            vector<vector<int>> nx(K + 1, vector<int>(1 << M, -inf));
            for (int k = 0; k <= K; k++) {
                for (int bit = 0; bit < (1 << M); bit++) {
                    nx[k][bit * 2 % (1 << M)] = max(dp[k][bit], nx[k][bit * 2 % (1 << M)]);
                    if (k == K) continue;
                    if (bit / (1 << (M - 1))) continue;
                    if (j != 0 && bit % 2) continue;
                    nx[k + 1][bit * 2 % (1 << M) + 1] = dp[k][bit] + x;
                }
            }
            dp = nx;
        }
    }

    int ans = -inf;
    for (int bit = 0; bit < (1 << M); bit++) ans = max(ans, dp[K][bit]);

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