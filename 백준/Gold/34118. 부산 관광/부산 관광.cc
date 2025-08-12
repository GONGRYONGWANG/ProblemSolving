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


bool A[2000], B[2000];
int N;

int pp;
pii P[4];

int DP[2000][5][5];
int dp(int x, int a, int b) {
    a = max(a, 0); b = max(b, 0);
    if (x >= N) return 0;
    if (DP[x][a][b] != -1) return DP[x][a][b];

    DP[x][a][b] = dp(x + 1, max(a - 1, 3), max(b - 1, 3)) + pp;
    
    for (int p = 0; p < 4; p++) {
        for (int q = 0; q < 4; q++) {
            if (A[x] && !a && !p ) continue;
            if (B[x] && !b && !q) continue;
            DP[x][a][b] = min(DP[x][a][b], dp(x + 1, max(P[p].first, a) - 1, max(P[q].first, b) - 1) + P[p].second + P[q].second);
        }
    }

    return DP[x][a][b];

}

void solve(int tc) {
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        char x; cin >> x;
        A[i] = (x == '1');
    }
    for (int i = 0; i < N; i++) {
        char x; cin >> x;
        B[i] = (x == '1');
    }

    P[0] = { 0,0 }; P[1].first = 1; P[2].first = 3; P[3].first = 5;
    cin >> P[1].second >> P[2].second >> P[3].second >> pp;

    for (int i = 0; i < N; i++) {
        for (int a = 0; a <= 4; a++) {
            for (int b = 0; b <= 4; b++) {
                DP[i][a][b] = -1;
            }
        }
    }

    cout << dp(0, 0, 0);


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