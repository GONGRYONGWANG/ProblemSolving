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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

ll mod = 1e9 + 7;
ll DP[3000][3001];

void solve(int tc) {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;

        if (i == 0) {
            for (int j = a; j <= b; j++) DP[i][j] = DP[i][j - 1] + 1;
            for (int j = b + 1; j <= 3000; j++) DP[i][j] = DP[i][j - 1];
            continue;
        }

        for (int j = a; j <= b; j++) {
            DP[i][j] = DP[i][j - 1] + (DP[i - 1][min(3000, j + K)] - DP[i - 1][max(1, j - K) - 1]);
            DP[i][j] %= mod;
        }
        for (int j = b + 1; j <= 3000; j++) DP[i][j] = DP[i][j - 1];
    }

    cout << (DP[N - 1][3000] + mod) % mod;




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