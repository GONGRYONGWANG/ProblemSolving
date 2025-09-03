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
#include<chrono>
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
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int N, M, C;
int mn[51][51];
int mx[51][51];
int DP[51][1001];

void solve(int tc) {

    cin >> N >> M >> C;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            mn[i][j] = inf; mx[i][j] = -inf;
        }
        mn[i][i] = 0; mx[i][i] = 0;
    }

    while (M--) {
        int u, v, c;
        cin >> u >> v >> c;
        mn[u][v] = min(mn[u][v], c);
        mx[u][v] = max(mx[u][v], c);
    }

    for (int i = 1; i <= N; i++) {
        DP[i][0] = inf;
    }
    DP[N][0] = 0;
    vector<bool> visited(N + 1, false);
    while (1) {
        int idx = 0;
        for (int i = 1; i <= N; i++) {
            if (visited[i]) continue;
            if (idx == 0 || DP[i][0] < DP[idx][0]) idx = i;
        }
        if (idx == 0) break;
        visited[idx] = true;
        for (int i = 1; i <= N; i++) {
            DP[i][0] = min(DP[i][0], DP[idx][0] + mn[i][idx]);
        }
    }
    
    int ans = DP[1][0];
    for (int c = 1; c <= C; c++) {
        for (int i = 1; i <= N; i++) {
            DP[i][c] = inf;
            for (int j = 1; j <= N; j++) {
                DP[i][c] = min(DP[i][c], DP[j][c - 1] - mx[i][j]);
            }
            visited[i] = false;
        }

        while (1) {
            int idx = 0;
            for (int i = 1; i <= N; i++) {
                if (visited[i]) continue;
                if (idx == 0 || DP[i][c] < DP[idx][c]) idx = i;
            }
            if (idx == 0) break;
            visited[idx] = true;
            for (int i = 1; i <= N; i++) {
                DP[i][c] = min(DP[i][c], DP[idx][c] + mn[i][idx]);
            }
        }

        ans = min(ans, DP[1][c]);

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