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


ll DP[101][1001];

void solve(int tc) {

    ll N, M;
    cin >> N >> M;
    vector<pll> arr(M);
    for (int i = 0; i < M; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            DP[i][j] = INF;
        }
    }

    DP[0][0] = 0;

    for (auto [p, q] : arr) {
        for (ll i = M - 1; i >= 0; i--) {
            for (ll j = 0; j <= N; j++) {
                if (j + q > N) DP[i + 1][N] = min(DP[i + 1][N], DP[i][j] + (N - j) * p);
                else DP[i + 1][j + q] = min(DP[i + 1][j + q], DP[i][j] + p * q);
            }
        }
    }

    ll ans = INF;
    for (ll i = 1; i <= M; i++) {
        if (DP[i][N] == INF) continue;
        ans = min(ans, DP[i][N] * i);
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