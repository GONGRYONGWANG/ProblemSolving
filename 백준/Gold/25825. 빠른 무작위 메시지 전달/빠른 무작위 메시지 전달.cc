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

int adj[12][12];
int DP[12][(1 << 12)];

int dp(int x, int bit) {
    if (DP[x][bit] != -1) return DP[x][bit];

    int sibling = x ^ 1;
    if (!(bit & (1 << sibling))) return DP[x][bit] = adj[x][sibling] + dp(sibling, bit | (1 << sibling));

    int ret = inf;
    for (int i = 0; i < 12; i++) {
        if (bit & (1 << i)) continue;
        ret = min(ret, adj[x][i] + dp(i, bit | (1 << i)));
    }

    return DP[x][bit] = ret;
}

void solve(int tc) {

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int bit = 0; bit < (1 << 12); bit++) {
            DP[i][bit] = -1;
        }
        DP[i][(1 << 12) - 1] = 0;
    }

    int ret = inf;
    for (int i = 0; i < 12; i++) ret = min(ret, dp(i, (1 << i)));

    cout << ret;


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