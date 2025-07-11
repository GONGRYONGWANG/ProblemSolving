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
#define INF ll(2e18)
const int inf = 1000000007;
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

int N, B;
ll DP[9][30001];
ll P[9], A[9], C[9];
ll dp(int x, int b) {
    if (x == N) return 1;
    if (DP[x][b] != 0) return DP[x][b];
    ll ret = 0;
    for (int i = 0; C[x] * i <= b && P[x] + A[x] * i < 100 + A[x]; i++) {
        ret = max(ret, min(100ll, P[x] + A[x] * i) * dp(x + 1, b - C[x] * i));
    }
    return DP[x][b] = ret;
}

void solve(int tc) {

    cin >> N >> B;

    for (int i = 0; i < N; i++) cin >> P[i] >> A[i] >> C[i];

    ll ret = dp(0, B);
    cout << ret << endl;


    int b = B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; C[i] * j <= b && P[i] + A[i] * j < 100 + A[i]; j++) {
            if (min(100ll, P[i] + A[i] * j) * dp(i + 1, b - C[i] * j) == ret) {
                ret /= min(100ll, P[i] + A[i] * j);
                b -= C[i] * j;
                cout << j << " ";   
                break;
            }
        }
    }



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