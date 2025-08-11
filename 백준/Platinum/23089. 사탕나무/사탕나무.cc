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


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int DP[100001][21];
vector<int> E[100001];
int parent[100001];

int dp(int x, int k) {
    if (DP[x][k] != -1) return DP[x][k];
    int ret = 1;
    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        ret += dp(nx, k - 1);
    }
    return DP[x][k] = ret;
}

void solve(int tc) {
    
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        DP[i][0] = 1;
        for (int j = 1; j <= K; j++) {
            DP[i][j] = -1;
        }
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (nx == parent[x]) continue;
            parent[nx] = x;
            q.push(nx);
        }
    }

    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= N; i++) {
            dp(i, k);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int ret = DP[i][K];
        
        int p = i; int prv = i;
        for (int k = K - 1; k >= 0; k--) {
            prv = p;
            p = parent[p];
            if (p == 0) break;
            ret += DP[p][k];
            if (k != 0) ret -= DP[prv][k - 1];
        }
        ans = max(ans, ret);
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