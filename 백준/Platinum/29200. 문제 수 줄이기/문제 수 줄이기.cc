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

ll arr[200001];
ll DP[200002][4];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    DP[N + 1][0] = DP[N + 1][1] = DP[N + 1][2] = DP[N + 1][3] = 0;

    for (int i = N; i >= 1; i--) {
        DP[i][0] = DP[i][1] = DP[i][2] = DP[i][3] = -INF;
        if (i <= N) {
            DP[i][1] = max(DP[i][1], arr[i] + DP[i + 1][0]);
            DP[i][2] = max(DP[i][2], arr[i] + DP[i + 1][0]);
            DP[i][3] = max(DP[i][3], arr[i] + DP[i + 1][0]);
        }
        if (i + 1 <= N) {
            DP[i][0] = max(DP[i][0], (arr[i] ^ arr[i + 1]) + DP[i + 2][1]);
            DP[i][2] = max(DP[i][2], (arr[i] ^ arr[i + 1]) + DP[i + 2][1]);
            DP[i][3] = max(DP[i][3], (arr[i] ^ arr[i + 1]) + DP[i + 2][1]);
        }
        if (i + 2 <= N) {
            DP[i][0] = max(DP[i][0], (arr[i] ^ arr[i + 1] ^ arr[i + 2]) + DP[i + 3][2]);
            DP[i][1] = max(DP[i][1], (arr[i] ^ arr[i + 1] ^ arr[i + 2]) + DP[i + 3][2]);
            DP[i][3] = max(DP[i][3], (arr[i] ^ arr[i + 1] ^ arr[i + 2]) + DP[i + 3][2]);
        }
        if (i + 3 <= N) {
            DP[i][0] = max(DP[i][0], (arr[i] ^ arr[i + 1] ^ arr[i + 2] ^ arr[i + 3]) + DP[i + 4][3]);
            DP[i][1] = max(DP[i][1], (arr[i] ^ arr[i + 1] ^ arr[i + 2] ^ arr[i + 3]) + DP[i + 4][3]);
            DP[i][2] = max(DP[i][2], (arr[i] ^ arr[i + 1] ^ arr[i + 2] ^ arr[i + 3]) + DP[i + 4][3]);
        }
    }

    cout << max(DP[1][0], DP[1][1]);

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