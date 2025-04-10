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
#define INF ll(4e18+7)
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

ll C[8001];
ll DP[801][8001];
void dnc(int g, int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;
    DP[g][m] = INF; 
    ll mnidx = max(m, l);
    for (int i = max(m, l); i <= r; i++) {
        ll val = (C[i] - C[m - 1]) * (i - m + 1) + DP[g + 1][i + 1];
        if (val < DP[g][m]) {
            DP[g][m] = val; mnidx = i;
        }
    }
    dnc(g, s, m - 1, l, mnidx); dnc(g, m + 1, e, mnidx, r);
}

void solve(int tc) {

    int L, G;
    cin >> L >> G;
    for (int i = 1; i <= L; i++) {
        cin >> C[i];
        C[i] += C[i - 1];
    }

    G = min(L, G);
    for (int i = 1; i <= L; i++) {
        DP[G][i] = (C[L] - C[i - 1]) * (L - i + 1);
    }
    for (int j = G - 1; j >= 1; j--) {
        dnc(j, 1, L, 1, L - (G - j));
    }

    cout << DP[1][1];

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