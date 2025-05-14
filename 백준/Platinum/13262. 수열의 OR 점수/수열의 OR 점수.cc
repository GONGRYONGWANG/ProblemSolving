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

ll arr[5001];
ll DP[5001][5001];

void dnc(int s, int e, int l, int r, int k) {
    if (e < s) return;
    int m = (s + e) / 2;

    if (max(l, m + 1) > r) {
        DP[m][k] = -INF;
        dnc(s, m - 1, l, r, k);
        dnc(m + 1, e, max(l, m + 1), r, k);
        return;
    }

    int idx = m + 1;
    ll ret = arr[m];
    ll mx = ret + DP[m + 1][k - 1];
    for (int i = m + 2; i <= r; i++) {
        ret |= arr[i - 1];
        if (ret + DP[i][k - 1] > mx) {
            mx = ret + DP[i][k - 1];
            idx = i;
        }
    }

    DP[m][k] = mx;
    dnc(s, m - 1, l, idx, k);
    dnc(m + 1, e, idx, r, k);
}

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    DP[N][1] = arr[N];
    for (int i = N - 1; i >= 1; i--) {
        DP[i][1] = arr[i] | DP[i + 1][1];
    }

    for (int k = 2; k <= K; k++) {
        dnc(1, N, 1, N, k);
    }

    cout << DP[1][K];



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