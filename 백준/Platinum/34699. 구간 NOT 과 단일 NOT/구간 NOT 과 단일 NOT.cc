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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


ll DP[2][2];
ll nx[2][2];

void solve(int tc) {

    int N;
    cin >> N;

    string A, B;
    cin >> A >> B;
    ll c1, c2;
    cin >> c1 >> c2;

    DP[0][0] = 0;
    DP[1][0] = DP[0][1] = c1;
    DP[1][1] = c1 * 2;

    for (int idx = 0; idx < N; idx++) {

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                nx[i][j] = INF;
            }
        }

        bool x = (A[idx] == '0');
        bool y = (B[idx] == '0');

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int a = 0; a < 2; a++) {
                    for (int b = 0; b < 2; b++) {
                        if (i && !a) continue;
                        if (j && !b) continue;
                        if ((x ^ a) != (y ^ b)) continue;
                        nx[a][b] = min(nx[a][b], DP[i][j] +  2 * c1 * (!i && a) + 2  * c1 * (!j && b) + c2 * (x ^ a));
                    }
                }
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                DP[i][j] = nx[i][j];
            }
        }
        
        DP[0][1] = min(DP[0][1], DP[1][1]);
        DP[1][0] = min(DP[1][0], DP[1][1]);
        DP[0][0] = min(DP[0][0], min(DP[0][1], DP[1][0]));

    }

    cout << DP[0][0];



    

    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}