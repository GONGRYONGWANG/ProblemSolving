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
#define INF ll(9e18)
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
    
    int N;
    cin >> N;
    if (N == 1) {
        cout << 10;
        return;
    }

    ll mod = 1e9 + 7;
    vector<vector<ll>> dp(10, vector<ll>(4, 0)); // 0:u, 1:uu, 2:d, 3:dd
    for (int i = 0; i <= 9; i++) {
        dp[i][1] = dp[i][3] = 1;
    }

    for (int j = 0; j < N - 1; j++) {
        vector<vector<ll>> nx(10, vector<ll>(4, 0));
        for (int i = 0; i <= 9; i++) {
            if (i != 0) {
                nx[i][0] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
                nx[i][1] = dp[i - 1][0];
            }
            if (i != 9) {
                nx[i][2] = (dp[i + 1][0] + dp[i + 1][1]) % mod;
                nx[i][3] = dp[i + 1][2];
            }
        }
        dp = nx;
        
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3];
    }
    cout << ans % mod;


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