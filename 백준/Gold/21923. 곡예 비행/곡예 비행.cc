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



int arr[1000][1000];
int A[1000][1000];
int B[1000][1000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            A[i][j] = B[i][j] = -inf;
        }
    }

    A[0][0] = arr[0][0];
    B[0][M - 1] = arr[0][M - 1];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i != 0) A[i][j] = max(A[i - 1][j] + arr[i][j], A[i][j]);
            if (j != 0) A[i][j] = max(A[i][j - 1] + arr[i][j], A[i][j]);
        }
        for (int j = M - 1; j >= 0; j--) {
            if (i != 0) B[i][j] = max(B[i - 1][j] + arr[i][j], B[i][j]);
            if (j != M - 1) B[i][j] = max(B[i][j + 1] + arr[i][j], B[i][j]);
        }
    }

    int ans = -inf;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = max(ans, A[i][j] + B[i][j]);
        }
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