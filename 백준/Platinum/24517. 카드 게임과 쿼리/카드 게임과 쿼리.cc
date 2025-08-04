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
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

bool DP[1 << 10][56];

void solve(int tc) {
    
    for (int bit = 1; bit < (1 << 10); bit++) {
        for (int i = 0; i < 10; i++) {
            if (!(bit & (1 << i))) continue;
            for (int j = 1; j <= i + 1; j++) {
                DP[bit][j] = true;
            }
            for (int j = i + 2; j <= 55; j++) {
                DP[bit][j] |= !DP[bit - (1 << i)][j - i - 1];
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int A, B, K;
        cin >> A >> B >> K;
        int N = B - A;
        int n = N / (K * (K + 1) / 2);
        N = N % (K * (K + 1) / 2);
        bool ret = DP[(1 << K) - 1][N];
        if (K % 2) ret ^= (n % 2);
        cout << (ret ? "swoon" : "raararaara") << endl;
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