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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

pll arr[500];
vector<int> E[500];
ll DP[500][501];
ll SZ[500];
ll sz(int x) {
    if (SZ[x]) return SZ[x];
    ll ret = arr[x].second;
    for (int nx : E[x]) {
        ret = max(ret, arr[x].second + sz(nx));
    }
    return SZ[x] = ret;
}

ll dp(int x, int n) {
    if (DP[x][n] != -1) return DP[x][n];
    ll ret = arr[x].first * n;
    for (int nx : E[x]) {
        if (arr[x].second + sz(nx) < n) continue;
        ret = max(ret, max(n - sz(nx), 0ll) * arr[x].first + dp(nx, n - max(n - sz(nx), 0ll)));
    }
    return DP[x][n] = ret;
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr[i].first >> arr[i].second;
        for (int j = 0; j < i; j++) {
            if (arr[i].first % arr[j].first == 0) E[j].push_back(i);
            if (arr[j].first % arr[i].first == 0) E[i].push_back(j);
        }
        for (int n = 0; n <= N; n++) DP[i][n] = -1;
    }

    ll ans = -1;
    for (int i = 0; i < M; i++) {
        if (sz(i) < N) continue;
        ans = max(ans, dp(i, N));
    }
    cout << ans;


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}