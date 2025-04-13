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


int N;
int s;
ll psum[101];
ll DP[101][101];
ll dp(int a, int b) {
    if (DP[a][b] != -1) return DP[a][b];
    int l = min(a, b); int r = max(a, b);
    if (l > s || r < s) return INF;
    ll n = N - (r - l);
    if (a == l) return DP[a][b] = min(dp(a + 1, b) + n * (psum[a + 1] - psum[a]), dp(b, a + 1) + n * (psum[b] - psum[a]));
    else return DP[a][b] = min(dp(a - 1, b) + n * (psum[a] - psum[a - 1]), dp(b, a - 1) + n * (psum[a] - psum[b]));
}

void solve(int tc) {

    cin >> N;
    cin >> s;
    for (int i = 2; i <= N; i++) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            DP[i][j] = -1;
        }
    }

    DP[s][s] = 0;
    cout << min(dp(1, N), dp(N, 1)) << endl;





}
    



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}