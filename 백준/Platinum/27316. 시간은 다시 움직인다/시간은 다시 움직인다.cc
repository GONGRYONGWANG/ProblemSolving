// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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

int psum[200001];
bool DP[200002][501];

void solve(int tc) {

    int N;
    cin >> N;

    while (N--) {
        int x;
        cin >> x;
        psum[x] += 1;
    }

    for (int i = 1; i <= 200000; i++) psum[i] += psum[i - 1];

    DP[200001][500] = true;
    for (int j = 499; j >= 1; j--) {
        DP[200001][j] = true;
        for (int i = 200000; i >= 0; i--) {
            if (i != 0 && psum[i] == psum[i - 1]) DP[i][j] |= DP[i + 1][j];
            if (i == 0 && psum[i] == 0) DP[i][j] |= DP[i + 1][j];
            if (psum[min(i + 2 * j - 1, 200000)] == psum[min(i + j - 1, 200000)]) DP[i][j] |= DP[min(i + 2 * j, 200001)][j + 1];
        }
    }


    cout << (DP[0][1] ? "YES" : "NO");

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